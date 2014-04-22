//---------------------------------------------------------------------------

#ifndef WCanvasH
#define WCanvasH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "windsoul.h"
#include "wscanvas.h"
typedef void __fastcall (__closure *TKeyboardEvent)(System::TObject* Sender, int &Key);

//---------------------------------------------------------------------------
class PACKAGE TWCanvas : public TCustomControl
{
private:
   TMouseMoveEvent FOnMouseMove;
//   TMouseMoveEvent FOnMouseExit;
//   TMouseMoveEvent FOnMouseEnter;
//   TMouseEvent FOnClick;
   TMouseEvent FOnDblClick;
   TMouseEvent FOnMouseDown;
   TMouseEvent FOnMouseUp;
   TKeyboardEvent FOnKeyUp;
   TKeyboardEvent FOnKeyDown;

    TShiftState ShiftState(int WParam);
    TPoint MousePoint(DWORD LParam);
protected:
    WCanvas *canvas;

    void __fastcall DoMessage(TMessage &Message);
//    virtual void __fastcall DoMouseMove(TShiftState Shift, int X, int Y);
//    void __fastcall AfterConstruction();
    void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
    void __fastcall Paint(void);
	void __fastcall NextFrame() {canvas->NextFrame();}		// 准备下一帧
public:
    __fastcall TWCanvas(TComponent* Owner);
    __fastcall ~TWCanvas();
    bool __fastcall IsValid() const { return (canvas!=0); } // 是否可以操作 canvas
	void __fastcall SkipFrame() {canvas->SkipFrame();}		// 跳过下一帧
//	void reset(int f);		// 时钟复位
	void __fastcall MoveTo(int x,int y) {canvas->MoveTo(x,y);}	// 移动到 p
	void __fastcall Move(int x,int y) {canvas->Move(x,y);}	// 移动 (x,y)
	int __fastcall GetX() const { return canvas->GetX();}		// 获取世界坐标 X
	int __fastcall GetY() const { return canvas->GetY();}		// 获取世界坐标 Y
	int __fastcall GetW() const { return canvas->GetW();}		// 获得 Canvas 的可视宽度
	int __fastcall GetH() const { return canvas->GetH();}		// 获得 Canvas 的可视高度
	WPoint __fastcall GetViewPort(int x,int y) const { return canvas->GetViewPort(x,y);}	// 获取视口坐标得对应世界坐标
	void __fastcall Clear(WPixel color) { canvas->Clear(color);}// 清除 Canvas
	WSERR __fastcall Draw(const WObject &bmp, DWORD style) { return canvas->Draw(bmp,style); }		// 画一张图
	WSERR __fastcall DrawEx(const WObject &bmp, DWORD style) { return canvas->DrawEx(bmp,style); }		// 画一张图
	void __fastcall Draw(WCanvas &c) { canvas->Draw(c); }	   	// 输入另一个画布
	void __fastcall SetOvlRect(int w,int h) { canvas->SetOvlRect(w,h); }// 添加覆盖矩形
	void __fastcall SetOvlRect(const WRect &rect) { canvas->operator()(rect.x,rect.y); canvas->SetOvlRect(rect.w,rect.h); }
	WCanvas* __fastcall Pos(int x,int y) {canvas->operator()(x,y); return canvas; }	// 设置关键点
	WCanvas* __fastcall ViewPort(int x,int y) { canvas->ViewPort(x,y); return canvas; }	// 设置视口关键点
	WCanvas* __fastcall UnChange() { canvas->UnChange(); return canvas; }	// 设置画布状态为相对上帧不变更
	WCanvas* __fastcall Change() { canvas->Change(); return canvas; }	// 设置画布状态为相对上帧变更
	WCanvas* __fastcall SelfChange() { canvas->SelfChange(); return canvas; }//  设置画布状态为相对上帧自身变更
	bool __fastcall IsMove() const { return canvas->IsMove(); }	// 是否移动
	void __fastcall Update() { canvas->Blit2DC(Canvas->Handle,0,0); }   	// 绘制到 DC
__published:
    __property TAlign Align = {read=FAlign, write=SetAlign, default=0};
   // Events
//    __property TMouseEvent OnClick = {read=FOnClick,write=FOnClick};
    __property TMouseEvent OnDblClick = {read=FOnDblClick,write=FOnDblClick};
//    __property TMouseMoveEvent OnMouseEnter = {read=FOnMouseEnter,write=FOnMouseEnter};
//    __property TMouseMoveEvent OnMouseExit = {read=FOnMouseExit,write=FOnMouseExit};
    __property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove,write=FOnMouseMove};
    __property TMouseEvent OnMouseUp = {read=FOnMouseUp,write=FOnMouseUp};
    __property TMouseEvent OnMouseDown = {read=FOnMouseDown,write=FOnMouseDown};
    __property TKeyboardEvent OnKeyUp = {read=FOnKeyUp, write=FOnKeyUp};
    __property TKeyboardEvent OnKeyDown = {read=FOnKeyDown, write=FOnKeyDown};
    __property TCursor Cursor = {read=FCursor, write=SetCursor, default=0};
};
//---------------------------------------------------------------------------
#endif
