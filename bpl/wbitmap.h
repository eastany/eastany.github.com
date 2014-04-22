//---------------------------------------------------------------------------

#ifndef WBitmapH
#define WBitmapH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "windsoul.h"

typedef void __fastcall (__closure *TKeyboardEvent)(System::TObject* Sender, int &Key);

//---------------------------------------------------------------------------
class PACKAGE TWBitmap : public TCustomControl
{
private:
   TMouseMoveEvent FOnMouseMove;
   TMouseEvent FOnDblClick;
   TMouseEvent FOnMouseDown;
   TMouseEvent FOnMouseUp;
   TKeyboardEvent FOnKeyUp;
   TKeyboardEvent FOnKeyDown;

    TShiftState ShiftState(int WParam);
    TPoint MousePoint(DWORD LParam);
protected:
    void __fastcall DoMessage(TMessage &Message);
//    virtual void __fastcall DoMouseMove(TShiftState Shift, int X, int Y);
//    void __fastcall AfterConstruction();
    void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
public:
    WBitmap Bitmap;
    __fastcall TWBitmap(TComponent* Owner);
    void __fastcall Paint(void);
__published:
    __property TAlign Align = {read=FAlign, write=SetAlign, default=0};
    __property TMouseEvent OnDblClick = {read=FOnDblClick,write=FOnDblClick};
    __property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove,write=FOnMouseMove};
    __property TMouseEvent OnMouseUp = {read=FOnMouseUp,write=FOnMouseUp};
    __property TMouseEvent OnMouseDown = {read=FOnMouseDown,write=FOnMouseDown};
    __property TKeyboardEvent OnKeyUp = {read=FOnKeyUp, write=FOnKeyUp};
    __property TKeyboardEvent OnKeyDown = {read=FOnKeyDown, write=FOnKeyDown};
    __property TCursor Cursor = {read=FCursor, write=SetCursor, default=0};
};
//---------------------------------------------------------------------------
#endif
 