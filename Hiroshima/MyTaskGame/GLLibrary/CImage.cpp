#include "CImage.h"




CImage::CImage() : m_vPos(0,0),m_vCenter(0,0),m_vSize(0,0),srcRect(0,0,0,0),m_ang(0),m_flipH(false),m_color(1.0f,1.0f,1.0f,1.0f){
}
CImage::~CImage(){
}
bool CImage::Load(const char* path){
	bool f=false;
	f= CTexture::Load(path);
	if (f){
		SetPos(0, 0);
		SetRect(0, 0, (float)m_width, (float)m_height);
		SetSize((float)m_width, (float)m_height);
	}
	return f;
	

}

CImage* CImage::LoadImage(const char* path) {
	CImage* img = new CImage();
	if (img->Load(path)) {
		return img;
	}
	delete img;
	return nullptr;
}



void CImage::Draw() {

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
		2.0f / GL::window_width, 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / GL::window_height, 0.0f, 1.0f,
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
	CMatrix mT,mR;

	mT.Transelate(m_vPos.x,m_vPos.y,0.0f);
	
	mR.RotationZ(m_ang);

	glLoadMatrixf((mT * mR).f);




	MapTexture();

	//画像を張り付けるためのポリゴンの作成
	struct SVertex {
		float tu;
		float tv;
		float vx;
		float vy;
		float vz;
	};
	SVertex vertices[] = {
		//テクスチャー座標 uv														頂点座標xyz
		{ srcRect.m_left/m_width,srcRect.m_top/m_height,0-m_vCenter.x,			0-m_vCenter.y,			0.0f },		//左上
		{ srcRect.m_right/m_width,srcRect.m_top/m_height,m_vSize.x-m_vCenter.x,	0-m_vCenter.y,			0.0f },		//右上
		{ srcRect.m_left/m_width,srcRect.m_bottom/m_height,0-m_vCenter.x,		m_vSize.y-m_vCenter.y,	0.0f },		//左下
		{ srcRect.m_right/m_width,srcRect.m_bottom/m_height,m_vSize.x-m_vCenter.x,m_vSize.y-m_vCenter.y,	0.0f }		//右下
	};
	//左右反転処理
	if(m_flipH) {
		float t = vertices[0].tu;
		vertices[0].tu = vertices[2].tu = vertices[1].tu;
		vertices[1].tu = vertices[3].tu = t;
		
	}


	//描画
	glColor4fv(m_color.v);
	glInterleavedArrays(GL_T2F_V3F, 0, vertices);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);

	UnmapTexture();

	//元の行列と設定に戻す
	glPopMatrix();
    glMatrixMode(GL_PROJECTION);
	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
	

	glPopAttrib();
	
}