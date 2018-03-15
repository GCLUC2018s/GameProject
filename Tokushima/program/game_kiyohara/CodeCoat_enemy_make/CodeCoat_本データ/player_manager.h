/*!
@brief	敵管理クラス hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "player.h"

class CPlayerManager
{
private:
	static CPlayerManager* mp_Instance;
	CPlayerControl *m_player;	//主人公のアドレス
	/// コンストラクタ
	CPlayerManager();
public:
	/// デストラクタ
	~CPlayerManager();

	static CPlayerManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	初期化処理
	**/
	void Init(CPlayerControl *player);

	/*!
	@brief	終了処理
	**/
	void Finish();

	/*!
	@brief	主人公のアドレス返却
	**/
	CPlayerControl* GetPlayerAdress() const;

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__