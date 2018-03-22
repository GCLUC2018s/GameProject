#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H


#include "Include.h"
#include "scoredata.h"

class CScoreManager
{
private:
	static CScoreManager* mp_Instance;
	ScoreData *m_score;
	int			m_Elapsed;
	int m_myscore;
	/// �R���X�g���N�^
	CScoreManager();
public:
	/// �f�X�g���N�^
	~CScoreManager();

	static CScoreManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init(ScoreData *score);

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	�G�̃��X�g�擾
	**/
	ScoreData* GetPlayerAdress() const;

	/*!
	@brief	�X�V����
	**/
	void Update();
};

#endif SCORE_MANAGER_H
