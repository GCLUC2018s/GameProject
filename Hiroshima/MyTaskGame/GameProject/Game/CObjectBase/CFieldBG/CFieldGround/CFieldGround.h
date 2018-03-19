#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

class CPlayer;

/*

製作者　六車
編集　　宮﨑

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround(const bool flag);	//地面。trueなら画面右外に生成
	~CFieldGround();
	void Update();
	void Draw();
	void GroundHitCheck(CPlayer * pl);
private:
//	CRect m_rect_tourou[4];
	bool m_flag;
};

#endif // !FIELDGROUND_GUARD
