#include "CFont.h"
#include "CCamera.h"
#include <locale.h>

//コンストラクタ フォント作成
CFont::CFont(wchar_t *font, int size)
{
 Hfont = CreateFont(
        size,      //フォント高さ
        0,       //文字幅
        0,       //テキストの角度
        0,       //ベースラインとｘ軸との角度
        FW_REGULAR,     //フォントの太さ
        FALSE,      //イタリック体
        FALSE,      //アンダーライン
        FALSE,      //打ち消し線
        SHIFTJIS_CHARSET,   //文字セット
        OUT_DEFAULT_PRECIS,   //出力精度
        CLIP_DEFAULT_PRECIS,  //クリッピング精度
        ANTIALIASED_QUALITY,  //出力品質
        FIXED_PITCH | FF_MODERN, //ピッチとファミリー
        font);     //書体名

 Hdc = wglGetCurrentDC();
 SelectObject(Hdc, Hfont);
}

void CFont::Draw(int x,int y,float r,float g,float b, const char *format, ...)
{
	SelectObject(Hdc, Hfont);
	
	char buf[256];
	va_list ap;
	int length = 0;


	if (format == NULL)
	{
		return;
	}

	//文字列変換 
	va_start(ap, format);
	vsprintf_s(buf, format, ap);
	va_end(ap);

	glPushAttrib(GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	//スクリーン左上を原点(0,0)にした正射投影の行列を作成
	CMatrix	mProj = CMatrix(
		2.0f/CCamera::GetCurrent()->GetWhidth() , 0.0f, 0.0f, -1.0f,
         0.0f, -2.0f/CCamera::GetCurrent()->GetHeight() , 0.0f, 1.0f,
         0.0f, 0.0f, 1.0f, 0.0f,
         0.0f, 0.0f, 0.0f, 1.0f
     );
	glLoadMatrixf(mProj.f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();



	
	glColor4f(r, g, b, 1.0f);
	float font_color[]={r,g,b,1.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, font_color);
	glRasterPos2i(x, y);
	
	setlocale(LC_CTYPE,"jpn");
	int size = _mbstrlen(buf);
	wchar_t *wbuf=new wchar_t[size+1];

	MultiByteToWideChar(CP_ACP,0,buf,-1, wbuf,sizeof(wchar_t)*size+1);


	int list = glGenLists(size);
	for( int i=0; i<size; i++ ){
		wglUseFontBitmapsW(Hdc, wbuf[i], 1, list + i);
	}
	for( int i=0; i<size; i++ ){
		glCallList(list + i);
	}

	glDeleteLists(list, size);

	delete wbuf;





	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	

	glPopAttrib();

};
void CFont::DrawString(int _x, int _y, float r, float g, float b, const wchar_t *format, ...)
{
	SelectObject(Hdc, Hfont);
	wchar_t buf[256];
	va_list ap;
	int length = 0;
	int list = 0;

	if (format == NULL)
	{
		return;
	}


	glPushAttrib(GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	//スクリーン左上を原点(0,0)にした正射投影の行列を作成
	CMatrix	mProj = CMatrix(
		2.0f / CCamera::GetCurrent()->GetWhidth(), 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / CCamera::GetCurrent()->GetHeight(), 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	glLoadMatrixf(mProj.f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	//文字列変換 
	va_start(ap, format);
	vswprintf_s(buf, format, ap);
	va_end(ap);

	length = wcslen(buf);
	list = glGenLists(length);
	for (int i = 0; i < length; i++)
	{
		wglUseFontBitmapsW(Hdc, buf[i], 1, list + (DWORD)i);
	}
	float font_color[] = { r,g,b,1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, font_color);
	glColor4f(r, g, b, 1.0f);

	glDisable(GL_LIGHTING);
	glRasterPos2i(_x, _y);
	//ディスプレイリストで描画 
	for (int i = 0; i< length; i++)
	{
		glCallList(list + i);
	}
	glEnable(GL_LIGHTING);
	//ディスプレイリスト破棄 
	glDeleteLists(list, length);


	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();

}
void CFont::Release() {
	if( Hfont ) DeleteObject( Hfont );
}