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

		Description:		风魂应用程序
 		Original Author:	云风
		Authors:
		Create Time:		2000/12/13
		Modify Time:		2001/3/25

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#include <windows.h>
#include "windsoul.h"
#include "wsapp.h"

BEGIN_MAP_MESSAGE(WApplication,WWindow)
MAP_MESSAGE(WM_DESTROY,WApplication::OnDestroy)
END_MAP_MESSAGE()

WApplication::WApplication(HINSTANCE hInst)
{
	WWindow::Init(hInst);
}

bool WApplication::CreateMainWindow()
{
	return Create("WindSoul");
}

int WApplication::OnDestroy(DWORD ignore1,DWORD ignore2)
{
	Quit();
	return 0;
}

void WApplication::Excute()
{
	MSG msg;
	AfterCreate();
	Show();
	Update();
	for (;;)
    {
        if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
        {
            if(!GetMessage(&msg,NULL,0,0))
				break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
			Idle();
    }
}

void WApplication::Quit()
{
	BeforeExit();
//	SendMessage(hWnd,WM_CLOSE,0,0);
	PostQuitMessage(0);
}


