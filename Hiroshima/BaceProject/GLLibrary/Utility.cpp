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
	//カラー設定
	glColor4fv(color.v);
	//描画
	glVertex3f(s.x, s.y,s.z);
	glVertex3f(e.x, e.y,e.z);
	glEnd();


}

void Utility::DrawCube(CVector3D &pos, float size, CVector4D &color) {
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, (float*)color.v);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	//カラー設定
	glColor4fv(color.v);
	glutSolidCube(size);
	glPopMatrix();


}
void Utility::DrawLine(CVector2D &s, CVector2D &e, CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//各種機能を無効に
	//カリング無効
	glDisable(GL_CULL_FACE);
	//ライティング無効
	glDisable(GL_LIGHTING);
	//デプステスト無効
	glDisable(GL_DEPTH_TEST);
	//
	//正射投影の行列を作成
	//
	CMatrix	mProj = CMatrix(
		2.0f / CCamera::GetCurrent()->GetWhidth(), 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / CCamera::GetCurrent()->GetHeight(), 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//投影行列を専用の物に設定
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//モデル＆ビュー行列を再設定
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_LINES);
	//カラー設定
	glColor4fv(color.v);
	//描画

	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();


	//元の行列と設定に戻す
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}
void Utility::DrawQuad(CVector2D &pos, CVector2D &size, CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//各種機能を無効に
	//カリング無効
	glDisable(GL_CULL_FACE);
	//ライティング無効
	glDisable(GL_LIGHTING);
	//デプステスト無効
	glDisable(GL_DEPTH_TEST);
	//
	//正射投影の行列を作成
	//
	CMatrix	mProj = CMatrix(
		2.0f / CCamera::GetCurrent()->GetWhidth(), 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / CCamera::GetCurrent()->GetHeight(), 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//投影行列を専用の物に設定
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//モデル＆ビュー行列を再設定
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_QUADS);
	//カラー設定
	glColor4fv(color.v);
	//描画

	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y);
	glEnd();


	//元の行列と設定に戻す
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}
