#ifndef __GAME_H__
#define __GAME_H__

//�w�b�_�t�@�C��
#include "myLib.h"

//�v���g�^�C�v
enum SCREEN;
class CSceneBase;

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
	CSceneBase* m_pScreen;
	SCREEN m_now_screen;
};
#endif __GAME_H__