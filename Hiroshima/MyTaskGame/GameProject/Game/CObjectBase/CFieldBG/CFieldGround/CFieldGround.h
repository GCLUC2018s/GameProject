#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

/*

êªçÏé“Å@òZé‘

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround();
	~CFieldGround();
	void Update();
private:
	CRect m_rect_tourou1;
	CRect m_rect_tourou2;
	CRect m_rect_tourou3;
	CRect m_rect_tourou4;
};

#endif // !FIELDGROUND_GUARD
