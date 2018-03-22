/*!
@brief	敵管理クラス cpp
@author	s.namizashi
**/

#include "player_manager.h"
#include "bullet_manager.h"
#include "item_manager.h"
#include "enemy_manager.h"
#include "se_manager.h"

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
	m_evasion = 0;
	m_evasion_flag = false;
	m_nodamage_movement = 0;
	m_ndm_flag = false;
	m_passflag = false;
	m_player = player;
	m_nodamage_movement = 0;
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
	int _num = rand() % ITEM_RAND;		//追加


	CItemData *_Idata = m_player->getEquipment(WEAPON);
	CItemData *_Armor = m_player->getEquipment(ARMOR);
	if (_Idata->m_name == KNIFE && _Idata->m_useful > 0)
	{
		_knife_coli = 50.0f;
		_knife_flag = true;
		CPlayerManager::GetInstance()->setNoDamageMovement(0);	//追加
	}

	//主人公の腹部
	CVector3D _p_pos = m_player->getBodyPos() + CVector3D(PLAYER_CENTER, 0, PLAYER_LOWER_SIZE);
	auto _bullet_list = CBulletManager::GetInstance()->GetBulletList();
	for (auto it = _bullet_list.begin(); it != _bullet_list.end(); it++){
		if ((*it)->getWhoseBullet()){
			if (IsHitCircle(PLAYER_COLLISION + _knife_coli, BULLET_COLLISION, &_p_pos, &CVector3D((*it)->getPos().getX() + BULLET_CENTER, (*it)->getPos().getY(), (*it)->getPos().getZ() + BULLET_CENTER)))
			{
				PlaySoundMem(CSeManager::GetInstance()->getsnd(PURGE_SE), DX_PLAYTYPE_BACK);	//変更終わったら直して
				if (_knife_flag){
					(*it)->Kill();
				}
				else if (!m_player->getInvinsibleFlag()){
					if (_Armor->m_useful > 0){
						_Armor->m_useful--;
						m_player->SetInvincibleFlag();
						if (_Armor->m_useful == 0){
							CItemData* item = new CItemData;
							item->m_attack_rate = 0;
							item->m_img = 0;
							item->m_name = NONE;
							item->m_type = (ItemType)1;
							item->m_useful = 0;
							m_player->setEquipment(item);
						}
					}
					else{
						m_player->setDeath();
						CEnemyManager::getInstance()->SetComb(0);	//追加
						CPlayerManager::GetInstance()->setNoDamageMovement(0);	//追加
					}
				}
			}
		}
	}
	
	
	auto _enemy_list = CEnemyManager::getInstance()->getEnemyList();//ココから下変更、追加
	for (auto it2 = _enemy_list.begin(); it2 != _enemy_list.end(); it2++){
		//ナイフのみの判定が欲しかったので追加
		if (IsHitCircle(PLAYER_COLLISION + _knife_coli, ENEMY_COLLISION, &_p_pos, &CVector3D((*it2)->GetPos().getX() + ENEMY_CENTER, (*it2)->GetPos().getY(), (*it2)->GetPos().getZ() + ENEMY_LOWER_SIZE))){
			PlaySoundMem(CSeManager::GetInstance()->getsnd(DAMAGE_SE), DX_PLAYTYPE_BACK);
			if (_knife_flag){
				(*it2)->SetLive(false);
				CEnemyManager::getInstance()->SetDel(true);
				CEnemyManager::getInstance()->CombInc();		//追加
				if (_num == 1){
					CItemManager::GetInstance()->Create(&(*it2)->GetPos());	//追加
				}
			}
			CPlayerManager::GetInstance()->setNoDamageMovement(0);	//追加
		}
	
		if (!m_player->getInvinsibleFlag() && IsHitCircle(PLAYER_COLLISION, ENEMY_COLLISION, &_p_pos, &CVector3D((*it2)->GetPos().getX() + ENEMY_CENTER, (*it2)->GetPos().getY(), (*it2)->GetPos().getZ() + ENEMY_LOWER_SIZE))){
			if (_Armor->m_useful > 0){
				_Armor->m_useful--;
				m_player->SetInvincibleFlag();
				if (_Armor->m_useful == 0){
					CItemData* item = new CItemData;
					item->m_attack_rate = 0;
					item->m_img = 0;
					item->m_name = NONE;
					item->m_type = (ItemType)1;
					item->m_useful = 0;
					m_player->setEquipment(item);
				}
			}
			else{
				m_player->setDeath();
				CEnemyManager::getInstance()->SetComb(0);	//追加
				CPlayerManager::GetInstance()->setNoDamageMovement(0);	//追加
			}
		}
	}																//ここまで
	

	//主人公の足元


	_p_pos = m_player->getBodyPos();
	_p_pos += CVector3D(PLAYER_CENTER, 0, PLAYER_SHADOW_HEIGHT_POS);
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


	noDamageDistance();		//追加
}

void CPlayerManager::noDamageDistance(){	//追加
	float ma = CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount();
	m_nodamage_movement += ma;
	if (m_nodamage_movement > 2500){
		//450単位で切り替わる
		if (m_nodamage_movement /450 % 2 == 0){
			//一回入ると次の０まで入れない
			if (m_passflag == false){
				m_ndm_flag = true;
				m_passflag = true;
			}
		}
		else{
			m_passflag = false;
		}
	}
}