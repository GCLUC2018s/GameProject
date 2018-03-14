/*!
	@brief	�V�[���}�l�[�W���[�N���X cpp
	@author	s.namizashi
**/

#include "SceneManager.hpp"

#include "Source/Utility/Font.hpp"

#include "GameScene.hpp"

clSceneManager* clSceneManager::mp_Instance = nullptr;

clSceneManager* clSceneManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clSceneManager();
	}
	return mp_Instance;
}

void clSceneManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
clSceneManager::clSceneManager()
	: m_Scene(nullptr)
{
}

// �f�X�g���N�^
clSceneManager::~clSceneManager()
{
}

// ���̃V�[���𓮓I�Ɋm�ۂ��A�Ԃ�
clSceneBase* clSceneManager::GetNextScene()
{
	clSceneBase* pScene(nullptr);

	switch(clSceneBase::GetNextID())
	{
		case STYPE_GAME:	pScene = new clGameScene;	break;
	}

	SN_ASSERT(pScene);
	if (!pScene) return nullptr;
	else clSceneBase::SetNext(STYPE_NONE);

	return pScene;
}

// �V�[���؂�ւ�
void clSceneManager::ChangeScene()
{
	// �V�[���ǂݍ���ł���΁A
	if(m_Scene)
	{
		// �I������
		m_Scene->Finish();
		// �V�[�����
		SN_SAFE_DELETE(m_Scene);
	}

	// ���̃V�[���擾
	m_Scene = GetNextScene();
	// ������
	if(m_Scene) m_Scene->Init();
}

// ����������
void clSceneManager::Init()
{
}

// �X�V����
void clSceneManager::Update()
{
	// ���̃V�[�����ݒ肳��Ă���΁A
	if(clSceneBase::GetNextID() != STYPE_NONE)
	{
		// �V�[���؂�ւ�
		ChangeScene();
	}
	// �V�[���X�V
	if(m_Scene) m_Scene->Update();
}
