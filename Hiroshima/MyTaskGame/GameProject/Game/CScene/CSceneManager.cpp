#include "CSceneManager.h"
#include "DebugScene\DebugScene.h"

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

	/*new CEnemy1(&(CVector3D(400, 0, -300)));
	new CEnemy2(&(CVector3D(500, 100, -100)));
	new CEnemy3(&(CVector3D(600, 100, -250)));
	new CEnemy4(&(CVector3D(800, 50, -200)));
	new CEnemy5(&(CVector3D(200, 0, -130)));*/
	//new CBoss(&(CVector3D(3000, 50, 0)));
	new CGimmick(&(CVector3D(500, 0, -20)));
	new CGimmick(&(CVector3D(500, 0, -100)));
	new CFieldManager();

	//new CKoban(&(CVector3D(500,500, 0)));
	//new COage(&(CVector3D(500, 450, 0)));
	//new CSake(&(CVector3D(450, 500, 0)));
	//new CMagatama();	
	new CEnemyManager();
}

void CSceneManager::BossScene(){
	//�{�X�퓬��ʂ̗v�f�Ԃ�����
}

void CSceneManager::EndScene(){
	//�G���f�B���O��ʂ̗v�f�Ԃ�����
}
