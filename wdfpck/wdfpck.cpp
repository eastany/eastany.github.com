#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <direct.h>
#include <algorithm>
#include <vector>

#define DWORD unsigned long

struct FILE_LST {
	DWORD uid;
	const char *name;
	int size;
	unsigned offset;
	unsigned space;
};

struct FileHeader {
	DWORD id;
	int number;
	unsigned offset;
public:
	FileHeader() : id('WDFP') {};
};

enum { c_MaxFile=0x10000 };

class FileList {
	
	std::vector<FILE_LST> m_List;
	char *m_NameBuffer;
	int m_FileNumber;
public:
	FileList();
	~FileList();

	int GetNumber() const { return m_FileNumber; }
	const char *GetName(int i) const { return m_List[i].name; }
	unsigned GetID(int i) const { return m_List[i].uid; }
	int ReadList(const char *name);
	int ReadListOnly(const char *name);
	void WriteList(FILE *f);
	bool WriteFile(FILE *f,int n,bool findspace=false);		// 将第 n 个文件写入 f
	void UpdateFile(FILE *f,int n,std::vector<FILE_LST>& list,int t);	// 更新第 n 个文件
	void ReadHeader(FILE *f,FileHeader *header);
	int FindFile(DWORD id) const;
	int IsFileExist(int n,std::vector<FILE_LST>& list,int t) const;
	bool NeedUpdate(FILE *f,int n,std::vector<FILE_LST>& list,int t);
	void ClearTail(unsigned long id);
};

FileList::FileList()
{
	m_NameBuffer=0;
	m_FileNumber=0;
}

FileList::~FileList()
{
	if (m_NameBuffer) {
		delete[] m_NameBuffer;
	}
}

void FileList::ReadHeader(FILE *f,FileHeader *header)
{
	fflush(f);
	fseek(f,0,SEEK_SET);
	fread(header,sizeof(*header),1,f);
	fflush(f);
}

int FileList::IsFileExist(int n,std::vector<FILE_LST>& list,int t) const
{
	assert((size_t)t==list.size());
	assert((size_t)n<m_List.size());
	DWORD id=m_List[n].uid;
	int i;
	for (i=0;i<t;i++) {
		if (id==list[i].uid) {
			return i;
		}
	}
	return -1;
}

int FileList::FindFile(DWORD id) const
{
	int i;
	for (i=0;i<m_FileNumber;i++) {
		if (id==m_List[i].uid) {
			return i;
		}
	}
	return -1;
}

int file_size(const char *name)
{
	FILE *f;
	f=fopen(name,"rb");
	if (f==0) return -1;
	fseek(f,0,SEEK_END);
	int len=ftell(f);
	fclose(f);
	return len;
}

bool file_exist(const char *name)
{
	FILE *f;
	f=fopen(name,"rb");
	if (f==0) return false;
	fclose(f);
	return true;
}

unsigned long string_id(const char *str)
{
	int i;
	unsigned int v;
	static unsigned m[70];
	strncpy((char *)m,str,256);
	for (i=0;i<256/4 && m[i];i++) ;
	m[i++]=0x9BE74448,m[i++]=0x66F42C48;
	v=0xF4FA8928;

	__asm {
		mov esi,0x37A8470E		;x0=0x37A8470E
		mov edi,0x7758B42B		;y0=0x7758B42B
		xor ecx,ecx
_loop:
		mov ebx,0x267B0B11		;w=0x267B0B11
		rol v,1
		lea eax,m
		xor ebx,v

		mov eax,[eax+ecx*4]
		mov edx,ebx
		xor esi,eax
		xor edi,eax

		add edx,edi
		or edx,0x2040801		;a=0x2040801
		and edx,0xBFEF7FDF		;c=0xBFEF7FDF

		mov eax,esi
		mul edx
		adc eax,edx
		mov edx,ebx
		adc eax,0

		add edx,esi
		or edx,0x804021			;b=0x804021
		and edx,0x7DFEFBFF		;d=0x7DFEFBFF

		mov esi,eax
		mov eax,edi
		mul edx

		add edx,edx
		adc eax,edx
		jnc _skip
		add eax,2
_skip:
		inc ecx;
		mov edi,eax
		cmp ecx,i
		jnz _loop
		xor esi,edi
		mov v,esi
	}

	return v;
}

static char *string_adjust(char *p)
{
	int i;
	for (i=0;p[i];i++) {
		if (p[i]>='A' && p[i]<='Z') p[i]+='a'-'A';
		else if (p[i]=='/') p[i]='\\';
	}
	return p;
}

