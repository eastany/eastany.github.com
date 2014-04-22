#include <windows.h>
#include <stdlib.h>
#include "myapp.h"
#include "wstimer.h"
#include "wsstring.h"
#include "wsalpha.h"
#include "wsfont.h"
#include "wsgeo.h"
#define new debug_new

#define MAX_OBJ 100

struct {
	int lx;
	int ly;
	float x;
	float y;
	float dx;
	float dy;
	int times;
	int alpha;
} trans[MAX_OBJ];

WORD tile1[64*64];
WORD tile2[64*64];

WAlphaBitmap alpha,alpha2;

WFont font;

void MyApp::draw_canvas(int xx,int yy)
{
	static kk=0;
	subcanvas->MoveTo(-kk,-kk);
	subcanvas->SetPos(0,0);
	subcanvas->Draw("SubCanvas Test",0xffffff);
	subcanvas->UnChange();
	subcanvas->Clear(0);
	subcanvas->SetUserData(192);
	pcanvas->SetPos(xx,yy);
	pcanvas->Draw(*subcanvas,BLIT_TRANS);
	if (++kk>240) kk=0;
}

void MyApp::AfterCreate()
{
	HFONT winfont;
#ifdef DIRECTDRAW
	surface.Create(hWnd,*pcanvas);		
#endif

	pcanvas->Reset(30);


	WBitmap a1(100,0);
	WBitmap a2(100,100);
	a1.Draw(a2,0);
	a1.Draw(a2,BLIT_BACK);

	winfont=CreateFont(
		300,0,
		0, 0, 
		FW_NORMAL, 
		FALSE, FALSE, FALSE, 
		DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
		DEFAULT_QUALITY, 
//		DEFAULT_PITCH | FF_DONTCARE, 
		"仿宋");


/*
	winfont = CreateFont(
		16, 8, 0, 0,  
		600, 
		FALSE, FALSE, FALSE, 
		GB2312_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		FIXED_PITCH, 
		"宋体" );
*/
	font.Create(winfont,16,4);

	WFile f;
	int i,j;
//	memset(tile1,0,64*64*2);
//	memset(tile2,0xff,64*64*2);
	WFile::OpenDataFile("data.wdf");

	f.Load("data/10001.tga");
	alpha.LoadTGA(f);
	alpha2.LoadTGA(f);
	alpha2.SetPos(-10,5);
	alpha.Combine(alpha2);
	f.Load("data/tile1.bmp");
	tile[0].Load(f);
	f.Load("data/tile2.bmp");
	tile[1].Load(f);
//	tile[0].SetPicData((const char*)tile1);
//	tile[1].SetPicData((const char*)tile2);
	for (i=0;i<256;i++)
		for (j=0;j<256;j++)
			map[i][j]=rand()&1;
	f.Load("data/stand.bmp");
	hero_stand.Load(f);
	for (i=0;i<4;i++)
		for (j=0;j<8;j++)
			stand[i][j].Create(hero_stand,j*48,i*80,48,80);
	f.Load("data/walk.bmp");
	hero_walk.Load(f);
	for (i=0;i<4;i++)
		for (j=0;j<14;j++)
			walk[i][j].Create(hero_walk,j*48,i*80,48,80);
//	f.Load("obj.jpg");
	f.Load("data/sm.bmp");
	sm.Load(f);
//	sm.Clear(0xff0000);

	for (i=0;i<MAX_OBJ;i++) {
		trans[i].lx=trans[i].ly=400;
		trans[i].x=trans[i].y=400.0;
		trans[i].dx=float(rand()%60-30)/10.0;
		trans[i].dy=float(rand()%60-30)/10.0;
		trans[i].times=0;
		trans[i].alpha=rand()%128+128;
	}

//	if (surface.Create(*pcanvas)!=WS_OK) {
//		Quit();
//	}
//	pcanvas->Reset(40);


}

void MyApp::draw_map(int xx,int yy)
{
	WCanvas &canvas=*pcanvas;
/*
	WLine hline(600,0,0xffffff);
	WLine vline(0,600,0xffffff);
	canvas(4*64,9*32).Draw(hline,0);
	canvas(4*64,9*32).Draw(vline,0);
	canvas(9*64,18*32).Draw(hline,0);
	canvas(9*64,18*32).Draw(vline,0);
*/
	int i,j,sx,x,y;
	int start_x,start_y,end_x,end_y,block_x,block_y;
	end_x=xx+canvas.GetW(),end_y=yy+canvas.GetH();
	block_x=DIV(xx,64);
	block_y=DIV(yy,32)*2;
	start_x=block_x*64;
	start_y=block_y*16;
	
	canvas(0,0).Draw(alpha(128),BLIT_TRANS);
//	canvas.Clear(0xffffff);
	WChar c(font,_C('风'),0xff);
	canvas(0,30).Draw(c,FONT_ALPHA);
	canvas(c.GetWidth(),30).Draw(WChar(font,'X',0xff),FONT_NOALPHA);

//	font.Draw(canvas(10,110)," Test  测试",0xff0000,FONT_ALPHA);

	for (sx=32,y=-16+start_y,i=block_y;y<end_y;y+=16,sx=32-sx,i++) {
		for (x=start_x-sx,j=block_x;x<end_x;x+=64,j++) {
			int id=map[MOD(j,256)][MOD(i,256)];
			canvas(x,y).Draw(tile[id],BLIT_MASK);
		}
	}
//	canvas.Clear(0);

}

