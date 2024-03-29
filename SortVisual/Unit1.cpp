// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	TrackBar1->Position = StrToInt(Edit2->Text);
	arr = NULL;
	pen_width = 8;
	space = 4;
	angle = 30;
	space_up = 20;
	fon_color = clWhite;
	select_color = (TColor)RGB(245, 245, 245);
	item_color = clGray;
	line_color = clBlack;
	beze_color = clBlue;
	make_array();
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender) {
	Edit2->Text = IntToStr(TrackBar1->Position);
	timeout = TrackBar1->Position;
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Exit(TObject *Sender) {
	TrackBar1->Position = StrToInt(Edit2->Text);
	timeout = TrackBar1->Position;
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)

{
	if (Key == VK_RETURN) {
		Edit2Exit(Sender);
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	make_array();
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::make_array() {

	srand(time(NULL));
	randomize();

	arr_size = StrToInt(Edit1->Text);
	if (arr != NULL) {
		delete[]arr;
		arr = NULL;
	}
	arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		arr[i] = (rand() % ((1000 + 1) - 0) + 0);
	}

	max_height = ScrollBox1->Height - 25;
	max_width = ScrollBox1->Width - 2;
	int x = arr_size * (pen_width + space);
	max_width = x > max_width ? x : max_width;
	Image1->Height = max_height;
	Image1->Width = max_width;
	Image1->Picture->Bitmap->SetSize(max_width, max_height);

	draw_array(Image1);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::draw_array(TImage *img, int l_select, int r_select) {

	max_arr = arr[0];
	min_arr = arr[0];
	for (int i = 1; i < arr_size; i++) {
		if (max_arr < arr[i]) {
			max_arr = arr[i];
		}
		if (min_arr > arr[i]) {
			min_arr = arr[i];
		}
	}

	Image1->Canvas->Brush->Color = fon_color;
	Image1->Canvas->FillRect(Rect(0, 0, Image1->Width, Image1->Height));
	if (l_select >= 0 && r_select > 0 && l_select != r_select) {
		int x1 = l_select * (space + pen_width) + space;
		int x2 = (r_select + 1) * (space + pen_width) + space / 2;
		img->Canvas->Pen->Style = psClear;
		img->Canvas->Pen->Width = 0;
		img->Canvas->Brush->Color = select_color;

		img->Canvas->Rectangle(x1, 0, x2, img->Height);
	}

	for (int i = 0; i < arr_size; i++) {
		draw_item(img, i, item_color);
	}

}

// ----------------------------------------------------------------------------

void __fastcall TForm1::draw_line(TImage *img, int value) {

	img->Canvas->Pen->Style = psDashDotDot;
	img->Canvas->Pen->Width = 0;
	img->Canvas->Pen->Color = clBlack;
	img->Canvas->Brush->Color = clWhite;
	int y = max_height - (((value - min_arr) * (max_height - space_up - 10)) /
		(max_arr - min_arr)) - 5 - pen_width / 2;
	img->Canvas->MoveTo(0, y);
	img->Canvas->LineTo(img->Width, y);
}

// ----------------------------------------------------------------------------

void __fastcall TForm1::draw_item(TImage *img, int i, TColor color) {

	img->Canvas->Pen->Style = psSolid;
	img->Canvas->Pen->Width = 1;
	img->Canvas->Pen->Color = color;
	img->Canvas->Brush->Color = color;
	int x = i * (space + pen_width) + space;
	int y = max_height - (((arr[i] - min_arr) * (max_height - space_up - 10)) /
		(max_arr - min_arr)) - 5 - pen_width / 2;
	img->Canvas->Rectangle(x, max_height - 5, x + pen_width, y);
}

// ----------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	 buble_sort();
//	Buble *TBuble = new Buble(false);

}
// ----------------------------------------------------------------------------

void __fastcall TForm1::buble_sort() {
	int i, j, tmp;
	for (i = 1; i < arr_size; i++) {
		for (j = 0; j < arr_size - i; j++) {
			draw_array(Image1, 0, arr_size - i);
			draw_item(Image1, j, (TColor)RGB(0, 255, 0));
			draw_line(Image1, arr[j]);
			Image1->Update();
			// delay();
			Sleep(timeout);
			if (arr[j] > arr[j + 1]) {
				swap(j, j + 1, 0, arr_size - i, arr[j]);
			}
		}
	}
	draw_array(Image1);
	Image1->Update();
}

void __fastcall TForm1::delay() {

	for (unsigned start = GetTickCount(); GetTickCount() - start < timeout;
	Application->ProcessMessages());

}

// ----------------------------------------------------------------------------

void __fastcall TForm1::qsort(int b, int e) {

	int l = b, r = e;
	int piv = arr[(b + e) / 2]; // ������� ��������� ��� ������� ������ �������

	draw_array(Image1, b, e);
	draw_line(Image1, piv);
//	Image1->Update();
	delay();

	while (l <= r) {
		while (arr[l] < piv)
			l++;
		while (arr[r] > piv)
			r--;
		if (l <= r) {
			if (l != r) {
				swap(l, r, b, e, piv);
			}
			l++;
			r--;
		}
	}

	if (b < r)
		qsort(b, r);
	if (e > l)
		qsort(l, e);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::swap(int l, int r, int b, int e, int value) {

	int tmp;

	draw_array(Image1, b, e);
	draw_item(Image1, l, (TColor)RGB(0, 255, 0));
	draw_item(Image1, r, clRed);
	draw_line(Image1, value);
	draw_bezier(Image1, l, r, clBlue);
	// Image1->Update();
	 delay();
//	Sleep(timeout);

	tmp = arr[r];
	arr[r] = arr[l];
	arr[l] = tmp;

	draw_array(Image1, b, e);
	draw_item(Image1, l, (TColor)RGB(0, 255, 0));
	draw_item(Image1, r, clRed);
	draw_line(Image1, value);
	draw_bezier(Image1, l, r, clBlue);
	// Image1->Update();
	 delay();
//	Sleep(timeout);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	qsort(0, arr_size - 1);
	draw_array(Image1);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::draw_bezier(TImage *img, int l, int r, TColor color) {

	img->Canvas->Pen->Style = psSolid;
	img->Canvas->Pen->Width = 1;
	img->Canvas->Pen->Color = color;
	TPoint p[4];
	p[0].x = space + l * (space + pen_width) + pen_width / 2;
	p[0].y = max_height - (((arr[l] - min_arr) * (max_height - space_up - 10)) /
		(max_arr - min_arr)) - 5 - pen_width / 2;
	p[3].x = space + r * (space + pen_width) + pen_width / 2;
	p[3].y = max_height - (((arr[r] - min_arr) * (max_height - space_up - 10)) /
		(max_arr - min_arr)) - 5 - pen_width / 2;
	p[1].x = p[0].x + (p[3].x - p[0].x) / 6;
	p[1].y = 0;
	p[2].x = p[3].x - (p[3].x - p[0].x) / 6;
	p[2].y = 0;
	img->Canvas->PolyBezier(p, 3);
	draw_edje(img, p[1], p[0]);
	draw_edje(img, p[2], p[3]);

}

// ----------------------------------------------------------------------------

void __fastcall TForm1::draw_edje(TImage *img, TPoint p1, TPoint p2) {

	double angle;
	TPoint p3, p4;
	angle = 180 * atan2((long double)(p2.y - p1.y), p2.x - p1.x) / M_PI;
	p3 = TPoint(p2.x + (int)(15 * cos(M_PI * (angle + 155) / 180)),
		p2.y + (int)(15 * sin(M_PI * (angle + 155) / 180)));
	p4 = TPoint(p2.x + (int)(15 * cos(M_PI * (angle - 155) / 180)),
		p2.y + (int)(15 * sin(M_PI * (angle - 155) / 180)));
	img->Canvas->MoveTo(p2.x, p2.y);
	img->Canvas->LineTo(p3.x, p3.y);
	img->Canvas->MoveTo(p2.x, p2.y);
	img->Canvas->LineTo(p4.x, p4.y);
}
