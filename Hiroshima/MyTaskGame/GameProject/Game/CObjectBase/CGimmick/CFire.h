#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CObjectBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CFire :public CObjectBase {
public:
	CFire(CVector3D *pos);
	~CFire();
	void Update();
	void Draw();

private:
	int m_cnt;	//ÇÌÇ©ÇÁÇÒ
};

#endif // !GIMMICK_GUARD