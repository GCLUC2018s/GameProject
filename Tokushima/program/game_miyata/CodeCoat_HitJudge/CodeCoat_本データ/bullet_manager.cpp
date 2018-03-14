/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "bullet_manager.h"

CBulletManager* CBulletManager::mp_Instance = nullptr;

CBulletManager* CBulletManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CBulletManager();
	}
	return mp_Instance;
}

void CBulletManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CBulletManager::CBulletManager()
: m_Elapsed(0)
{
	m_img = LoadGraph("media\\img\\bullet.png");
}

// デストラクタ
CBulletManager::~CBulletManager()
{
}


// 初期化処理
void CBulletManager::Init()
{
}

// 終了処理
void CBulletManager::Finish()
{
}

// アイテム生成					作成場所	移動方向	飛ぶ時間	誰のものか
void CBulletManager::Create(CVector3D* pos,CVector3D *vec,float fdist,int whose)
{
	//アイテム生成
	CBullet* bullet = new CBullet(pos, vec, fdist,whose);
	// リストに追加
	m_bullet_list.push_back(bullet);
}

// アイテムをリストから除外
void CBulletManager::Remove(CBullet* bullet)
{
	auto itr = std::find(m_bullet_list.begin(), m_bullet_list.end(), bullet);
	m_bullet_list.erase(itr);
}

// アイテムのリスト取得
std::vector<CBullet*> CBulletManager::GetBulletList() const
{
	return m_bullet_list;
}
//番号指定の画像の返却
int CBulletManager::getImg(){
	return m_img;
}


// 更新処理
void CBulletManager::Update()
{
}
