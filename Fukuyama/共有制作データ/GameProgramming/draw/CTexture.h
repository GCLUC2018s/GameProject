#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "glut.h"
/*
TGA�t�@�C���̃t�H�[�}�b�g
*/
struct STgaheader{
	unsigned char    dummy1[12];
	unsigned short   width;//��
	unsigned short   height;//����
	unsigned char    depth;//�r�b�g�̐[��
	unsigned char    dummy2;
};

/*
�e�N�X�`���[�N���X
*/
class CTexture{
public:
	GLuint mId;
	STgaheader header;
	/*
	�f�t�H���g�R���X�g���N�^
	*/
	CTexture() :mId(0){}
	/*
	�f�X�g���N�^
	�i���̃C���X�^���X���j�������Ƃ��Ɏ��s�����j
	*/
	~CTexture(){
		if (mId != 0){
			glDeleteTextures(1, &mId);
			mId = 0;
		}
	}
	/*
	�摜�t�@�C���̓ǂݍ���
	�i�e�N�X�`���t�@�C���̓ǂݍ��݁j
	*/
	void Load(const char* filename);

	void CTexture::DrawImage(int left, int right, int bottom, int top, float tleft, float tright, float tbottom, float ttop);
};

#endif