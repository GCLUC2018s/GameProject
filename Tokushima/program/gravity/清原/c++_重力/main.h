#ifndef MAIN_H
#define MAIN_H

//�w�b�_�[�t�@�C��
#include <stdio.h>
#include "Dxlib.h"

//�v���g�^�C�v
class CGame;

//���C���N���X
class CMain
{
public:
	CMain();
	~CMain();

	void Init();
	void Dest();
	void Update();
	void Draw();
private:
	CGame* m_pGame;
};
#endif MAIN_H