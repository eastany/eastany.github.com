#ifndef _MYAPP_H
#define _MYAPP_H

#define DIRECTDRAW

#include <windows.h>
#include "windsoul.h"
#include "wsfile.h"
#include "wsapp.h"
#include "wscanvas.h"
#include "wsurface.h"

class MyApp : public WApplication {
	int map[256][256];
	int dis;
	int iswalk;
	int obj_num;
	int x,y,hero_p;

//	Rain ss;

	WCanvas *pcanvas;
	WCanvas *subcanvas;
	WSurface surface;
	WBitmap tile[2];
//	LOZEBITMAP tile[2];
	WBitmap hero_stand;
	WBitmap hero_walk;
	WBitmap stand[4][8];
	WBitmap walk[4][14];
	WBitmap sm;
	WTimer m_Timer;
public:
//	MyApp(HINSTANCE hInst) : WApplication(hInst), canvas(*(new WCanvas(1152,864))) {
/*
	MyApp(HINSTANCE hInst) : WApplication(hInst), pcanvas(new WCanvas(1024,768)) {
		surface.Init(hWnd);
		dis=3,iswalk=0,obj_num=100;
		x=y=0,hero_p=0;
		surface.SetDisplay(1024,768);
		surface.Create(*pcanvas);		
	}
*/
	MyApp(HINSTANCE hInst) : WApplication(hInst), pcanvas(new WCanvas(640,480)) {
		dis=3,iswalk=0,obj_num=100;
		x=y=0,hero_p=0;
		subcanvas=new WCanvas(320,240);
//		ss.Bind(pcanvas);
	} 
	~MyApp() { delete pcanvas; 
		delete subcanvas;
	}
	void Idle();
	void AfterCreate();
	void BeforeExit() {}
	int OnPaint(DWORD,DWORD);
	int OnClick(DWORD,DWORD);
	void draw_canvas(int xx,int yy);
	void draw_map(int xx,int yy);
	int OnKeyDown(DWORD,DWORD);
	int OnActivateApp(DWORD,DWORD);
//	int OnClick(DWORD,DWORD);
//	int OnMouseMove(DWORD,DWORD);
	MAP_MESSAGE_FUNC()
};

#endif