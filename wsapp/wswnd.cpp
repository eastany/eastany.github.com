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

		Description:		窗口类
 		Original Author:	云风
		Authors:
		Create Time:		2000/12/13
		Modify Time:		2001/8/23

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#include <windows.h>
#include <assert.h>
#include "windsoul.h"
#include "wsapp.h"
#include "wsmap.h"

static HINSTANCE hInst=0;

static WMapPtr mapWndDC;

LRESULT CALLBACK WWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WWindow *wnd=(WWindow*)GetWindowLong(hWnd,GWL_USERDATA);
	if (wnd) {
		const WMessageFunc *mf=wnd->GetMessageEntries();
		do {
			int i;
			for (i=1;mf[i].func;i++) {
				if (mf[i].id==message) {
					if ((wnd->*(mf[i].func))(wParam,lParam)==-1)
						return 0;
					else break;
				}
			}
			mf=(const WMessageFunc*)(mf[0].id);
		} while (mf!=0);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

const WMessageFunc WWindow::messageEntries[]={
	{0,0},
	{0,0}
};

const char * WWindow::GetText()
{
	static char buf[256];
	::GetWindowText(hWnd,buf,256);
	return buf;
}

void WWindow::SetText(const char *text)
{
	::SetWindowText(hWnd,text);
}

WWindow::~WWindow()
{
	HWND p=GetParent(hWnd);
	if (!hWnd) return;
	for (int i=0;i<num;i++)
		delete childwnd[i];
	if (maxchildwnd>0) delete[] childwnd;
	num=maxchildwnd=0;
	mapWndDC.Delete(hWnd);
	DestroyWindow(hWnd);
	if (p) {
		WWindow *parent=(WWindow*)GetWindowLong(p,GWL_USERDATA);
		ASSERT(parent!=0);
		int i;
		for (i=0;i<parent->num;i++) {
			if (parent->childwnd[i]==this) break;
		}
		ASSERT(i<parent->num);
		--parent->num;
		for (;i<parent->num;i++) {
			parent->childwnd[i]=parent->childwnd[i+1];
		}
	}
	hWnd=0;
}

int WWindow::Show(int show) const
{
	return (::ShowWindow(hWnd,show));
}

int WWindow::Update() const
{
	return (::UpdateWindow(hWnd));
}

void WWindow::Init(HINSTANCE hInstance)
{
	WNDCLASS	wc;
	if (hInst!=0) return;	// 已经初始化过
	hInst=hInstance;
	wc.style=          CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc=    WWindow::WndProc;
	wc.cbClsExtra=     0;
	wc.cbWndExtra=     0;
	wc.hInstance=      hInst;
	wc.hIcon=          LoadIcon(hInstance,"WS_ICON");
	wc.hCursor=        NULL;
	wc.hbrBackground=  (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName=   NULL;
	wc.lpszClassName=  "WSWINDOW";
    RegisterClass(&wc);
}

bool WWindow::Create(const char *name,DWORD style,int w,int h,int x, int y,HWND parent)
{
	ASSERT(hWnd==0);
	hWnd=::CreateWindow("WSWINDOW",name,style,x,y,w,h,parent,0,hInst,0);
	if (hWnd==0) return false;
	::SetWindowLong(hWnd,GWL_USERDATA,(DWORD)this);
	return true;
}

bool WWindow::CreateEx(DWORD exstyle,const char *name,DWORD style,int w,int h,int x, int y,HWND parent)
{
	ASSERT(hWnd==0);
	hWnd=::CreateWindowEx(exstyle,"WSWINDOW",name,style,x,y,w,h,parent,0,hInst,0);
	if (hWnd==0) return false;
	::SetWindowLong(hWnd,GWL_USERDATA,(DWORD)this);
	return true;
}

WWindow *WWindow::CreateChild(const char *classname,const char *name,DWORD style,int x,int y,int w,int h,DWORD id)
{
	HWND wnd;
	WWindow *child;
	wnd=::CreateWindow(classname,name,style|WS_VISIBLE|WS_CHILD,x,y,w,h,hWnd,(HMENU)id,hInst,0);
	if (wnd==0) return 0;
	child=new WWindow;
	::SetWindowLong(wnd,GWL_USERDATA,(DWORD)child);
	child->hWnd=wnd;
	if (num==maxchildwnd) {
		int i;
		WWindow **n;
		maxchildwnd+=blocksize;
		n=new WWindow*[maxchildwnd];
		for (i=0;i<num;i++)
			n[i]=childwnd[i];
		childwnd=n;
	}
	childwnd[num]=child;
	++num;
	return child;
}

HDC WWindow::GetDC() const
{
	HDC LastDC=(HDC)mapWndDC.LookUp((void*)hWnd);
	if (LastDC==0) {
		LastDC=::GetDC(hWnd);
		mapWndDC.Insert((void*)hWnd,(void *)LastDC);
	}
	return LastDC;
}

void WWindow::ReleaseDC(HDC hDC) const
{
	mapWndDC.Delete((void*)hWnd);
	::ReleaseDC(hWnd,hDC);
}


