#ifndef __SCREEN_BADCLEAR_H__
#define __SCREEN_BADCLEAR_H__

//�w�b�_�t�@�C��
#include "myLib.h"
//#include "scoredata.h"
#include "Scene\SceneBase.h"

const int BADGAMECLEAR_TIME = (7 * 1000);

//�Q�[���I�[�o�[�X�N���[���N���X
class CGameScoreScreen : public CSceneBase
{
public:
	CGameScoreScreen();
	~CGameScoreScreen();
	SCREEN GetNextScreen();
	void Update();
	void Draw();
	void Dest();
private:
	SCREEN m_state;
	int m_lasttime;
};
#endif __SCREEN_BADCLEAR_H__