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
	/// コンストラクタ
	CScoreManager();
public:
	/// デストラクタ
	~CScoreManager();

	static CScoreManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	初期化処理
	**/
	void Init(ScoreData *score);

	/*!
	@brief	終了処理
	**/
	void Finish();

	/*!
	@brief	敵のリスト取得
	**/
	ScoreData* GetPlayerAdress() const;

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif SCORE_MANAGER_H
