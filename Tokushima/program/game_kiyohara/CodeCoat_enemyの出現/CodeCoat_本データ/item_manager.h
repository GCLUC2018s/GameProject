/*!
@brief	�G�Ǘ��N���X hpp
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
	/// �R���X�g���N�^
	CItemManager();
public:
	/// �f�X�g���N�^
	~CItemManager();

	static CItemManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init();

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	�A�C�e������
	**/
	//void Create(CVector2D pos, int num);
	void Create(CVector2D pos);
	/*!
	@brief �G�����X�g���珜�O
	**/
	void Remove(CIdata* enemy);

	/*!
	@brief	�G�̃��X�g�擾
	**/
	std::vector<CIdata*> GetItemList() const;

	//�A�C�e���̐���������
	CItemData makeItem(int num);

	//�摜��Ԃ�
	int getImg(int num);

	/*!
	@brief	�X�V����
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__