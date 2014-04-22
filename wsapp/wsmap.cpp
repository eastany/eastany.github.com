/*
 "               ..;;;;,                     ;;;,    
 '           ..;;;"` ;;:           ,;;;;;: ,;;;:.,;..          _/
 `     ,;..,;;"`    :;;'            :;;"`,;;;;;;"":;;         _/ 
       ;;;"  `:;;. ;;'           ..;;:  .;;,.;;:',;;"    _/_/_/_/_/
      .;;`   ,;;" .;"          ,;;;;;;" :;`',;",;;"         _/
     ,;;,:.,;;;  ,;:          :" ,;:` , `:.;;;;;'`         _/   
     ;;"'':;;:. .;; .          ,;;;,;:;;,;;;, ,;             _/
    :;;..;;;;;; :;' :.        :;;;"` `:;;;;;,;,.;.          _/
  .;;":;;`  '"";;:  ';;       '""   .;;`.;";:;;;;` ;,  _/_/_/_/_/
 ;;;" `'       "::. ,;;:          .;"`  ::. '   .,;;;     _/ 
 ""             ';;;;;;;"        ""     ';;;;;;;;;;`     _/
 
                        Windsoul++

                by 云风 (Cloud Wu)  1999-2001
 
		http://member.netease.com/~cloudwu 
		mailto:cloudwu@263.net
 
		请阅读 readme.txt 中的版权信息
		See readme.txt for copyright information.

		Description:		指针映射
 		Original Author:	云风
		Authors:
		Create Time:		2000/12/12
		Modify Time:

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#include "windsoul.h"
#include "wsmap.h"

void * WMapPtr::LookUp(void *p) const
{
	int begin=0,end=num-1,middle;
	unsigned t=(unsigned)p;
	while(begin<=end) {
		middle=(begin+end)/2;
		unsigned temp=(unsigned)ptr[middle*2];
		if (temp==t) return ptr[middle*2+1];
		else if (temp>t) end=middle-1;
		else begin=middle+1;
	}
	return 0;
}

void WMapPtr::Insert(void *key,void *var)
{
	int begin=0,end=num-1,middle;
	unsigned t=(unsigned)key;
	while(begin<=end) {
		middle=(begin+end)/2;
		unsigned temp=(unsigned)ptr[middle*2];
		if (temp==t) {
			ptr[middle*2+1]=var;
			return;
		}
		else if (temp>t) end=middle-1;
		else begin=middle+1;
	}
// 在 begin 处插入
	if (num>=size) {
		size+=blocksize;
		++num;
		void **newptr=new void*[size*2];
		int i;
		for (i=0;i<begin*2;i++)
			newptr[i]=ptr[i];
		newptr[begin*2]=key;
		newptr[begin*2+1]=var;
		for (i=begin*2;i<num*2;i++)
			newptr[i+2]=ptr[i];
		ptr=newptr;
	}
	else {
		++num;
		for (int i=num*2-1;i>begin*2+1;i--)
			ptr[i]=ptr[i-2];
		ptr[begin*2]=key;
		ptr[begin*2+1]=var;
	}
	return;
}

void WMapPtr::Delete(void *key)
{
	int begin=0,end=num-1,middle;
	unsigned t=(unsigned)key;
	while(begin<=end) {
		middle=(begin+end)/2;
		unsigned temp=(unsigned)ptr[middle*2];
		if (temp==t) {
			--num;
			for (int i=middle*2;i<num*2;i++)
				ptr[i]=ptr[i+2];
			return;
		}
		else if (temp>t) end=middle-1;
		else begin=middle+1;
	}
}
