
#ifndef GAME_H
#define GAME_H

//�w�b�_�[�t�@�C��
#include "mylib.h"
#include "game_data.h"

//�v���g�^�C�v
enum SCREEN;
class CScreen;

//�Q�[���N���X
class CGame
{
public:
	CGame();
	~CGame();
	void Init();
	void Dest();
	void Update();
	void Draw();
private:
	CScreen*	m_pScreen;	//���݂̃X�N���[���N���X�̃|�C���^
	GameData	m_GameData;	//��ʏ��
};
#endif GAME_H
