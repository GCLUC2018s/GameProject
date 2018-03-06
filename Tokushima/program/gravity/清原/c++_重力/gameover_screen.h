#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "screen.h"
#include "game_data.h"

//�v���g�^�C�v
struct GameData;

//�Z���N�g�X�N���[���N���X
class CGameOverScreen : public CScreen
{
public:
	CGameOverScreen();
	~CGameOverScreen();
	SCREEN GetNextScreen();
	void Load();
	void Release();
	void Init();
	void Update();
	void Draw();
private:
	SCREEN m_state;
};
#endif GAMEOVER_SCREEN_H