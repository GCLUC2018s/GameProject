#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "CBase.h"
/*

����ҁ@�͖�

*/

class CGimmick :public CBase {
public:
	CGimmick(CVector2D pos);
	~CGimmick();
	void Update();
};

#endif // !GIMMICK_GUARD