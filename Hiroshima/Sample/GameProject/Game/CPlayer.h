#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "CBase.h"

/*

制作者　六車　

*/

class CPlayer :public CBase {
public:
	CPlayer();
	~CPlayer();
	virtual void Update();
};

#endif // !PLAYER_GUARD