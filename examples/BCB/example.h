//---------------------------------------------------------------------------

#ifndef exampleH
#define exampleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "WCanvas.h"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "WBitmap.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TOpenDialog *OpenDialog1;
    TTimer *Timer1;
    TLabel *Label1;
    TLabel *Label2;
        TButton *Button2;
        TWBitmap *WBitmap1;
        TWCanvas *WCanvas1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall WBitmap1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall WBitmap1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall WBitmap1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
