/*!
	@brief	�e�Ǘ��N���X cpp
	@author	s.namizashi
**/

#include "BulletManager.hpp"
#include "Source/Game/Enemy/EnemyManager.hpp"

clBulletManager* clBulletManager::mp_Instance = nullptr;

clBulletManager* clBulletManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new clBulletManager();
	}
	return mp_Instance;
}

void clBulletManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
clBulletManager::clBulletManager()
{
}

// �f�X�g���N�^
clBulletManager::~clBulletManager()
{
}


// ����������
void clBulletManager::Init()
{
}

// �I������
void clBulletManager::Finish()
{
}

// �e����
void clBulletManager::Create(VECTOR2F start, VECTOR2F vec)
{
	// ����
	clBullet* bullet = new clBullet();
	bullet->Init(start, vec);
	// ���X�g�ɒǉ�
	m_BulletList.push_back(bullet);
}

// �e�����X�g���珜�O
void clBulletManager::Remove(clBullet* bullet)
{
	auto itr = std::find(m_BulletList.begin(), m_BulletList.end(), bullet);
	m_BulletList.erase(itr);
}

// �X�V����
void clBulletManager::Update()
{
	// ���˂��Ă���e��0�ł���Ώ������Ȃ�
	if (m_BulletList.size() == 0) return;

	// �G�̃��X�g�擾
	auto enemyList = clEnemyManager::GetInstance()->GetEnemyList();
	// �G�̐���0�̂ł���Ώ������Ȃ�
	if (enemyList.size() == 0) return;

	// �e�̐�������
	auto bullet = m_BulletList.begin();
	while (bullet != m_BulletList.end())
	{
		// ����ł�e���ǂ���
		if ((*bullet)->IsKill())
		{
			++bullet;
			continue;
		}

		// �e�̈ʒu
		auto bulletPos = (*bullet)->GetPos();

		// �G�̐������񂵂ăq�b�g�`�F�b�N
		auto enemy = enemyList.begin();
		while (enemy != enemyList.end())
		{
			// ���Ɏ���ł�G���ǂ���
			if ((*enemy)->IsKill())
			{
				++enemy;
				continue;
			}

			// �G�̈ʒu
			auto enemyPos = (*enemy)->GetPos();

			// �e�ƓG�̋����v�Z
			auto dis = VECTOR2F(enemyPos.x - bulletPos.x, enemyPos.y - bulletPos.y);
			float dist = std::sqrt(dis.x * dis.x + dis.y * dis.y);
			// ��苗���ȉ��ł����
			if (dist <= 25.0f)
			{
				// �q�b�g�����e�ƓG�̃^�X�N���E��
				(*bullet)->Kill();
				(*enemy)->Kill();
				break;
			}

			// ���̓G�𒲂ׂ�
			++enemy;
		}

		// ���̒e�𒲂ׂ�
		++bullet;
	}
}