struct {
	int x;
	int y;
} offset[4]={{-2,1},{-2,-1},{2,-1},{2,1}};

#include "wsgeo.h"

WBitmap temp(100,100);

void MyApp::Idle()
{
	WCanvas &canvas=*pcanvas;
	static DWORD thistime,lasttime,timecount=0,fpscount=0;
	int sx,sy;

	int i,j;
	WString fps;
	if (pcanvas==0) return;
	static xx=0;

//	canvas.Change();
//	canvas(200,200).Draw(temp(192),BLIT_TRANS);
//	canvas.UnChange();
//	canvas(0,0).Draw(temp,BLIT_BACK);
//	canvas(99,99).Change();
/*
	canvas.DrawEx(WLine(100,50,0xff0000),0);
	canvas.DrawEx(WLine(100,-50,0xff),0);
	canvas.DrawEx(WLine(-100,50,0x80000),0);
	canvas.DrawEx(WLine(-100,-50,0x80),0);
	canvas.DrawEx(WLine(100,0,0),0);
	canvas.DrawEx(WLine(-100,0,0),0);
	canvas.DrawEx(WLine(0,50,0),0);
	canvas.DrawEx(WLine(0,-50,0),0);
*/
//	canvas.DrawEx(WLine(-50,-100,0xff0000),0);
//	canvas(0,0).Change();
//	canvas.DrawEx(WLine(0,100,0),0);
//	canvas.DrawEx(WLine(100,0,0),0);
//	canvas.DrawEx(WLine(400,++xx,0)(32),BLIT_TRANS);

	if (iswalk) {
		static tt=0;
		if (++tt==2)
			tt=2;
		canvas.Move(offset[dis].x,offset[dis].y);
//		ss.Move(offset[dis].x,offset[dis].y);
		x+=offset[dis].x,y+=offset[dis].y;
		canvas.Change();
		if (hero_p>=14) hero_p=0;
		canvas(x+canvas.GetW()/2-30,y+canvas.GetH()/2-80).Draw(walk[dis][hero_p],BLIT_MASK);
		++hero_p;
	}
	else {
		if (hero_p&1) canvas.Change();
		else canvas.UnChange();
		if (++hero_p>=16) hero_p=0;
		canvas(x+canvas.GetW()/2-30,y+canvas.GetH()/2-80).Draw(stand[dis][hero_p/2],BLIT_MASK);
		++hero_p;
	}

	if (timecount==0)
		thistime=m_Timer.GetTime();
	if (++timecount>=30) {
		timecount=0;
		fpscount=300000/(thistime-lasttime);
		lasttime=thistime;
	}

	draw_canvas(0,0);

//	ss.Update();

	for (i=0;i<obj_num;i++) {
		int x,y;
		x=(int)(trans[i].x+=trans[i].dx);
		y=(int)(trans[i].y+=trans[i].dy);
		if (++trans[i].times>300) {
			trans[i].times=0;
			trans[i].dx=-trans[i].dx;
			trans[i].dy=-trans[i].dy;
			trans[i].alpha=rand()%128+128;
		}
		if (x==trans[i].lx && y==trans[i].ly) {
			canvas.UnChange();
			canvas(x,y).Draw(sm(trans[i].alpha),BLIT_TRANS);
//			canvas(x,y).Draw(sm,0);
		}
		else {
			canvas.Change();
			canvas(x,y).Draw(sm(trans[i].alpha),BLIT_TRANS);
			if ((trans[i].alpha-=rand()%3)<8) trans[i].alpha=8;
//			canvas(x,y).Draw(sm,0);
			trans[i].lx=x,trans[i].ly=y;
		}
	}

	font.Lock();	// Lock font 的数据区(自动 Unlock 上次)


	canvas.Change();
	canvas.ViewPort(0,0);
	canvas.Draw(fps.Format("%dx%dx16bit FPS:%d FlayingObj:%d",canvas.GetW(),canvas.GetH(),fpscount,obj_num),0xffffff);
	canvas.ViewPort(0,13);
	canvas.Draw("Home End PgUp PgDn:Walk,Space:Stop,Mouse->FlyingObj",0xff);
	canvas.ViewPort(0,26);
	if (canvas.GetW()==1024) canvas.Draw("F1->Change to 640x480",0xff);
	else canvas.Draw("F1->Change to 1024x768",0xff);
//	canvas.Draw(sm,0);

	canvas.UnChange();
	draw_map(x,y);

#ifdef DIRECTDRAW
	surface.Blit2Screen();
#else
	canvas.Blit2DC(GetDC(),0,0);
#endif
	font.Unlock();	// 可以省略
}
