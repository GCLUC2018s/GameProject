#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

/*

製作者　六車

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround(const bool flag);	//地面。trueなら画面右外に生成
	~CFieldGround();
	void Draw();
private:
	CRect m_rect_tourou1;
	CRect m_rect_tourou2;
	CRect m_rect_tourou3;
	CRect m_rect_tourou4;
};

#endif // !FIELDGROUND_GUARD
