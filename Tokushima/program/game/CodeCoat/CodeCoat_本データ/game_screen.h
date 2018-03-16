#ifndef __SCREEN_GAME_H__
#define __SCRENE_GAME_H__

//�w�b�_�[�t�@�C��
#include "myLib.h"
#include "Scene\SceneBase.h"
#include "map.h"
#include "player.h"
#include "item.h"

//�v���g�^�C�v
struct GameData;

//�^�C�g���X�N���[���N���X
class CGameScreen : public CSceneBase
{
public:
	CGameScreen();
	~CGameScreen();
	SCREEN GetNextScreen();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	CMapControl m_Mcnt;
	int m_bgm;
};
#endif __SCREEN_GAME_H__