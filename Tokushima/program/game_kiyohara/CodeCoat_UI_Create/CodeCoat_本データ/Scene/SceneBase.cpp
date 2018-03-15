/*!
	@brief	�V�[���x�[�X�N���X cpp
	@author	s.namizashi
**/

#include "SceneBase.hpp"

namespace
{
	// �J�n�V�[���^�C�v
	const enSceneType	START_SCENE(STYPE_GAME);
}

enSceneType clSceneBase::sm_NextID(START_SCENE);

// �R���X�g���N�^
clSceneBase::clSceneBase()
{
}

// �f�X�g���N�^
clSceneBase::~clSceneBase()
{
}

// ����������
void clSceneBase::Init()
{
}

// �I������
void clSceneBase::Finish()
{
}

// ���̃V�[��ID�ݒ�
void clSceneBase::SetNext( enSceneType id )
{
	SN_ASSERT(STYPE_NONE <= id && id < STYPE_COUNT);
	if(!(STYPE_NONE <= id && id < STYPE_COUNT)) return;

	sm_NextID = id;
}

// ���̃V�[��ID�擾
enSceneType clSceneBase::GetNextID()
{
	return sm_NextID;
}

// �X�V����(�p����p)
void clSceneBase::UpdateSub()
{
}

// �X�V����
void clSceneBase::Update()
{
	// �p����X�V
	UpdateSub();
}

// �`�揈��(�p����p)
void clSceneBase::DrawSub()
{
}

// �O�ʕ`�揈��(�p����p)
void clSceneBase::DrawFTSub()
{
}

// �`�揈��
void clSceneBase::Draw()
{
	// �p����`��
	DrawSub();

	// �p����O���`��
	DrawFTSub();
}