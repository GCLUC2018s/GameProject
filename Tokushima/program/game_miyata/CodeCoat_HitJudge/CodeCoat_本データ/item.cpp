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

//�o�����W�ƃA�C�e���̔ԍ�������
CIdata::CIdata(CVector3D* pos, int num)
:CTask(0, eUDP_Item, eDWP_Item)
, m_pos(*pos)
, m_name((ItemName)num)
{
	switch (num){//�A�C�e���̎�ނɂ���Đ��l��ύX
	case KNIFE:
	case PISTOL:
	case SHOTTOGAN:
	case RIFLE:
		m_useful = 0;		//����͑�ʂ��Ă��邽�߉��u��
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
	//PlayerControl�̃A�h���X����ɓ����
	auto l_player = CPlayerManager::GetInstance()->GetPlayerAdress();
	
		//�ړ�
		m_pos.setX(m_pos.getX() - l_player->getMoveAmount());
}

void CIdata::Draw(){
	//�A�C�e���̖��O�ɂ���ĉ摜���ω�
	DrawGraph(m_pos.getX(), m_pos.getY() + m_pos.getZ(), CItemManager::GetInstance()->getImg(m_name), TRUE);
}
