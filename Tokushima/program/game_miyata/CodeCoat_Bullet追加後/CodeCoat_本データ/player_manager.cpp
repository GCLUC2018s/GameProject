/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "player_manager.h"
#include "bullet_manager.h"
#include "item_manager.h"

CPlayerManager* CPlayerManager::mp_Instance = nullptr;

CPlayerManager* CPlayerManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CPlayerManager();
	}
	return mp_Instance;
}

void CPlayerManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// コンストラクタ
CPlayerManager::CPlayerManager()
{
}

// デストラクタ
CPlayerManager::~CPlayerManager()
{
}


// 初期化処理
void CPlayerManager::Init(CPlayerControl* player)
{
	m_player = player;
}

// 終了処理
void CPlayerManager::Finish()
{
	delete m_player;
	delete mp_Instance;
}

//主人公のアドレス返却
CPlayerControl* CPlayerManager::GetPlayerAdress() const
{
	return m_player;
}

// 更新処理
void CPlayerManager::Update()
{
	CVector2D _p_pos = m_player->getBodyPos() + CVector2D(25.0f, PLAYER_LOWER_SIZE);
	auto _bullet_list = CBulletManager::GetInstance()->GetBulletList();
	float _xdist, _ydist;
	for (auto it = _bullet_list.begin(); it != _bullet_list.end(); it++){
		_xdist = pow((*it)->GetPos().getX() - _p_pos.getX(), 2);
		_ydist = pow((*it)->GetPos().getY() - _p_pos.getY(), 2);
		if (_xdist + _ydist < 900)
		{
			
		}
	}

	auto Idata = CItemManager::GetInstance()->GetItemList();
	_p_pos = m_player->getBodyPos() + CVector2D(25.0f, PLAYER_SHADOW_POS);
	for (auto it2 = Idata.begin(); it2 != Idata.end(); it2++){
		_xdist = pow(((*it2)->GetPos().getX() + 100) - _p_pos.getX(), 2);
		_ydist = pow(((*it2)->GetPos().getY() + 100) - _p_pos.getY(), 2);
		if (_xdist + _ydist < 13225){
			(*it2)->SetKill();

			CItemData *item;
			item = CItemManager::GetInstance()->makeItem((int)(*it2)->GetName());

			m_player->setEquipment(item);
			CItemManager::GetInstance()->Remove((*it2));
		}
	}



}
