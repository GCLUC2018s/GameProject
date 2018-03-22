/*!
@brief	�A�C�e���Ǘ��N���X cpp
@author	s.namizashi
**/

#include "item_manager.h"

CItemManager* CItemManager::mp_Instance = nullptr;

CItemManager* CItemManager::GetInstance()
{
	if (mp_Instance == nullptr)
	{
		mp_Instance = new CItemManager();
	}
	return mp_Instance;
}

void CItemManager::ClearInstance()
{
	if (mp_Instance != nullptr) delete mp_Instance;
}

// �R���X�g���N�^
CItemManager::CItemManager()
: m_Elapsed(0)
{
	char *item[] = { "knife.png", "pistol.png", "shottogan.png","rifle.png","stabarmor.png","bulletarmor.png","speedup.png","x2score.png" };
	char buf[256];
	for (int i = 0; i < ITEMCOUNT; i++){
		sprintf_s(buf, "media\\img\\Item\\%s", item[i]);
		m_img[i] = LoadGraph(buf);
	}
	m_price[KNIFE] = 1000.0f;
	m_price[PISTOL] = 500.0f;
	m_price[SHOTTOGAN] = 2000.0f;
	m_price[RIFLE] = 2500.0f;
	m_price[STABARMOR] = 1000.0f;
	m_price[BULLETARMOR] = 1500.0f;
	m_price[SCOREBOOST] = 2000.0f;
	m_price[SPEEDUP] = 1000.0f;
}

// �f�X�g���N�^
CItemManager::~CItemManager()
{
}


// ����������
void CItemManager::Init()
{
}

// �I������
void CItemManager::Finish()
{
}

// �A�C�e������
void CItemManager::Create(CVector3D* pos)
{
	int _num = rand() % ITEMCOUNT;
	//�A�C�e������
	CIdata* item = new CIdata(pos,_num);
	// ���X�g�ɒǉ�
	m_ItemList.push_back(item);
}

// �A�C�e�������X�g���珜�O
void CItemManager::Remove(CIdata* item)
{
	auto itr = std::find(m_ItemList.begin(), m_ItemList.end(), item);
	m_ItemList.erase(itr);
}

// �A�C�e���̃��X�g�擾
std::vector<CIdata*> CItemManager::GetItemList() const
{
	return m_ItemList;
}
//�ԍ��w��̉摜�̕ԋp
int CItemManager::getImg(int num){
	return m_img[num];
}

CItemData* CItemManager::makeItem(int name){
	CItemData* item = new CItemData;
	//item�̒��g���l�߂Ă���
	item->m_img = m_img[name];
	item->m_name = (ItemName)name;

	switch (name){//�A�C�e���̎�ނɂ���Đ��l��ύX �������鐔�l�͉��u��
	case KNIFE:
		item->m_type = WEAPON;
		item->m_attack_rate = 30;
		break;
	case PISTOL:
		item->m_attack_rate = 0;
		item->m_useful = 15;
		item->m_type = WEAPON;
		break;
	case RIFLE:
		item->m_useful = 30;
		item->m_attack_rate = 3;
		break;
	case SHOTTOGAN:
		item->m_useful = 8;
		item->m_attack_rate = 60;
		break;
	case STABARMOR:
		item->m_useful = 1;
		item->m_type = ARMOR;
		break;
	case BULLETARMOR:
		item->m_useful = 2;
		item->m_type = ARMOR;
		break;
	case SCOREBOOST:
	case SPEEDUP:
		item->m_useful = 10000;
		item->m_type = ITEM;
		break;
	default:
		item->m_useful = 0;
		break;
	}
	return item;
}

// �X�V����
void CItemManager::Update()
{
	// ���t���[�����ƂɓG�𐶐�
	/*m_Elapsed++;
	if (m_Elapsed >= 60 * 1.5f)
	{
		Create();
		m_Elapsed = 0;
	}*/
}
