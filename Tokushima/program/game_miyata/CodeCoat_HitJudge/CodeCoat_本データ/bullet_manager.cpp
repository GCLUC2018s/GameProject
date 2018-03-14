/*!
@brief	�G�Ǘ��N���X cpp
@author	s.namizashi
**/

#include "bullet_manager.h"

CBulletManager* CBulletManager::mp_Instance = nullptr;

CBulletManager* CBulletManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CBulletManager();
	}
	return mp_Instance;
}

void CBulletManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CBulletManager::CBulletManager()
: m_Elapsed(0)
{
	m_img = LoadGraph("media\\img\\bullet.png");
}

// �f�X�g���N�^
CBulletManager::~CBulletManager()
{
}


// ����������
void CBulletManager::Init()
{
}

// �I������
void CBulletManager::Finish()
{
}

// �A�C�e������					�쐬�ꏊ	�ړ�����	��Ԏ���	�N�̂��̂�
void CBulletManager::Create(CVector3D* pos,CVector3D *vec,float fdist,int whose)
{
	//�A�C�e������
	CBullet* bullet = new CBullet(pos, vec, fdist,whose);
	// ���X�g�ɒǉ�
	m_bullet_list.push_back(bullet);
}

// �A�C�e�������X�g���珜�O
void CBulletManager::Remove(CBullet* bullet)
{
	auto itr = std::find(m_bullet_list.begin(), m_bullet_list.end(), bullet);
	m_bullet_list.erase(itr);
}

// �A�C�e���̃��X�g�擾
std::vector<CBullet*> CBulletManager::GetBulletList() const
{
	return m_bullet_list;
}
//�ԍ��w��̉摜�̕ԋp
int CBulletManager::getImg(){
	return m_img;
}


// �X�V����
void CBulletManager::Update()
{
}
