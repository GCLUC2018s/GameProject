#include"CRectangle.h"
#include"glut.h"

//四角形の描画
void C_Rectangle::Render(float a, float b, float c, float d){

	//アルファブレンドを有効にする
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(a, b, c, d);

	if (!m_Enabled) return;
	glBegin(GL_TRIANGLES);
	glVertex2d(m_Left, m_Top);
	glVertex2d(m_Left, m_Bottom);
	glVertex2d(m_Right, m_Bottom);
	glVertex2d(m_Left, m_Top);
	glVertex2d(m_Right, m_Bottom);
	glVertex2d(m_Right, m_Top);
	glEnd();

	//アルファブレンドを無効
	glDisable(GL_BLEND);
	//テクスチャを無効
	glDisable(GL_TEXTURE_2D);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

//表示する四角形の座標を指定します
void C_Rectangle::SetVertex(float left, float right, float bottom, float top)
{
	m_Left = left;
	m_Right = right;
	m_Bottom = bottom;
	m_Top = top;
}



//上下ポジション設定
float C_Rectangle::m_PotisionY(float m_V){
	float mv = m_V;
	m_Top += mv;
	m_Bottom += mv;
	return mv;
}

//左右ポジション設定
float C_Rectangle::m_PotisionX(float m_H){
	float mh = m_H;
	m_Left += mh;
	m_Right += mh;
	return mh;
}