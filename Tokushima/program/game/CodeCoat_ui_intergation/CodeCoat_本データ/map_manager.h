/*!
@brief	マップ管理クラス h
@author	s.namizashi
**/

#ifndef __MAP_MANAGER_HPP__
#define __MAP_MANAGER_HPP__

#include "Include.h"
#include "map.h"

class CMapManager
{
private:
	static CMapManager* mp_Instance;
	CMapControl *m_map;
	int			m_Elapsed;
	/// コンストラクタ
	CMapManager();
public:
	/// デストラクタ
	~CMapManager();

	static CMapManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	初期化処理
	**/
	void Init(CMapControl *map);

	/*!
	@brief	終了処理
	**/
	void Finish();

	/*!
	@brief	敵のリスト取得
	**/
	CMapControl* GetPlayerAdress() const;

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__