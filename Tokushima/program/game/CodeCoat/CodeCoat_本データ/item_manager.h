/*!
@brief	アイテム管理クラス hpp
@author	s.namizashi
**/

#ifndef __ITEM_MANAGER_HPP__
#define __ITEM_MANAGER_HPP__

#include "Include.h"

#include "item.h"

class CItemManager
{
private:
	static CItemManager* mp_Instance;
	std::vector<CIdata*> m_ItemList;
	int			m_Elapsed;
	int m_img[ITEMCOUNT];
	float m_price[ITEMCOUNT];
	/// コンストラクタ
	CItemManager();
public:
	/// デストラクタ
	~CItemManager();

	static CItemManager* GetInstance();
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
	@brief	アイテム生成
	**/
	void Create(CVector3D* pos);
	/*!
	@brief アイテムをリストから除外
	**/
	void Remove(CIdata* item);

	/*!
	@brief	アイテムのリスト取得
	**/
	std::vector<CIdata*> GetItemList() const;

	//アイテムの生成をする
	CItemData* makeItem(int num);
	
	//アイテムの売値を返却
	float get_itemprice(ItemName name){ return m_price[name]; }
	//画像を返す
	int getImg(int num);

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__