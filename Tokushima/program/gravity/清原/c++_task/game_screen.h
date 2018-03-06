
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "screen.h"
//#include "map.h"

//�v���g�^�C�v
struct GameData;

//�Z���N�g�X�N���[���N���X
class CGameScreen : public CScreen
{
public:
	CGameScreen();
	~CGameScreen();
	SCREEN GetNextScreen();
	void Load();
	void Release();
	void Init();
	void Update();
	void Draw();
private:
	SCREEN m_state;
	//Map		map;
};

#endif GAME_SCREEN_H