/*!
@brief	se管理クラス hpp
@author	s.namizashi
**/

#ifndef __SE_MANAGER_HPP__
#define __SE_MANAGER_HPP__

#include "Include.h"
const int BGM_COUNT = 3;
const int SE_COUNT = 11;

enum SND_NAME{TITLE_BGM = 0,STAGE_BGM,RANKING_BGM,CLEAR_SE,OVER_SE,JUMP_SE,SHOT_SE,SHOT2_SE,EMPTY_SE,KNIFE_SE,ITEM_SE,DAMAGE_SE,GET_SE,PURGE_SE};

class CSeManager
{
private:
	static CSeManager* mp_Instance;
	int			m_Elapsed;
	int m_snd[BGM_COUNT + SE_COUNT];
	/// コンストラクタ
	CSeManager();
public:
	/// デストラクタ
	~CSeManager();

	static CSeManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	初期化処理
	**/
	void Init();

	/*!
	@brief	終了処理
	**/
	void Finish();

	/*!
	@brief	更新処理
	**/
	void Update();

	//音楽を返却する関数
	int getsnd(SND_NAME name){ return m_snd[name]; }
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__