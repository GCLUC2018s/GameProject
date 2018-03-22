#include "CSceneManager.h"
#include "DebugScene\DebugScene.h"
#include "../GameProject/Source/Fieldsource.h"
#include "../GameProject/Source/Enemysource.h"
#include "../GameProject/Source/Gamesource.h"
#include "../GameProject/Source/Itemsource.h"

CSceneManager::CSceneManager(int scene) : CTask(0, eU_Scene, eD_Null)
{
	SetSceneObject(scene);
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::SetSceneObject(int scene_num)
{
	CTaskManager::GetInstance()->SetKillAll();
	//�Ή������V�[���N���X�𐶐�
	switch (scene_num)
	{
	case eDebug:
		new CDebugScene();
		break;
	case eGameStart:
		GameStartScene();
		break;
	case eTitle:
		TitleScene();
		break;
	case eMain:
		MainScene();
		break;
	case eBoss:
		BossScene();
		break;
	case eEnd:
		EndScene();
		break;
	default:
		break;
	}
}

//�݂�Ȃ��������Ă����͈̂ȉ��̕���
void CSceneManager::GameStartScene()
{
	MusicStop();
	new CGameStart();
}

void CSceneManager::TitleScene(){
	//�^�C�g����ʂ̗v�f�Ԃ�����
	MusicStop();
	SOUND("BGM_Title")->Play(true);
	new CBB(0, 0, true);
	new CTitleBG();
}

void CSceneManager::MainScene() {
	//���C���퓬��ʂ̗v�f�Ԃ�����
	MusicStop();
	new CBB(60 * 3, 1, true);
	new CPlayer(PLAYER_HP);

	//new CFire(&(CVector3D(500, 0, -100)));
	/*new CItemBox(&(CVector3D(500, 0, -200)), 0);
	new CItemBox(&(CVector3D(900, 0, -20)), 1);*/

	new CFieldManager();
	new CMagatama();
	new CHPBar(false);
	new CEnemyManager();

}


void CSceneManager::BossScene() {
	//�{�X�퓬��ʂ̗v�f�Ԃ�����
	MusicStop();
	SOUND("BGM_Boss")->Play(true);
	CObjectBase *pl = dynamic_cast<CObjectBase*>(CTaskManager::GetInstance()->GetTask(eID_Player));
	int pl_hp;
	if(pl) pl_hp = pl->GetHP();
	else pl_hp = PLAYER_HP;
	new CBB(0, 0, true);
	new CPlayer(pl_hp);
	new CBossStage();
	new CMagatama();
	new CHPBar(true);
	new CHPBar(false);

}
void CSceneManager::EndScene(){
	//�G���f�B���O��ʂ̗v�f�Ԃ�����
	MusicStop();
	new CEnding();
}