int FileList::ReadListOnly(const char *name)
{
	FILE *f;
	int i;
	char *p;
	int size=file_size(name);
	bool in_line;
	if (size<0) return -1;
	m_NameBuffer=new char[size];
	f=fopen(name,"rb");
	fread(m_NameBuffer,1,size,f);
	fclose(f);

	m_FileNumber=0;	
	for (in_line=false,i=0;i<size;i++) {
		if (in_line) {
			if (m_NameBuffer[i]<=32 && m_NameBuffer[i]>=0) {
				m_NameBuffer[i]=0;

				FILE_LST fl;

				fl.size=0;
				fl.name=p;
				fl.uid=string_id(string_adjust(p));
				fl.space=0;
				fl.offset=0;

				m_List.push_back(fl);

				m_FileNumber++;
				in_line=false;
			}
		}
		else {
			if (m_NameBuffer[i]>32 || m_NameBuffer[i]<0) {
				p=&m_NameBuffer[i];
				in_line=true;
			}
		}
	}
	return m_FileNumber;
}

int FileList::ReadList(const char *name)
{
	FILE *f;
	int i;
	char *p;
	int size=file_size(name);
	bool in_line;
	if (size<0) return -1;
	m_NameBuffer=new char[size];
	f=fopen(name,"rb");
	fread(m_NameBuffer,1,size,f);
	fclose(f);

	m_FileNumber=0;	
	for (in_line=false,i=0;i<size;i++) {
		if (in_line) {
			if (m_NameBuffer[i]<=32 && m_NameBuffer[i]>=0) {
				m_NameBuffer[i]=0;

				FILE_LST fl;

				fl.size=file_size(p);
				fl.name=p;
				fl.uid=string_id(string_adjust(p));
				fl.space=0;
				fl.offset=0;

				if (fl.size>0) {
					m_List.push_back(fl);
					m_FileNumber++;
				}
				else {
					printf("%s can't open.\n",p);
				}
				in_line=false;
			}
		}
		else {
			if (m_NameBuffer[i]>32 || m_NameBuffer[i]<0) {
				p=&m_NameBuffer[i];
				in_line=true;
			}
		}
	}
	return m_FileNumber;
} 

struct lt{
	unsigned uid;
	int id;
	bool operator < (const lt& l1) const
	{
		return this->uid < l1.uid;
	}
};

void FileList::WriteList(FILE *f)
{
	std::vector<lt> sort_array(m_FileNumber);

	int i;
	for (i=0;i<m_FileNumber;i++) {
		sort_array[i].uid=m_List[i].uid;
		sort_array[i].id=i;
	}

	//for (i=0;i<m_FileNumber-1;i++)
	//	for (j=i+1;j<m_FileNumber;j++) {
	//		if (sort_array[i].uid>sort_array[j].uid) {
	//			temp=sort_array[i];
	//			sort_array[i]=sort_array[j];
	//			sort_array[j]=temp;
	//		}
	//	}
	std::sort(sort_array.begin(), sort_array.end());
	
	unsigned uid_temp = sort_array[0].uid;
	for(i=1; i<m_FileNumber; ++i)
	{
		if( sort_array[i].uid == uid_temp )
		{	
			printf("!!!!!!!!!!!! double use uid %s !!!!!!!!!!!!!\n", m_List[sort_array[i].id].name);
			printf("!!!!!!!!!!!! double use uid %s !!!!!!!!!!!!!\n", m_List[sort_array[i-1].id].name);
		}
		uid_temp = sort_array[i].uid;
	}

	for (i=0;i<m_FileNumber;i++) {
		fwrite(&m_List[sort_array[i].id].uid,4,1,f);
		fwrite(&m_List[sort_array[i].id].offset,4,1,f);
		fwrite(&m_List[sort_array[i].id].size,4,1,f);
		fwrite(&m_List[sort_array[i].id].space,4,1,f);
	}
}

