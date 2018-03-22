/*!
@brief	プレイヤー管理クラス hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "player.h"

class CPlayerManager
{
private:
	int m_evasion;				//回避した回数
	bool m_evasion_flag;		//回避フラグ
	int m_nodamage_movement;	//ダメージを受けずに走った距離
	bool m_ndm_flag;			//ダメージを受けずにある一定まで進むとtrue
	bool m_passflag;			//一度通ったか
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

	void countEvasion(){ m_evasion++; };								//追加	
	float getNoDamageMovement(){ return m_nodamage_movement; };			//追加
	bool getNdmFalg(){ return m_ndm_flag; };							//追加
	void setNoDamageMovement(float ndm){ m_nodamage_movement = ndm; };	//追加
	void setNdmFalg(bool f){ m_ndm_flag = f; };							//追加
	void noDamageDistance();	//追加
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__