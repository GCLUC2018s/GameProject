/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "player_manager.h"
#include "bullet_manager.h"
#include "item_manager.h"
#include "enemy_manager.h"

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
	//ナイフを振っていれば数値が増大
	float _knife_coli = 0;
	bool _knife_flag = false;

	CItemData *_Idata = m_player->getEquipment(WEAPON);
	CItemData *_Armor = m_player->getEquipment(ARMOR);
	if (_Idata->m_name == KNIFE && _Idata->m_useful > 0)
	{
		_knife_coli = 30.0f;
		_knife_flag = true;
	}



	//主人公の腹部
	CVector3D _p_pos = m_player->getBodyPos() + CVector3D(PLAYER_CENTER, 0, PLAYER_LOWER_SIZE);
	auto _bullet_list = CBulletManager::GetInstance()->GetBulletList();
	for (auto it = _bullet_list.begin(); it != _bullet_list.end(); it++){
		if ((*it)->getWhoseBullet()){
			if (IsHitCircle(PLAYER_COLLISION + _knife_coli, BULLET_COLLISION, &_p_pos, &CVector3D((*it)->getPos().getX() + BULLET_CENTER, (*it)->getPos().getY(), (*it)->getPos().getZ() + BULLET_CENTER)))
			{
				if (_knife_flag){
					(*it)->Kill();
				}
					else
					if (_Armor->m_useful > 0)
						_Armor->m_useful--;
					else
						m_player->setDeath();
			}
		}
	}
	
	
	auto _enemy_list = CEnemyManager::getInstance()->getEnemyList();
	for (auto it2 = _enemy_list.begin(); it2 != _enemy_list.end(); it2++){
		if (IsHitCircle(PLAYER_COLLISION  + _knife_coli, ENEMY_COLLISION, &_p_pos, &CVector3D((*it2)->GetPos().getX() + ENEMY_CENTER, (*it2)->GetPos().getY(), (*it2)->GetPos().getZ() + ENEMY_LOWER_SIZE))){
			if (_knife_flag){
				(*it2)->SetLive(false);
			}
			else
			if (_Armor->m_useful > 0)
				_Armor->m_useful--;
			else
				m_player->setDeath();			
		}
		

	}
	

	//主人公の足元
	_p_pos = m_player->getBodyPos() + CVector3D(PLAYER_CENTER, 0, PLAYER_SHADOW_POS);
	auto _item_list = CItemManager::GetInstance()->GetItemList();
	for (auto it3 = _item_list.begin(); it3 != _item_list.end(); ){
		if (IsHitCircle(PLAYER_COLLISION, ITEM_COLLISION, &_p_pos, &CVector3D((*it3)->GetPos().getX() + ITEM_CENTER, (*it3)->GetPos().getY(), (*it3)->GetPos().getZ() + ITEM_CENTER))){
			(*it3)->SetKill();
			CItemData *item;
			item = CItemManager::GetInstance()->makeItem((int)(*it3)->GetName());

			m_player->setEquipment(item);
			CItemManager::GetInstance()->Remove((*it3));
		}
		it3++;
	}



}