bool FileList::WriteFile(FILE *f,int n,bool findspace)
{
	FILE *g;
	static char buffer[1024];
	size_t count;
	if (m_List[n].offset!=0) 
		return false;

	long pos=ftell(f);
	int space=-1,space_n;
	int i;

	g=fopen(m_List[n].name,"rb");
	if (g==0) 
		return false;

	if (findspace) {
		fseek(g,0,SEEK_END);
		size_t size=ftell(g);
		fseek(g,0,SEEK_SET);

		for (i=0;i<m_FileNumber;i++) {
			if (m_List[i].offset!=0) {
				if (m_List[i].space>=size) {
					if (space<0 || (space>=0 && (size_t)space>m_List[i].space)) {
						space_n=i;
						space=m_List[i].space;
					}
				}
			}
		}
		if (space>=0) {
			m_List[n].offset=m_List[space_n].offset+m_List[space_n].size;
			fseek(f,m_List[n].offset,SEEK_SET);
			m_List[n].space=space-size;
			m_List[space_n].space=0;
		}
	}

	if (space<0) {
		m_List[n].offset=pos;
	}
	do {
		count=fread(buffer,1,1024,g);
		fwrite(buffer,1,count,f);
	} while(count==1024);
	fclose(g);
	if (space>=0) {
		fseek(f,pos,SEEK_SET);
	}
	printf("[%s] ",m_List[n].name);
	return true;
}

// 注, 这个函数不检查长度是否相同
bool FileList::NeedUpdate(FILE *f,int n,std::vector<FILE_LST>& list,int t)
{
	assert((size_t)n < m_List.size() );
	assert((size_t)t < list.size() );

	static char buffer1[1024],buffer2[1024];
	FILE *g;
	fseek(f,list[t].offset,SEEK_SET);
	size_t count;
	g=fopen(m_List[n].name,"rb");
	if (g==0) {
		printf("[%s] can't open\n",m_List[n].name);
		return false;
	}
	do {
		count=fread(buffer1,1,1024,g);
		if (count==0) break;
		fread(buffer2,1,1024,f);
		if (memcmp(buffer1,buffer2,count)!=0) {
			fclose(g);
			return true;
		}
	} while(count==1024);
	fclose(g);
	m_List[n].offset=list[t].offset;
	m_List[n].space=list[t].space;
	list[t].uid=0;
	return false;
}

void FileList::UpdateFile(FILE *f,int n,std::vector<FILE_LST>& list,int t)
{
	assert((size_t)n < m_List.size() );
	assert((size_t)t < list.size());

	fseek(f,list[t].offset,SEEK_SET);
	WriteFile(f,n);
	printf("Updated\n");
	m_List[n].space=list[t].size+list[t].space-m_List[n].size;
	list[t].size=m_List[n].size;
	list[t].space=m_List[n].space;
}

void FileList::ClearTail(unsigned long id)
{
	int n=FindFile(id);
	assert(n>=0);
	m_List[n].space=0;
}

void delete_file(FILE *f,int total,std::vector<FILE_LST>& list,int n)
{
	assert(total == list.size() );
	assert(n < total );
	int i;
	for (i=0;i<total;i++) {
		if (list[i].uid!=0) {
			if (list[i].offset+list[i].size+list[i].space==list[n].offset) {
				list[i].space+=list[n].size+list[n].space;
				break;
			}
		}
	}
	fseek(f,list[n].offset,SEEK_SET);
	for (i=0;i<list[n].size;i++) {
		putc(0,f);
	}
	list[n].uid=0;
}

void write_header(FILE *f,FileHeader *header)
{
	fseek(f,0,SEEK_SET);
	fwrite(header,sizeof(*header),1,f);
}

void create_new(const char *dataname,const char *lstname)
{
	FILE *f;
	FileList list;
	FileHeader header;
	int n,i;
	n=list.ReadList(lstname);
	f=fopen(dataname,"wb");
	write_header(f,&header);
	header.number=n;
	for (i=0;i<n;i++) {
		list.WriteFile(f,i);
		printf("Added\n");
	}
	header.offset=ftell(f);
	list.WriteList(f);
	write_header(f,&header);
	fclose(f);
}

int read_lst(const char *name, std::vector<FILE_LST>& lst)
{
	FILE *f;
	FileHeader header;
	int i;

	f=fopen(name,"rb");
	if (f==0) {
		return -1;
	}

	fread(&header,sizeof(header),1,f);
	if (header.id!='WDFP') {
		return -1;
	}

	lst.resize(0);

	fseek(f,header.offset,SEEK_SET);
	for (i=0;i<header.number;i++) {
		FILE_LST fl;

		fread(&(fl.uid),4,1,f);
		fread(&(fl.offset),4,1,f);
		fread(&(fl.size),4,1,f);
		fread(&(fl.space),4,1,f);

		lst.push_back(fl);
	}
	fclose(f);
	return header.number;
}

