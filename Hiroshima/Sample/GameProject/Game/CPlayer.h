#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "CBase.h"

/*

����ҁ@�Z�ԁ@

*/

class CPlayer :public CBase {
public:
	CPlayer();
	~CPlayer();
	 void Update();
	 void Draw();

};

#endif // !PLAYER_GUARD