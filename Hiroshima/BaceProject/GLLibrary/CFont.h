#pragma once
#include "GL.h"

class CFont {
private:
 HFONT Hfont;
 HDC Hdc;
public:
	CFont(wchar_t *font = L"‚l‚rƒSƒVƒbƒN", int size=24);
	void Draw(int x,int y,float r,float g,float b, const char *format, ...);
	void DrawString(int _x, int _y, float r, float g, float b, const wchar_t *format, ...);

	void Release();
};