#ifndef __MAIN_H__
#define __MAIN_H__

//�w�b�_�t�@�C��
#include <DxLib.h>

//�v���g�^�C�v
class CGame;

//���C���N���X
class CMain			//state�p�^�[��
{
public:
	CMain();
	~CMain();
	
	void Dest();	//�ǂݍ���
	void Update();  //�X�V
	void Draw();	//�`��
private:
	CGame* m_pGame;
};
#endif __MAIN_H__