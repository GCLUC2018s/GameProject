#ifndef __SCREEN_OVER_H__
#define __SCREEN_OVER_H__

//�w�b�_�t�@�C��
#include "myLib.h"
#include "Scene\SceneBase.h"

const int GAMEOVER_TIME = (5 * 1000);

//�Q�[���I�[�o�[�X�N���[���N���X
class CGameOverScreen : public CSceneBase
{
public:
	CGameOverScreen();
	~CGameOverScreen();
	SCREEN GetNextScreen();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	int m_GoverSound;
	int m_GoverImage;
	int m_lasttime;
};
#endif __SCREEN_OVER_H__