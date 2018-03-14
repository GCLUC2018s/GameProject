#include"CRectangle.h"
#include"glut.h"

//�l�p�`�̕`��
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

//�\������l�p�`�̍��W���w�肵�܂�
void C_Rectangle::SetVertex(float left, float right, float bottom, float top)
{
	m_Left = left;
	m_Right = right;
	m_Bottom = bottom;
	m_Top = top;
}

//�X�N���[���̊�_�����l�𒴂��Ă�����X�N���[������B
void C_Rectangle::Scroll(C_Rectangle*p){

	//id��UI�łȂ��Ȃ�X�N���[�����܂�
	if (m_Scroll >= SCROLL_POINT){
		//�X�N���[���̊�_�����l���傫���Ȃ�ƃX�N���[������
		if (CKey::Push(VK_RIGHT)){
			p->m_Right -= SCROLL_SPEED;
			p->m_Left -= SCROLL_SPEED;
		}
	}
	return;
}
