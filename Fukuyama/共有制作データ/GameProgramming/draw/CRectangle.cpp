#include"CRectangle.h"
#include"glut.h"

//�l�p�`�̕`��
void C_Rectangle::Render(float a, float b, float c, float d){

	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
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

	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
	//�e�N�X�`���𖳌�
	glDisable(GL_TEXTURE_2D);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

//�\������l�p�`�̍��W���w�肵�܂�
void C_Rectangle::SetVertex(float left, float right, float bottom, float top)
{
	m_Left = left;
	m_Right = right;
	m_Bottom = bottom;
	m_Top = top;
}



//�㉺�|�W�V�����ݒ�
float C_Rectangle::m_PotisionY(float m_V){
	float mv = m_V;
	m_Top += mv;
	m_Bottom += mv;
	return mv;
}

//���E�|�W�V�����ݒ�
float C_Rectangle::m_PotisionX(float m_H){
	float mh = m_H;
	m_Left += mh;
	m_Right += mh;
	return mh;
}