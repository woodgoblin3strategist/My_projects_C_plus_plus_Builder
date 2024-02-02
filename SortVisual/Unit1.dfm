object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 471
  ClientWidth = 849
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    849
    471)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 16
    Width = 78
    Height = 13
    Caption = #1056#1072#1079#1084#1077#1088' '#1084#1072#1089#1089#1080#1074#1072
  end
  object Label2: TLabel
    Left = 304
    Top = 16
    Width = 67
    Height = 13
    Caption = #1047#1072#1076#1077#1088#1078#1082#1072' '#1084#1057
  end
  object Button1: TButton
    Left = 200
    Top = 11
    Width = 75
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 121
    Top = 13
    Width = 56
    Height = 21
    TabOrder = 1
    Text = '50'
  end
  object Edit2: TEdit
    Left = 377
    Top = 13
    Width = 49
    Height = 21
    TabOrder = 2
    Text = '500'
    OnExit = Edit2Exit
    OnKeyDown = Edit2KeyDown
  end
  object TrackBar1: TTrackBar
    Left = 432
    Top = 16
    Width = 150
    Height = 41
    Max = 2000
    Min = 1
    Frequency = 100
    Position = 1
    TabOrder = 3
    OnChange = TrackBar1Change
  end
  object Button2: TButton
    Left = 616
    Top = 11
    Width = 75
    Height = 25
    Caption = #1055#1091#1079#1099#1088#1105#1082
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 720
    Top = 11
    Width = 75
    Height = 25
    Caption = 'qsort'
    TabOrder = 5
    OnClick = Button3Click
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 184
    Width = 851
    Height = 290
    Anchors = [akLeft, akTop, akRight, akBottom]
    BorderStyle = bsNone
    TabOrder = 6
    object Image1: TImage
      Left = 0
      Top = 3
      Width = 849
      Height = 262
    end
  end
end
