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

		Description:		风魂 API ( C 版本)
 		Original Author:	云风
		Authors:
		Create Time:		2001/1/4
		Modify Time:

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#ifdef _API

#include <windows.h>
#include "wsapi.h"
#include "windsoul.h"
#include "wscanvas.h"
#include "wsstring.h"

ws_handle WSAPI create_bitmap(int w,int h)
{
	return (ws_handle)new WBitmap(w,h);
}

ws_handle WSAPI create_sub_bitmap(ws_handle handle,int x,int y,int w,int h)
{
	return (ws_handle)new WBitmap(*(WBitmap *)handle,x,y,w,h);
}

ws_handle WSAPI load_bitmap(const char *name)
{
	WBitmap *bmp=new WBitmap;
	WFile f;
	f.Load(name);
	bmp->Load(f);
	return (ws_handle)bmp;
}

void WSAPI destroy_bitmap(ws_handle handle)
{
	delete (WBitmap *)handle;
}

void WSAPI destroy_canvas(ws_handle handle)
{
	delete (WCanvas *)handle;
}

int WSAPI bitmap_command(ws_handle handle,int command,int param1,int param2)
{
	WBitmap &bmp=*(WBitmap *)handle;
	switch (command) {
	case C_SETPOS:
		bmp.SetPos(param1,param2);
		break;
	case C_CLEAR:
		bmp.Clear((DWORD)param1);
		break;
	case C_BLIT:
		if (param2&BLIT_TRANS) {
			int alpha=param2>>16;
			WBitmap &bmp2=*(WBitmap *)param1;
			bmp.Draw(bmp2(alpha),param2&0xffff);
		}
		else bmp.Draw(*(const WBitmap *)param1,param2);
		break;
	case C_DRAWTEXT:
		bmp.Draw((const char *)*(WString*)param1,(DWORD)param2);
		break;
	case C_ISVALID:
		return 1;
	case C_GETPIXEL:
		return (DWORD)bmp[bmp.GetY()][bmp.GetX()];
	case C_PUTPIXEL:
		bmp[bmp.GetY()][bmp.GetX()]=(DWORD)param1;
		break;
	}
	return 0;
}

ws_handle WSAPI create_canvas(int w,int h)
{
	return (ws_handle)new WCanvas(w,h);
}

int WSAPI canvas_command(ws_handle handle,int command,int param1,int param2)
{
	WCanvas &canvas=*(WCanvas *)handle;
	switch (command) {
	case C_SETPOS:
		canvas.SetPos(param1,param2);
		break;
	case C_CLEAR:
		canvas.Clear((DWORD)param1);
		break;
	case C_SETSCREENPOS:
		canvas.ViewPort(param1,param2);
		break;
	case C_BLIT:
		if (param2&BLIT_TRANS) {
			int alpha=param2>>16;
			WBitmap &bmp=*(WBitmap *)param1;
			canvas.Draw(bmp(alpha),param2&0xffff);
		}
		else canvas.Draw(*(const WBitmap *)param1,param2);
		break;
	case C_DRAWTEXT:
		canvas.Draw((const char *)*(WString*)param1,(DWORD)param2);
		break;
	case C_ISVALID:
		return 1;
	case C_BLITCANVAS:
		canvas.Draw(*(WCanvas *)param1);
		break;
	case C_CHANGE:
		switch (param1) {
		case CANVAS_NOCHANGE:
			canvas.UnChange();
			break;
		case CANVAS_CHANGE:
			canvas.Change();
			break;
		case CANVAS_SELFCHANGE:
			canvas.SelfChange();
			break;
		}
		break;
	case C_MOVE:
		canvas.Move(param1,param2);
		break;
	case C_MOVETO:
		canvas.MoveTo(param1,param2);
		break;
	}
	return 0;
}

int WSAPI canvas_command_stream(ws_handle handle,int command_num,int *stream)
{
	int i;
	for (i=0;i<command_num;i++) {
		if (canvas_command(handle,stream[i*3],stream[i*3+1],stream[i*3+2])==-1)
			return -1;
	}
	return 0;
}

void WSAPI refresh_canvas(ws_handle handle,void *hdc)
{
	WCanvas *canvas=(WCanvas *)handle;
	canvas->SetPos(0,0);
	canvas->Update2DC((HDC)hdc,0,0);
}

void WSAPI skipframe_canvas(ws_handle handle)
{
	WCanvas *canvas=(WCanvas *)handle;
	canvas->SkipFrame();
}

void WSAPI update_canvas(ws_handle handle,void *hdc)
{
	WCanvas *canvas=(WCanvas *)handle;
	canvas->SetPos(0,0);
	canvas->Blit2DC((HDC)hdc,0,0);
}

void WSAPI update_bitmap(ws_handle handle,void *hdc)
{
	WBitmap *canvas=(WBitmap *)handle;
	canvas->SetPos(0,0);
	canvas->Blit2DC((HDC)hdc,0,0);
}

ws_handle WSAPI create_text()
{
	return (ws_handle)new WString;
}

void WSAPI destroy_text(ws_handle str)
{
	delete (WString *)str;
}

void WSAPI set_text(ws_handle handle,const char *string)
{
	WString &str=*(WString *)handle;
	str=string;
}

#endif