//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WBitmap.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TWBitmap *)
{
    new TWBitmap(NULL);
}
//---------------------------------------------------------------------------
__fastcall TWBitmap::TWBitmap(TComponent* Owner)
    : TCustomControl(Owner)
{
    Width=320;
    Height=240;
    WindowProc=DoMessage;
}
//---------------------------------------------------------------------------
void __fastcall TWBitmap::SetBounds(int ALeft, int ATop, int AWidth, int AHeight)
{
    if (AWidth>0 && AHeight>0) {
        if (!Bitmap.IsValid()) {
            Bitmap.Create(AWidth,AHeight);
            Bitmap.Clear(0);
        }
        else if (Bitmap.GetW()!=AWidth || Bitmap.GetH()!=AHeight) {
            WBitmap tmp(AWidth,AHeight);
            if (Bitmap.GetW()<AWidth || Bitmap.GetH()<AHeight) {
                tmp.Clear(0);
            }
            if (Bitmap.IsValid()) tmp.Draw(Bitmap(0,0),BLIT_COPY);
            Bitmap=tmp;
        }
    }
    TCustomControl::SetBounds(ALeft,ATop,AWidth,AHeight);
}
//---------------------------------------------------------------------------
void __fastcall TWBitmap::Paint(void)
{
    if (Bitmap.IsValid()) {
        Bitmap.Blit2DC(Canvas->Handle,0,0,0,0,Bitmap.GetW(),Bitmap.GetH());
    }
}
//---------------------------------------------------------------------------
TShiftState TWBitmap::ShiftState(int WParam)
{
   TShiftState result;

    if (WParam & MK_CONTROL)
        result << ssCtrl;
    if (WParam & MK_SHIFT)
        result << ssShift;
    if (WParam & MK_LBUTTON)
        result << ssLeft;
    if (WParam & MK_RBUTTON)
        result << ssRight;
    if (WParam & MK_MBUTTON)
        result << ssMiddle;
   return result;
}
//---------------------------------------------------------------------------
TPoint TWBitmap::MousePoint(DWORD LParam)
{
    TPoint t;
    t.x=LParam&0xffff;
    t.y=LParam>>16;
    if (t.x&0x8000) t.x=0;
    else if (t.x>=Width) t.x=Width-1;
    if (t.y&0x8000) t.y=0;
    else if (t.y>=Height) t.y=Height-1;
    return t;
}
//---------------------------------------------------------------------------
void __fastcall TWBitmap::DoMessage(TMessage &Message)
{
   TShiftState shift;
   TPoint mp;
   switch (Message.Msg) {
   case WM_MOUSEMOVE:
        if (FOnMouseMove) {
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseMove(this,ShiftState(Message.WParam), mp.x,mp.y);
        }
        break;
   case WM_LBUTTONDOWN:
        if (FOnMouseDown) {
            shift = ShiftState(Message.WParam);
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseDown(this,mbLeft,shift, mp.x,mp.y);
        }
        break;
   case WM_LBUTTONUP:
        if (FOnMouseUp) {
            shift = ShiftState(Message.WParam);
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseUp(this,mbLeft,shift,  mp.x,mp.y);
            }
        break;
   case WM_LBUTTONDBLCLK:
        if (FOnDblClick) {
            shift = ShiftState(Message.WParam);
            shift << ssDouble;
            mp=MousePoint((DWORD)Message.LParam);
            FOnDblClick(this,mbLeft,shift,  mp.x,mp.y);
            }
        break;
   case WM_RBUTTONDOWN:
        if (FOnMouseDown) {
            shift = ShiftState(Message.WParam);
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseDown(this,mbRight,shift,  mp.x,mp.y);
            }
        break;
   case WM_RBUTTONUP:
        if (FOnMouseUp) {
            shift = ShiftState(Message.WParam);
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseUp(this,mbRight,shift,  mp.x,mp.y);
            }
        break;
   case WM_RBUTTONDBLCLK:
        if (FOnDblClick) {
            shift = ShiftState(Message.WParam);
            shift << ssDouble;
            mp=MousePoint((DWORD)Message.LParam);
            FOnDblClick(this,mbRight,shift,  mp.x,mp.y);
            }
        break;
   case WM_MBUTTONDOWN:
        if (FOnMouseDown) {
            shift = ShiftState(Message.WParam);
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseDown(this,mbMiddle,shift,  mp.x,mp.y);
            }
        break;
   case WM_MBUTTONUP:
        if (FOnMouseUp) {
            shift = ShiftState(Message.WParam);
            mp=MousePoint((DWORD)Message.LParam);
            FOnMouseUp(this,mbMiddle,shift,  mp.x,mp.y);
            }
        break;
   case WM_MBUTTONDBLCLK:
        if (FOnDblClick) {
            shift = ShiftState(Message.WParam);
            shift << ssDouble;
            mp=MousePoint((DWORD)Message.LParam);
            FOnDblClick(this,mbMiddle,shift,  mp.x,mp.y);
            }
        break;
   case WM_KEYUP:
        if (FOnKeyUp) {
            FOnKeyUp(this,Message.WParam);
        }
        break;
   case WM_KEYDOWN:
        if (FOnKeyDown) {
            FOnKeyDown(this,Message.WParam);
        }
        break;
   }
   WndProc(Message);
}
//---------------------------------------------------------------------------
namespace Wbitmap
{
    void __fastcall PACKAGE Register()
    {
         TComponentClass classes[1] = {__classid(TWBitmap)};
         RegisterComponents("WindSoul", classes, 0);
    }
}
//---------------------------------------------------------------------------
 