#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

class CPlayer;

/*

����ҁ@�Z��
�ҏW�@�@�{��

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround(const bool flag);	//�n�ʁBtrue�Ȃ��ʉE�O�ɐ���
	~CFieldGround();
	void Update();
	void Draw();
	void GroundHitCheck(CPlayer * pl);
private:
//	CRect m_rect_tourou[4];
	bool m_flag;
};

#endif // !FIELDGROUND_GUARD
