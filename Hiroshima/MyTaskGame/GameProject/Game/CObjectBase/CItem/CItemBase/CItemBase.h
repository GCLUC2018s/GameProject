#ifndef ITEM_BASE_GUARD
#define ITEM_BASE_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CItemBase :public CObjectBase {
public:
	CItemBase(CVector3D *pos);
	~CItemBase();
	void Update();
	void Draw();
	//�����������̏���
	void Hit(CObjectBase * t);
protected:
	int m_time;		//���邭���鎞��
	bool m_get;		//true�Ȃ�Q�b�g���ꂽ
	void Vanush();	//�����鏈��
};

#endif // !ITEM_BASE_GUARD
