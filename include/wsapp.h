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

		Description:		风魂应用程序头文件
 		Original Author:	云风
		Authors:
		Create Time:		2000/12/12
		Modify Time:		2002/3/4

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#ifndef _WINDSOUL_APPLICATION_H
#define _WINDSOUL_APPLICATION_H

#ifndef _WINDOWS_
#error Include windows.h first!
#endif

//class WMapPtr;

class WWindow;

typedef int (WWindow::*WWndFunc)(DWORD,DWORD);

struct WMessageFunc {
	DWORD id;
	WWndFunc func;
};

#define MAP_MESSAGE_FUNC()								\
public:													\
virtual const WMessageFunc* GetMessageEntries() { return messageEntries; }	\
static const WMessageFunc messageEntries[];


#define BEGIN_MAP_MESSAGE(thisclass,baseclass)			\
const WMessageFunc thisclass::messageEntries[]={		\
	{(DWORD)(baseclass::messageEntries),0},
#define MAP_MESSAGE(id,func) {id,(WWndFunc)&func},
#define END_MAP_MESSAGE() {0,0}};

class WINDSOUL_API WWindow {
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK WWndProc(WWindow *wnd,UINT message, WPARAM wParam, LPARAM lParam);
	enum { blocksize=32 };
	int maxchildwnd;				// 最多子窗口数量
	int num;						// 子窗口数量
	WWindow **childwnd;				// 子窗口
protected:
	HWND hWnd;
public:
	WWindow() : hWnd(0), maxchildwnd(0), num(0) {};
	virtual ~WWindow();
	HWND GetHandle() const { return hWnd; }
	bool Create(const char *name,DWORD style=WS_OVERLAPPEDWINDOW, int w=CW_USEDEFAULT, int h=0, int x=CW_USEDEFAULT, int y=0,HWND parent=0);	// 创建窗口
	bool CreateEx(DWORD exstyle, const char *name,DWORD style=WS_OVERLAPPEDWINDOW, int w=CW_USEDEFAULT, int h=0, int x=CW_USEDEFAULT, int y=0,HWND parent=0);	// 创建窗口
	WWindow *CreateChild(const char *classname,const char *name,DWORD style,int x,int y,int w,int h,DWORD id);	// 创建子窗口
	const char *GetText();							// 得到窗口名
	void SetText(const char *text);					// 设置窗口名
	static void Init(HINSTANCE hInstance);			// 初始化窗口
	static ATOM RegisterWndClass(const char *classname,DWORD style,HICON icon,HCURSOR cursor,HBRUSH brush,const char *menuname);	// 注册窗口类
	int Show(int show=SW_SHOWDEFAULT) const;		// 显示窗口
	int Update() const;								// 刷新窗口
	HDC GetDC() const;								// 获得窗口 DC (安全释放)
	void ReleaseDC(HDC) const;						// 释放 DC (可以不调用)
	MAP_MESSAGE_FUNC()								// 消息映射表
};

class WINDSOUL_API WApplication : public WWindow {
	MAP_MESSAGE_FUNC()
	int OnDestroy(DWORD w,DWORD l);					// 窗口关闭, 发一退出消息
protected:
	virtual void AfterCreate() {};					// 创建完毕之后调用
	virtual void BeforeExit() {};					// 退出之前运行
	virtual void Idle() {};							// 空闲时间运行 (游戏主循环)
public:
	WApplication(HINSTANCE hInst);
	virtual ~WApplication() {};
	virtual bool CreateMainWindow();				// 创建主窗口
	void Excute();									// 运行
	void Quit();									// 关闭窗口退出程序
};

#endif