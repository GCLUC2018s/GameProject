#include "item.h"
#include "item_manager.h"
#include "player_manager.h"

CItemData::CItemData() :
m_img(0)
, m_name(NONE)
, m_type(WEAPON)
, m_useful(0)
, m_attack_rate(0)
{}

//出現座標とアイテムの番号が引数
CIdata::CIdata(CVector3D* pos, int num)
:CTask(0, eUDP_Item, eDWP_Item)
, m_pos(*pos)
, m_name((ItemName)num)
{
	switch (num){//アイテムの種類によって数値を変更
	case KNIFE:
	case PISTOL:
	case SHOTTOGAN:
	case RIFLE:
		m_useful = 0;		//現状は大別しているため仮置き
		m_type = WEAPON;
		break;
	case STABARMOR:
		m_useful = 1;
		m_type = ARMOR;
		break;
	case BULLETARMOR:
		m_useful = 2;
		m_type = ARMOR;
		break;
	case SCOREBOOST:
	case SPEEDUP:
		m_useful = 10;
		m_type = ITEM;
		break;
	default:
		break;
	}
}

CIdata::~CIdata(){
}

void CIdata::Update(){
	//PlayerControlのアドレスを手に入れる
	auto l_player = CPlayerManager::GetInstance()->GetPlayerAdress();
	float _p_pos_z = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getZ()+PLAYER_LOWER_SIZE;

		//移動
		m_pos.setX(m_pos.getX() - l_player->getMoveAmount());

		if (_p_pos_z < m_pos.getZ()){
			CIdata::ChangeDrawPriority(eDWP_Item);
		}
		else{
			CIdata::ChangeDrawPriority(eDWP_BItem);
		}

}

void CIdata::Draw(){
	float _yscr = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	if (_yscr > 250.0f)
		_yscr = 250.0f;
	//アイテムの名前によって画像が変化
	DrawGraph(m_pos.getX(), m_pos.getY() + m_pos.getZ() - _yscr, CItemManager::GetInstance()->getImg(m_name), TRUE);
}
