#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "CBase.h"

/*

êßçÏé“Å@òZé‘Å@

*/

class CPlayer :public CBase {
public:
	CPlayer();
	~CPlayer();
	 void Update();
	 void Draw();
private:
	bool m_punch;
	int m_anim;
};

#endif // !PLAYER_GUARD