#include "item.h"
#include "item_manager.h"
#include "player_manager.h"

//�o�����W�ƃA�C�e���̔ԍ�������
CIdata::CIdata(CVector2D pos,int num)		
:CTask(0, eUDP_Item, eDWP_Item)
, m_pos(pos)
//, m_live(true)
//, m_IsKill(false)
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
		m_pos.setY(m_pos.getY());

		//����ł��邩
	/*	if (m_IsKill)
		{

		}*/
	
}

void CIdata::Draw(){
	//�A�C�e���̖��O�ɂ���ĉ摜���ω�
	DrawGraph(m_pos.getX(), m_pos.getY(), CItemManager::GetInstance()->getImg(m_name), TRUE);
}
/*
CItemData CIdata::BuyItem(ItemName name){
	CItemData item;
	//item�̒��g���l�߂Ă���
	item.m_img = m_img[name];
	item.m_name = name;

	switch (name){//�A�C�e���̎�ނɂ���Đ��l��ύX
	case KNIFE:
	case PISTOL:
	case SHOTTOGAN:
	case RIFLE:
		item.m_useful = 0;
		item.m_type = WEAPON;
		break;
	case STABARMOR:
		item.m_useful = 1;
		item.m_type = ARMOR;
		break;
	case BULLETARMOR:
		item.m_useful = 2;
		item.m_type = ARMOR;
		break;
	case SCOREBOOST:
	case SPEEDUP:
		item.m_useful = 10;
		item.m_type = ITEM;
		break;
	default:
		item.m_useful = 0;
		break;
	}
	return item;
}

void CItemControl::makeItem(CVector2D pos, ItemName name){
	idata item;
	item.m_pos = CVector2D(800.0f, 500.0f);
	item.m_name = name;
	item.m_live = true;
	m_itemList.push_back(item);
}
*/




/*CItemControl::CItemControl()
:CTask(0, eUDP_Item, eDWP_Item)

{
	printfDx("item");
	char *item[] = { "knife.png", "bar.png", "pistol.png", "shottogan.png", "rifle.png", "stabarmor.png", "bulletarmor.png", "x2score.png", "speedup.png" };
	char buf[256];
	for (int i = 0; i < ITEMCOUNT; i++){
		sprintf_s(buf, "media\\img\\Item\\%s", item[i]);
		m_img[i] = LoadGraph(buf);
	}
	CItemManager::GetInstance()->Add(this);
}

CItemControl::~CItemControl(){
}

//�����Ă���A�C�e�����E�����ۂɎ�l���ɑ��������邽�߂̂���
CItemData CItemControl::pickupItem(CVector2D pos){
	CItemData item;
	item.m_img = 0;
	item.m_useful = 0;

	for (auto it = m_itemList.begin(); it != m_itemList.end(); it++){
		if (pos == it->m_pos){
			it->m_live = false;

			item.m_img = m_img[(int)it->m_name];
			item.m_name = it->m_name;
			switch (it->m_name){//�A�C�e���̎�ނɂ���Đ��l��ύX
			case KNIFE:
			case BAR:
			case PISTOL:
			case SHOTTOGAN:
			case RIFLE:
				item.m_useful = 0;
				item.m_type = WEAPON;
				break;
			case STABARMOR:
				item.m_useful = 1;
				item.m_type = ARMOR;
				break;
			case BULLETARMOR:
				item.m_useful = 2;
				item.m_type = ARMOR;
				break;
			case SCOREBOOST:
			case SPEEDUP:
				item.m_useful = 10;
				item.m_type = ITEM;
				break;
			default:
				break;
			}
		}
	}
	//list<idata>�̍��W�ƏƂ炵���킹��
	return item;
}

CItemData CItemControl::BuyItem(ItemName name){
	CItemData item;
	//item�̒��g���l�߂Ă���
	item.m_img = m_img[name];
	item.m_name = name;

	switch (name){//�A�C�e���̎�ނɂ���Đ��l��ύX
	case KNIFE:
	case BAR:
	case PISTOL:
	case SHOTTOGAN:
	case RIFLE:
		item.m_useful = 0;
		item.m_type = WEAPON;
		break;
	case STABARMOR:
		item.m_useful = 1;
		item.m_type = ARMOR;
		break;
	case BULLETARMOR:
		item.m_useful = 2;
		item.m_type = ARMOR;
		break;
	case SCOREBOOST:
	case SPEEDUP:
		item.m_useful = 10;
		item.m_type = ITEM;
		break;
	default:
		item.m_useful = 0;
		break;
	}
	return item;
}

void CItemControl::eraseidata(){
	for (auto it = m_itemList.begin(); it != m_itemList.end();){
		if (it->m_live == false){
			it = m_itemList.erase(it);
			continue;
		}
		it++;
	}
}

void CItemControl::Update(){
	/*float l_Amount;
	l_Amount = CPlayerManager::GetInstance()->*/
//	for (auto it = m_itemList.begin(); it != m_itemList.end(); it++){
//		it->m_pos.setX(it->m_pos.getX() - /*Amount*/1);
//		if (it->m_pos.getX() < 0 - ITEM_CHIPSIZE)
//			it->m_live = false;
//	}
//}

/*void CItemControl::Draw(){
	for (auto it = m_itemList.begin(); it != m_itemList.end(); it++){
		DrawGraph((int)it->m_pos.getX(), (int)it->m_pos.getY(), m_img[/*it->m_name*///0], TRUE);
	//}
//}
