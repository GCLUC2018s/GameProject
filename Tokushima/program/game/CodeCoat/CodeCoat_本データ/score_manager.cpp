#include "score_manager.h"

CScoreManager* CScoreManager::mp_Instance = nullptr;

CScoreManager* CScoreManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CScoreManager();
	}
	return mp_Instance;
}

void CScoreManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CScoreManager::CScoreManager()
: m_Elapsed(0)
{
}

// �f�X�g���N�^
CScoreManager::~CScoreManager()
{
}


// ����������
void CScoreManager::Init(ScoreData* player)
{
	m_score = player;
}

// �I������
void CScoreManager::Finish()
{
}

// �A�C�e���̃��X�g�擾
ScoreData* CScoreManager::GetPlayerAdress() const
{
	return m_score;
}

// �X�V����
void CScoreManager::Update()
{
}