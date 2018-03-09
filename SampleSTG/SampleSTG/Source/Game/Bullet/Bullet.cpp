/*!
	@brief	�e�����N���X cpp
	@author	s.namizashi
**/

#include "Bullet.hpp"
#include "BulletManager.hpp"

// �R���X�g���N�^
clBullet::clBullet()
	: CTask(0, eUDP_Bullet, eDWP_Bullet)
	, m_Pos(0.0f, 0.0f)
	, m_Vec(0.0f, 1.0f)
	, m_IsInitialized(false)
	, m_IsKill(false)
{
}

// �f�X�g���N�^
clBullet::~clBullet()
{
}

// ����������
void clBullet::Init(VECTOR2F start, VECTOR2F vec)
{
	m_Pos = start;
	m_Vec = vec;

	m_Image.Load("Bullet.png");

	m_IsInitialized = true;
}

// �I������
void clBullet::Finish()
{
}

void clBullet::Kill()
{
	m_IsKill = true;
}

// �X�V����
void clBullet::Update()
{
	// �������ς݂�
	if (m_IsInitialized)
	{
		// �ړ�
		m_Pos.x += m_Vec.x;
		m_Pos.y += m_Vec.y;

		// ����ł�
		if (m_IsKill)
		{
			if (!m_destroyFlg)
			{
				// ���X�g�����菜��
				clBulletManager::GetInstance()->Remove(this);
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
void clBullet::Draw()
{
	m_Image.Draw();
}
