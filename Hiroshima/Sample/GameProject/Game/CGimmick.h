#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "CBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CGimmick :public CBase {
public:
	CGimmick(CVector2D pos);
	~CGimmick();
	void Update();
};

#endif // !GIMMICK_GUARD