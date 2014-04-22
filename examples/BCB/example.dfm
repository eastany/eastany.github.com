object Form1: TForm1
  Left = 197
  Top = 132
  Width = 783
  Height = 540
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 344
    Top = 88
    Width = 7
    Height = 13
    Caption = 'X'
  end
  object Label2: TLabel
    Left = 344
    Top = 128
    Width = 7
    Height = 13
    Caption = 'Y'
  end
  object Button1: TButton
    Left = 344
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Load'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 344
    Top = 184
    Width = 75
    Height = 25
    Caption = 'LoadTGA'
    TabOrder = 1
    OnClick = Button2Click
  end
  object WBitmap1: TWBitmap
    Left = 440
    Top = 8
    Width = 320
    Height = 240
  end
  object WCanvas1: TWCanvas
    Left = 8
    Top = 8
    Width = 320
    Height = 240
  end
  object OpenDialog1: TOpenDialog
    Left = 344
    Top = 8
  end
  object Timer1: TTimer
    Interval = 20
    OnTimer = Timer1Timer
    Left = 344
    Top = 40
  end
end
