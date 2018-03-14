/*!
@brief	敵管理クラス hpp
@author	s.namizashi
**/

#ifndef __BULLET_MANAGER_HPP__
#define __BULLET_MANAGER_HPP__

#include "Include.h"

#include "bullet.h"

class CBulletManager
{
private:
	static CBulletManager* mp_Instance;
	std::vector<CBullet*> m_bullet_list;
	int			m_Elapsed;
	int m_img;
	/// コンストラクタ
	CBulletManager();
public:
	/// デストラクタ
	~CBulletManager();

	static CBulletManager* GetInstance();
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
	void Create(CVector2D* pos, CVector2D *vec, float fdist,int whose);
	/*!
	@brief 敵をリストから除外
	**/
	void Remove(CBullet* bullet);

	/*!
	@brief	弾のリスト取得
	**/
	std::vector<CBullet*> GetBulletList() const;

	//画像を返す
	int getImg();

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__