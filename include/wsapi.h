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

		Description:		风魂 API 头文件
 		Original Author:	云风
		Authors:
		Create Time:		2001/1/4
		Modify Time:

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#ifndef _WINDSOUL_API_H
#define _WINDSOUL_API_H

#ifdef WINDSOUL_EXPORTS
	#define WSDLL_API __declspec(dllexport)
#else
	#define WSDLL_API __declspec(dllimport)
#endif

#define WSAPI __stdcall

typedef int ws_handle;
typedef unsigned long ws_color;

extern "C" {
WSDLL_API ws_handle WSAPI create_bitmap(int w,int h);									//创建 w * h 的位图
WSDLL_API ws_handle WSAPI create_sub_bitmap(ws_handle handle,int x,int y,int w,int h);	// 从一个位图里创建出一个子位图
WSDLL_API ws_handle WSAPI load_bitmap(const char *);									// 从一个文件创建一个位图
WSDLL_API void WSAPI destroy_bitmap(ws_handle handle);									// 删除位图
WSDLL_API void WSAPI destroy_canvas(ws_handle handle);
WSDLL_API int WSAPI bitmap_command(ws_handle handle,int command,int param1,int param2);	// 位图操作指令
WSDLL_API ws_handle WSAPI create_canvas(int w,int h);						// 创建一个 canvas (w * h)
WSDLL_API int WSAPI canvas_command(ws_handle handle,int command,int param1,int param2);	// canvas 操作指令
WSDLL_API int WSAPI canvas_command_stream(ws_handle handle,int command_num,int *);		// canvas 操作指令
WSDLL_API void WSAPI refresh_canvas(ws_handle handle,void *hdc);						// 刷新 canvas
WSDLL_API void WSAPI skipframe_canvas(ws_handle handle);								// 跳过一帧刷新
WSDLL_API void WSAPI update_canvas(ws_handle handle,void *hdc);							// 刷新一帧图片
WSDLL_API void WSAPI update_bitmap(ws_handle handle,void *hdc);
WSDLL_API ws_handle WSAPI create_text();												// 创建文字对象
WSDLL_API void WSAPI destroy_text(ws_handle str);										// 销毁文字对象
WSDLL_API void WSAPI set_text(ws_handle handle,const char *);							// 设置文字对象
};

// 设定关键点 (int x,int y)
#define	C_SETPOS	1
// 清除 (ws_color color,null)
#define C_CLEAR		2
// BLIT (ws_handle,DWORD style)
#define C_BLIT		3
// 写文字	(ws_handle,ws_color)
#define C_DRAWTEXT		4
// 校验合法性
#define C_ISVALID		5
// 得到像素点	(int x,int y)
#define C_GETPIXEL		101
// 设置像素点	(ws_color,null)
#define C_PUTPIXEL		102
// 设置屏幕坐标	(x,y)
#define C_SETSCREENPOS	103
// CanvasBlit (ws_handle,null)
#define C_BLITCANVAS	201
// 设置更变状态	(int changed,null)
#define C_CHANGE		202

#define C_MOVE			203
#define C_MOVETO		204

// blit 样式
#define BLIT_COPY	0
#define BLIT_ADDITIVE	0x1
#define BLIT_SUBTRACT	0x2
#define BLIT_TRANS		0x3
#define BLIT_MASK		0x4

#define CANVAS_NOCHANGE	0
#define CANVAS_CHANGE	1
#define CANVAS_SELFCHANGE	2

#endif