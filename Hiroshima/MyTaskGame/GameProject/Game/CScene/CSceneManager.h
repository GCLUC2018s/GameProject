#ifndef SCENE_MANAGER_GUARD
#define SCENE_MANAGER_GUARD

#include "../GameProject/Gamesource.h"
/*

����ҁ@�{��

*/

enum {
	eTitle,
	eMain,
	eBoss,
	eEnd,
	eNull,
};
class CSceneManager : public CTask
{
public:
	//���̒��̕��͉����G��Ȃ�
	CSceneManager(int scene);
	~CSceneManager();
	void SetSceneObject(int scene_num);
private:
	//�^�C�g����ʂɕK�v�Ȃ��̂����̒��Ő���
	void TitleScene();
	//���C����ʂɕK�v�Ȃ��̂����̒��Ő���
	void MainScene();
	//�{�X��ʂɕK�v�Ȃ��̂����̒��Ő���
	void BossScene();
	//�G���h��ʂɕK�v�Ȃ��̂����̒��Ő���
	void EndScene();

};
#endif // !SCENE_MANAGER_GUARD
