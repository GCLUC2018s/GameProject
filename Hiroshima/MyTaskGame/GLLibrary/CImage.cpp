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
		2.0f / GL::window_width, 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / GL::window_height, 0.0f, 1.0f,
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
	CMatrix mT,mR;

	mT.Transelate(m_vPos.x,m_vPos.y,0.0f);
	
	mR.RotationZ(m_ang);

	glLoadMatrixf((mT * mR).f);




	MapTexture();

	//�摜�𒣂�t���邽�߂̃|���S���̍쐬
	struct SVertex {
		float tu;
		float tv;
		float vx;
		float vy;
		float vz;
	};
	SVertex vertices[] = {
		//�e�N�X�`���[���W uv														���_���Wxyz
		{ srcRect.m_left/m_width,srcRect.m_top/m_height,0-m_vCenter.x,			0-m_vCenter.y,			0.0f },		//����
		{ srcRect.m_right/m_width,srcRect.m_top/m_height,m_vSize.x-m_vCenter.x,	0-m_vCenter.y,			0.0f },		//�E��
		{ srcRect.m_left/m_width,srcRect.m_bottom/m_height,0-m_vCenter.x,		m_vSize.y-m_vCenter.y,	0.0f },		//����
		{ srcRect.m_right/m_width,srcRect.m_bottom/m_height,m_vSize.x-m_vCenter.x,m_vSize.y-m_vCenter.y,	0.0f }		//�E��
	};
	//���E���]����
	if(m_flipH) {
		float t = vertices[0].tu;
		vertices[0].tu = vertices[2].tu = vertices[1].tu;
		vertices[1].tu = vertices[3].tu = t;
		
	}


	//�`��
	glColor4fv(m_color.v);
	glInterleavedArrays(GL_T2F_V3F, 0, vertices);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);

	UnmapTexture();

	//���̍s��Ɛݒ�ɖ߂�
	glPopMatrix();
    glMatrixMode(GL_PROJECTION);
	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
	

	glPopAttrib();
	
}