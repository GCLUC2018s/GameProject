#include <stdio.h>	//�t�@�C���̓��͂Ɏg�p
#include "CTexture.h"

void CTexture::Load(const char* filename) {
	//�摜�f�[�^
	unsigned char* data;
	//�t�@�C���|�C���^�̍쐬
	FILE *fp;
	errno_t error;
	//�t�@�C���I�[�v��
	error = fopen_s(&fp, filename, "rb");
	//�G���[�̂Ƃ��̓��^�[��
	if (error != 0) {
		printf("file not found:%s\n", filename);
		return;
	}
	//�w�b�_����ǂݍ���
	fread(&header, sizeof(header), 1, fp);
	//�摜�f�[�^�̃o�C�g�����v�Z����
	int length = header.width * header.height * header.depth / 8;
	//�摜�f�[�^�̊i�[�̈���m��
	data = new unsigned char[length];
	//�摜�f�[�^���w�b�_�̑�������ǂݍ���
	fread(data, length, 1, fp);
	//�摜�t�@�C���̃N���[�Y
	fclose(fp);

	//�e�N�X�`���f�[�^�̍쐬
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	if (header.depth == 32)
		//�A���t�@�L��̃e�N�X�`���쐬
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, header.width,
		header.height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
	else
		//�A���t�@�����̃e�N�X�`���쐬
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, header.width,
		header.height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
	//�i�[�̈�����
	delete[] data;
}

/*
DrawImage
left:�l�p�`�����W
right:�l�p�`�E���W
bottom:�l�p�`�����W
top:�l�p�`����W
tleft:�摜�����W
tright:�摜�E���W
tbottom:�摜�����W
ttop:�摜����W
*/
void CTexture::DrawImage(int left, int right, int bottom, int top, float tleft, float tright, float tbottom, float ttop) {
	//glColor4f(1.0f, 1.0f, 1.0f, x);
	//�e�N�X�`����L���ɂ���
	glEnable(GL_TEXTURE_2D);
	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//�e�N�X�`�����w��
	glBindTexture(GL_TEXTURE_2D, id);

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
