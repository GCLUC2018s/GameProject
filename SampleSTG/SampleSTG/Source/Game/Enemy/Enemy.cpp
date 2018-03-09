/*!
	@brief	�G�����N���X cpp
	@author	s.namizashi
**/

#include "Enemy.hpp"
#include "EnemyManager.hpp"

// �R���X�g���N�^
clEnemy::clEnemy()
	: CTask(0, eUDP_Enemy, eDWP_Enemy)
	, m_Pos(0.0f, 0.0f)
	, m_Vec(0.0f, 0.0f)
	, m_IsInitialized(false)
	, m_IsKill(false)
{
}

// �f�X�g���N�^
clEnemy::~clEnemy()
{
}

// ����������
void clEnemy::Init(VECTOR2F start, VECTOR2F vec)
{
	m_Pos = start;
	m_Vec = vec;

	m_Image.Load("Enemy.png");

	m_IsInitialized = true;
}

// �I������
void clEnemy::Finish()
{
}

void clEnemy::Kill()
{
	m_IsKill = true;
}

// �X�V����
void clEnemy::Update()
{
	// �������I�������
	if (m_IsInitialized)
	{
		// �ړ�
		m_Pos.x += m_Vec.x;
		m_Pos.y += m_Vec.y;

		// ����ł邩
		if (m_IsKill)
		{
			if (!m_destroyFlg)
			{
				// �G�l�~�[�̃��X�g�����菜��
				clEnemyManager::GetInstance()->Remove(this);
				// �^�X�N�L��
				SetKill();
			}
		}
		// �����Ă�
		else
		{
			// ��ʊO����
			UVI uv = m_Image.GetUV();
			if (m_Pos.x < -uv.ex || m_Pos.x > WINDOW_WIDTH ||
				m_Pos.y < -uv.ey || m_Pos.y > WINDOW_HEIGHT)
			{
				Kill();
			}
		}
	}

	m_Image.SetPos(m_Pos.x, m_Pos.y);
	m_Image.Update();
}

// �`�揈��
void clEnemy::Draw()
{
	m_Image.Draw();
}
