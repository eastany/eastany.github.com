#include "myapp.h"
#include "wstimer.h"
#define new debug_new

BEGIN_MAP_MESSAGE(MyApp,WApplication)
MAP_MESSAGE(WM_PAINT,MyApp::OnPaint)
MAP_MESSAGE(WM_LBUTTONDOWN,MyApp::OnClick)
//MAP_MESSAGE(WM_MOUSEMOVE,MyApp::OnMouseMove)
MAP_MESSAGE(WM_KEYDOWN,MyApp::OnKeyDown)
MAP_MESSAGE(WM_ACTIVATEAPP,MyApp::OnActivateApp)
END_MAP_MESSAGE()

int MyApp::OnClick(DWORD w,DWORD l)
{
	if ((obj_num-=20)<0) obj_num=100;
	return 0;
}

int MyApp::OnKeyDown(DWORD w,DWORD l)
{
	switch (w) {
	case VK_HOME:
		dis=1;
		iswalk=1;
		break;
	case VK_END:
		dis=0;
		iswalk=1;
		break;
	case VK_PRIOR:
		dis=2;
		iswalk=1;
		break;
	case VK_NEXT:
		dis=3;
		iswalk=1;
		break;
	case VK_SPACE:
		iswalk=0;
		break;
	case VK_F2:
		pcanvas->Clear();
		pcanvas->Move(300,300); x+=300,y+=300;
		break;
	case VK_ESCAPE:
		Quit();
		break;
#ifdef DIRECTDRAW
	case VK_F1:
		if (pcanvas->GetW()==1024) {
			surface.Release();
			delete pcanvas;
			pcanvas=new WCanvas(640,480);
			surface.Create(hWnd,*pcanvas);
			surface.SetDisplay(640,480);
			x=y=hero_p=0;

		}
		else if (pcanvas->GetW()==640) {
			surface.Release();
			delete pcanvas;
			pcanvas=new WCanvas(1024,768);
			surface.Create(hWnd,*pcanvas);
			surface.SetDisplay(1024,768);
			x=y=hero_p=0;
		}
		break;
#endif
	}
	return 0;
}

int MyApp::OnActivateApp(DWORD w,DWORD l)
{
	return 0;
}

int MyApp::OnPaint(DWORD w,DWORD l)
{
#ifndef DIRECTDRAW
	pcanvas->Update2DC(GetDC(),0,0);
#endif
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                   char *lpCmdLine,int nCmdShow)
{
	MyApp app(hInstance);
	app.CreateMainWindow();
	//app.CreateChild("BUTTON","ok",BS_PUSHBUTTON,100,100,80,40,1000);
	app.Excute();

	return 0;
}