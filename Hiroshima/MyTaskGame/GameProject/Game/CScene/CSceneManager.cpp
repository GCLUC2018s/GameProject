#include "CSceneManager.h"

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
	new CGameStart();
}

void CSceneManager::TitleScene(){
	//�^�C�g����ʂ̗v�f�Ԃ�����
	SOUND("BGM_Main")->Stop();
	SOUND("BGM_Title")->Play(true);
	new CTitleBG();
}

void CSceneManager::MainScene(){
	//���C���퓬��ʂ̗v�f�Ԃ�����
	SOUND("BGM_Title")->Stop();
	new CBB(60 * 3,true);
	new CPlayer();

	new CEnemy1(&(CVector3D(200, 300, 0)));
	new CEnemy2(&(CVector3D(200, 100, 0)));
	new CEnemy3(&(CVector3D(100, 300, 0)));
	new CEnemy4(&(CVector3D(300, 400, 0)));
	new CEnemy5(&(CVector3D(400, 450, 0)));
	//new CBoss(&(CVector3D(3000, 50, 0)));
	new CGimmick(&(CVector3D(500, 500, 0)));
	new CGimmick(&(CVector3D(250, 500, 0)));
	new CGimmick(&(CVector3D(500, 250, 0)));
//	new CFieldBG();
	new CFieldSky();
	new CFieldCloud();
	new CFieldBamboo();
	new CFieldGround();
	new CItem(&(CVector3D(500,500,0)));
}

void CSceneManager::BossScene(){
	//�{�X�퓬��ʂ̗v�f�Ԃ�����
}

void CSceneManager::EndScene(){
	//�G���f�B���O��ʂ̗v�f�Ԃ�����
}
