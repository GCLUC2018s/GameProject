#ifndef SCENE_MANAGER_GUARD
#define SCENE_MANAGER_GUARD


/*

����ҁ@�{��

*/

#include "../GameProject/Task/CTask.h"
enum {
	eDebug,
	eGameStart,
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
private:
	//�ύX�֎~�B�v�]�͋{����
	void SetSceneObject(int scene_num);

	//�X�^�[�g��ʂɕK�v�Ȃ��̂����̒��Ő���
	void GameStartScene();
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
