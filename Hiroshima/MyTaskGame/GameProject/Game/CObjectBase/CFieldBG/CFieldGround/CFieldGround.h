#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

/*

����ҁ@�Z��

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround(const bool flag);	//�n�ʁBtrue�Ȃ��ʉE�O�ɐ���
	~CFieldGround();
	void Draw();
private:
	CRect m_rect_tourou1;
	CRect m_rect_tourou2;
	CRect m_rect_tourou3;
	CRect m_rect_tourou4;
};

#endif // !FIELDGROUND_GUARD
