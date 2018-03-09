/*!
	@brief	�G�Ǘ��N���X cpp
	@author	s.namizashi
**/

#include "EnemyManager.hpp"

clEnemyManager* clEnemyManager::mp_Instance = nullptr;

clEnemyManager* clEnemyManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clEnemyManager();
	}
	return mp_Instance;
}

void clEnemyManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
clEnemyManager::clEnemyManager()
	: m_Elapsed(0)
{
}

// �f�X�g���N�^
clEnemyManager::~clEnemyManager()
{
}


// ����������
void clEnemyManager::Init()
{
}

// �I������
void clEnemyManager::Finish()
{
}

// �G����
void clEnemyManager::Create()
{
	// X���W�������_���Ŏ擾
	float x = rand() % WINDOW_WIDTH;
	VECTOR2F pos = VECTOR2F(x, 0.0f);
	VECTOR2F vec = VECTOR2F(0.0f, 0.5f);

	// �G����
	clEnemy* enemy = new clEnemy();
	enemy->Init(pos, vec);
	// ���X�g�ɒǉ�
	m_EnemyList.push_back(enemy);
}

// �G�����X�g���珜�O
void clEnemyManager::Remove(clEnemy* enemy)
{
	auto itr = std::find(m_EnemyList.begin(), m_EnemyList.end(), enemy);
	m_EnemyList.erase(itr);
}

// �G�̃��X�g�擾
std::vector<clEnemy*> clEnemyManager::GetEnemyList() const
{
	return m_EnemyList;
}

// �X�V����
void clEnemyManager::Update()
{
	// ���t���[�����ƂɓG�𐶐�
	m_Elapsed++;
	if (m_Elapsed >= 60 * 1.5f)
	{
		Create();
		m_Elapsed = 0;
	}
}
