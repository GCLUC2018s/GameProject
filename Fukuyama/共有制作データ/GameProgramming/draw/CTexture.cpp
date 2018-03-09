#include "CTexture.h"
#include <stdio.h>//�t�@�C�����͂ɕK�v

void CTexture::Load(const char*filename){
	//�摜�f�[�^
	unsigned char* data;
	//�t�@�C���|�C���^�̍쐬
	FILE *fp;
	//�t�@�C���I�[�v��
	fp = fopen(filename, "rb");
	//�G���[�̎��̓��^�[��
	if (fp == 0){
		printf("file not found : %s\n", filename);
		return;
	}
	//�w�b�_����ǂݍ���
	fread(&header, sizeof(header), 1, fp);
	//�摜�f�[�^�̃o�C�g�����v�Z����
	int length = header.width * header.height*
		header.depth / 8;
	//�摜�f�[�^�̊i�[�̈���m��
	data = new unsigned char[length];
	//�摜�f�[�^���w�b�_�̑�������ǂݍ���
	fread(data, length, 1, fp);
	//�摜�t�@�C���̃N���[�Y
	fclose(fp);

	//�e�N�X�`���f�[�^�̓o�^
	glGenTextures(1, &mId);
	glBindTexture(GL_TEXTURE_2D, mId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (header.depth == 32)
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
		header.width,
		header.height, GL_BGRA_EXT,
		GL_UNSIGNED_BYTE, data);
	else
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
		header.width,
		header.height, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
	//�i�[�̈�����
	delete[] data;
	}

void CTexture::DrawImage(int left, int right, int bottom, int top, float tleft, float tright, float tbottom, float ttop) {
	//�e�N�X�`����L���ɂ���
	glEnable(GL_TEXTURE_2D);
	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//�e�N�X�`�����w��
	glBindTexture(GL_TEXTURE_2D, mId);

	glBegin(GL_TRIANGLES);
	glTexCoord2f(tleft / header.width, (header.height - ttop) / header.height);
	glVertex2d(left, top);
	glTexCoord2f(tleft / header.width, (header.height - tbottom) / header.height);
	glVertex2d(left, bottom);
	glTexCoord2f(tright / header.width, (header.height - tbottom) / header.height);
	glVertex2d(right, bottom);
	glTexCoord2f(tleft / header.width, (header.height - ttop) / header.height);
	glVertex2d(left, top);
	glTexCoord2f(tright / header.width, (header.height - tbottom) / header.height);
	glVertex2d(right, bottom);
	glTexCoord2f(tright / header.width, (header.height - ttop) / header.height);
	glVertex2d(right, top);
	glEnd();

	//�e�N�X�`�������
	glBindTexture(GL_TEXTURE_2D, 0);
	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
	//�e�N�X�`���𖳌�
	glDisable(GL_TEXTURE_2D);
}