void update_datafile(const char *dataname,const char *lstname)
{
	int old_number,new_number;
	std::vector<FILE_LST> old_list(c_MaxFile);
	old_number=read_lst(dataname,old_list);
	if (old_number<0) {
		printf("[%s] is Bad\n",dataname);
		return;
	}
	FILE *f;
	FileList list;
	FileHeader header;
	int i;
	new_number=list.ReadList(lstname);
	f=fopen(dataname,"rb+");
	if (f==0) {
		printf("[%s] can't update",dataname);
		return;
	}
	list.ReadHeader(f,&header);
	header.number=new_number;
	int s;
	for (s=i=0;i<old_number;i++) {
		if (list.FindFile(old_list[i].uid)==-1) {
			printf("A file[%x] (%d bytes) is deleted\n",old_list[i].uid,old_list[i].size);
			delete_file(f,old_number,old_list,i);
			++s;
		}
	}
	if (s>0) {
		printf("%d files deleted\n",s);
	}
	for (i=0;i<old_number;i++) {
		int n;
		if (old_list[i].uid==0) continue;
		n=list.FindFile(old_list[i].uid);
		assert(n>=0);
		int space=old_list[i].size+old_list[i].space;
		int size=file_size(list.GetName(n));
		if (size>space) {
			delete_file(f,old_number,old_list,i);
			printf("[%s] deleted\n",list.GetName(n));
		}
		else if (size==old_list[i].size) {
			if (list.NeedUpdate(f,n,old_list,i)) {
				list.UpdateFile(f,n,old_list,i);
			}
		}
		else if (size<=space) {
			list.UpdateFile(f,n,old_list,i);
		}
	}
// 寻找文件尾
	for (i=0;i<old_number;i++) {
		if (old_list[i].uid==0) 
			continue;
		if (old_list[i].offset+old_list[i].size+old_list[i].space==header.offset) 
			break;
	}
	if (i<old_number) {
		header.offset=old_list[i].offset+old_list[i].size;
		old_list[i].space=0;
		list.ClearTail(old_list[i].uid);
	}
	fseek(f,header.offset,SEEK_SET);
	for (i=0;i<new_number;i++) {
		if (list.WriteFile(f,i,true)) 
			printf("Added\n");	// 添加文件(见缝插针)
	}
	header.offset=ftell(f);
	list.WriteList(f);
	write_header(f,&header);
	fclose(f);
}

int main(int agv,char *agc[])
{
	char lstname[256],dataname[256];
	if (agv==1) {
		printf("Need Argument\n");
		return -1;
	}
	if (agc[1][0]=='x') {
		char filename[256];
		int i;
		strcpy(lstname,agc[2]);
		strcpy(dataname,agc[2]);
		strcat(lstname,".lst");
		strcat(dataname,".wdf");
		if (!file_exist(lstname)) {
			printf("Can't open list file[.lst]\n");
			return -1;
		}
		if (!file_exist(dataname)) {
			printf("Can't open data file[.wdf]\n");
			return -1;
		}
		_mkdir(agc[2]);
		FileList list;
		int n;
		n=list.ReadListOnly(lstname);
		std::vector<FILE_LST> old_list;
		int old_number=read_lst(dataname,old_list);
		FILE *df;
		df=fopen(dataname,"rb");
		for (i=0;i<n;i++) {
			FILE *f;
			int j;
			static char buffer[1024];
			strcpy(filename,agc[2]);
			strcat(filename,"\\");
			int n;
			n=list.IsFileExist(i,old_list,old_number);
			printf("%s [%x] ",list.GetName(i),list.GetID(i));
			if (n<0) {
				printf(" Can't find\n");
				continue;
			}
			strcat(filename,list.GetName(i));
			char *path=strchr(filename,'\\');
			path=strchr(path+1,'\\');
			if (path) {
				path[0]=0;
				_mkdir(filename);
				path[0]='\\';
			}
			f=fopen(filename,"wb");
			fseek(df,old_list[n].offset,SEEK_SET);

			for (j=0;j<old_list[n].size-1024;j+=1024) {
				fread(buffer,1,1024,df);
				fwrite(buffer,1,1024,f);
			}
			j=old_list[n].size-j;
			fread(buffer,1,j,df);
			fwrite(buffer,1,j,f);
			fclose(f);
			printf(" Extracted\n");
		}
		fclose(df);

		return 0;

	}
	strcpy(lstname,agc[1]);
	strcpy(dataname,agc[1]);
	strcat(lstname,".lst");
	strcat(dataname,".wdf");
	if (!file_exist(lstname)) {
		printf("Can't open list file[.lst]\n");
		return -1;
	}
	if (file_exist(dataname)) {
		printf("Updating Data File...\n");
		update_datafile(dataname,lstname);
	}
	else {
		printf("Creating New Data File...\n");
		create_new(dataname,lstname);
	}
	return 0;
}
