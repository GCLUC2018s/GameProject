/*!
@brief	敵管理クラス hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "npc.h"

class CNpcManager
{
private:
	static CNpcManager* mp_Instance;
	CNpc *m_npc;	//npcのアドレス
	/// コンストラクタ
	CNpcManager();
public:
	/// デストラクタ
	~CNpcManager();

	static CNpcManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	初期化処理
	**/
	void Init(CNpc *npc);

	/*!
	@brief	終了処理
	**/
	void Finish();

	/*!
	@brief	npcのアドレス返却
	**/
	CNpc* GetNpcAdress() const;

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__