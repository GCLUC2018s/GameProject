#include"CRectangle.h"
#include"glut.h"

//四角形の描画
void C_Rectangle::Render(){
	if (!m_Enabled) return;
	glBegin(GL_TRIANGLES);
	glVertex2d(m_Left, m_Top);
	glVertex2d(m_Left, m_Bottom);
	glVertex2d(m_Right, m_Bottom);
	glVertex2d(m_Left, m_Top);
	glVertex2d(m_Right, m_Bottom);
	glVertex2d(m_Right, m_Top);
	glEnd();
}

//表示する四角形の座標を指定します
void C_Rectangle::SetVertex(float left, float right, float bottom, float top)
{
	m_Left = left;
	m_Right = right;
	m_Bottom = bottom;
	m_Top = top;
}

//スクロールの基準点が一定値を超えていたらスクロールする。
void C_Rectangle::Scroll(float left, float right){

	//idがUIでないならスクロールします
	if ((m_id != E_UI) && m_Right >= SCROLL_POINT){
		//スクロールの基準点が一定値より大きくなるとスクロールする
		if (CKey::Push(VK_RIGHT)){
			right -= PLAYER_LR_SPEED;
			left -= PLAYER_LR_SPEED;
		}
	}
	else if (m_id == E_UI){};
}