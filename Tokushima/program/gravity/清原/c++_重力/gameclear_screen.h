#ifndef GAMECLEARSCREEN_H
#define GAMECLEARSCREEN_H

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "screen.h"
#include "game_data.h"

//�v���g�^�C�v
struct GameData;

//�Z���N�g�X�N���[���N���X
class CGameClearScreen : public CScreen
{
public:
	CGameClearScreen();
	~CGameClearScreen();
	SCREEN GetNextScreen();
	void Load();
	void Release();
	void Init();
	void Update();
	void Draw();
private:
	SCREEN m_state;
};
#endif GAMECLEARSCREEN_H