#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CObjectBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CGimmick :public CObjectBase {
public:
	CGimmick(CVector3D *pos);
	~CGimmick();
	void Update();
	void Draw();

private:
	int m_cnt;	//ÇÌÇ©ÇÁÇÒ
};

#endif // !GIMMICK_GUARD