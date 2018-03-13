#ifndef GIMMICK2_GUARD
#define GIMMICK2_GUARD

#include "../CObjectBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CGimmick2 :public CObjectBase {
public:
	CGimmick2(CVector3D *pos);
	~CGimmick2();
	void Update();
private:
	int m_cnt;
};

#endif // !GIMMICK2_GUARD
