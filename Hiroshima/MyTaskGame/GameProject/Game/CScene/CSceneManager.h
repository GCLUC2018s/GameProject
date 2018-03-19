#ifndef SCENE_MANAGER_GUARD
#define SCENE_MANAGER_GUARD

#include "../GameProject/Source/Fieldsource.h"
#include "../GameProject/Source/Enemysource.h"
#include "../GameProject/Source/Gamesource.h"
#include "../GameProject/Source/Itemsource.h"

/*

����ҁ@�{��

*/

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
