#ifndef __SCREEN_SELECT_H__
#define __SCREEN_SELECT_H__

//�w�b�_�t�@�C��
#include "myLib.h"
#include "screen.h"

//�v���g�^�C�v
struct GameData;

//�Z���N�g�X�N���[���N���X
class CSelectScreen : public CScreen
{
public:
	CSelectScreen();
	~CSelectScreen();
	SCREEN GetNextScreen();
	void Load();
	void Release();
	void Init();
	void Update();
	void Draw();
private:
	SCREEN m_state;
};
#endif __SCREEN_SELECT_H__