#include "Utility.h"
#include "CCamera.h"

void Utility::ScreenToWorld(CVector3D *out,CVector3D spos,CMatrix mProj,CMatrix mView,int w,int h){
	CMatrix	mVP;
	mVP.Viewport(0, 0, (float)w, (float)h);
	CVector4D o = (mView.GetInverse() * mProj.GetInverse() * mVP.GetInverse()) * CVector4D(spos.x,spos.y,spos.z,1);
	*out = CVector3D(o.x/o.w,o.y/o.w,o.z/o.w);
	
}
void Utility::ScreenToWorld(CVector3D *out, CVector3D spos) {
	ScreenToWorld(out, spos, CCamera::GetCurrent()->GetProjectionMatrix(), CCamera::GetCurrent()->GetMatrix(), CCamera::GetCurrent()->GetScreenRect().m_right, CCamera::GetCurrent()->GetScreenRect().m_bottom);
}

void Utility::WorldToScreen(CVector3D *out,CVector3D spos,CMatrix mProj,CMatrix mView,int w,int h) {
	CMatrix	mVP;
	mVP.Viewport(0, 0, (float)w, (float)h);
	CVector4D o = mVP * mProj * mView * CVector4D(spos.x,spos.y,spos.z,1);

	*out =  CVector3D(o.x/o.w,o.y/o.w,o.z/w);

}
void Utility::WorldToScreen(CVector3D *out, CVector3D spos) {
	WorldToScreen(out, spos, CCamera::GetCurrent()->GetProjectionMatrix(), CCamera::GetCurrent()->GetMatrix(), CCamera::GetCurrent()->GetScreenRect().m_right, CCamera::GetCurrent()->GetScreenRect().m_bottom);
}


void Utility::DrawLine(CVector3D &s, CVector3D &e, CVector4D &color) {
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, (float*)color.v);
	glBegin(GL_LINES);
	//�J���[�ݒ�
	glColor4fv(color.v);
	//�`��
	glVertex3f(s.x, s.y,s.z);
	glVertex3f(e.x, e.y,e.z);
	glEnd();


}

void Utility::DrawCube(CVector3D &pos, float size, CVector4D &color) {
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, (float*)color.v);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	//�J���[�ݒ�
	glColor4fv(color.v);
	glutSolidCube(size);
	glPopMatrix();


}
void Utility::DrawLine(CVector2D &s, CVector2D &e, CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//�e��@�\�𖳌���
	//�J�����O����
	glDisable(GL_CULL_FACE);
	//���C�e�B���O����
	glDisable(GL_LIGHTING);
	//�f�v�X�e�X�g����
	glDisable(GL_DEPTH_TEST);
	//
	//���˓��e�̍s����쐬
	//
	CMatrix	mProj = CMatrix(
		2.0f / CCamera::GetCurrent()->GetWhidth(), 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / CCamera::GetCurrent()->GetHeight(), 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//���e�s����p�̕��ɐݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//���f�����r���[�s����Đݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_LINES);
	//�J���[�ݒ�
	glColor4fv(color.v);
	//�`��

	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();


	//���̍s��Ɛݒ�ɖ߂�
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}
void Utility::DrawQuad(CVector2D &pos, CVector2D &size, CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//�e��@�\�𖳌���
	//�J�����O����
	glDisable(GL_CULL_FACE);
	//���C�e�B���O����
	glDisable(GL_LIGHTING);
	//�f�v�X�e�X�g����
	glDisable(GL_DEPTH_TEST);
	//
	//���˓��e�̍s����쐬
	//
	CMatrix	mProj = CMatrix(
		2.0f / CCamera::GetCurrent()->GetWhidth(), 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / CCamera::GetCurrent()->GetHeight(), 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//���e�s����p�̕��ɐݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//���f�����r���[�s����Đݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_QUADS);
	//�J���[�ݒ�
	glColor4fv(color.v);
	//�`��

	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y);
	glEnd();


	//���̍s��Ɛݒ�ɖ߂�
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}
