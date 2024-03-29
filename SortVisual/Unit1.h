// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TTrackBar *TrackBar1;
	TButton *Button2;
	TButton *Button3;
	TScrollBox *ScrollBox1;
	TImage *Image1;

	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private: // User declarations

	int max_height, max_width;
	int pen_width;
	int space;
	int angle;

	int *arr;
	int arr_size, max_arr, min_arr;
	unsigned timeout;
	int space_up;

	TColor fon_color;
	TColor select_color;
	TColor item_color;
	TColor line_color;
	TColor beze_color;

	void __fastcall draw_array(TImage *img, int l_select = -1,
		int r_select = -1);
	void __fastcall draw_item(TImage *img, int i, TColor color);
	void __fastcall draw_line(TImage *img, int line);
	void __fastcall delay();
	void __fastcall make_array();
	void __fastcall qsort(int b, int e);
	void __fastcall swap(int l, int r, int b, int e, int line);
	void __fastcall draw_bezier(TImage *img, int l, int r, TColor color);
	void __fastcall draw_edje(TImage *img, TPoint p1, TPoint p2);

public: // User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall TForm1::buble_sort();
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
