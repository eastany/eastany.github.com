//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "example.h"
#include "windsoul.h"
#include "wscanvas.h"
#include "wsgeo.h"
#include "wsalpha.h"
#include "wsfont.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "WCanvas"
#pragma link "WBitmap"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
WBitmap bmp;
WAlphaBitmap alpha;
int mouse_x=0,mouse_y=0;
WFont font;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  OpenDialog1->DefaultExt = "BMP";
  OpenDialog1->FileName = "*.bmp;*.jpg";
  if (OpenDialog1->Execute())
  {
    DATAFILE f;
    f.Load(OpenDialog1->FileName.c_str());
    bmp.Destroy();
    bmp.Load(f);
//    Timer1->Enabled=false;
    WCanvas1->Change();
    WCanvas1->Pos(0,0)->Draw(bmp,BLIT_COPY);
    WCanvas1->UnChange();
    WCanvas1->Clear(0);
    WCanvas1->Update();
//    Timer1->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    static i=0;
    WCanvas1->MoveTo(i,i);
    WCanvas1->Change();
    WCanvas1->ViewPort(0,0);
    WCanvas1->Draw(alpha,0);
    WCanvas1->UnChange();
    WCanvas1->Pos(0,0)->Draw(bmp,BLIT_COPY);
    WCanvas1->Clear(0);
    WCanvas1->Update();
    if (++i>50) i=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::WBitmap1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    Label1->Caption=X;
    Label2->Caption=Y;
//    if (Shift.Contains(ssLeft)) {
        WBitmap1->Bitmap[Y][X]=0xff;
        WBitmap1->Paint();
//    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WBitmap1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbRight) {
        mouse_x=X;
        mouse_y=Y;
        }
    if (Button == mbLeft) {
        WBitmap1->Bitmap.Clear(0x808080);
        WBitmap1->Bitmap.Draw(WChar(font,'»ê',0xff),FONT_ALPHA);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WBitmap1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbRight) {
        WLine line(X-mouse_x,Y-mouse_y,0xff0000);
     WBitmap1->Bitmap.SetPos(mouse_x,mouse_y);
     WBitmap1->Bitmap.Draw(line,0);
//   WBitmap1->Bitmap[Y][X]=0xff0000;
     WBitmap1->Paint();
     }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
  OpenDialog1->DefaultExt = "TGA";
  OpenDialog1->FileName = "*.tga";
  if (OpenDialog1->Execute())
  {
    DATAFILE f;
    f.Load(OpenDialog1->FileName.c_str());
    alpha.LoadTGA(f);
//    Timer1->Enabled=false;
    WCanvas1->Change();
    WCanvas1->ViewPort(0,0);
    WCanvas1->Draw(alpha,0);
    WCanvas1->Pos(0,0)->Draw(bmp,BLIT_COPY);
    WCanvas1->UnChange();
    WCanvas1->Clear(0);
    WCanvas1->Update();
//    Timer1->Enabled=true;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        HFONT winfont;
	winfont=CreateFont(
		200,0,
		0, 0,
		FW_NORMAL,
		FALSE, FALSE, FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY,
//		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"ºÚÌå");
	font.Create(winfont,4);
}
//---------------------------------------------------------------------------

