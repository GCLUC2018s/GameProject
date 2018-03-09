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
	bool m_jump;
	int m_anim;
	int y;
};

#endif // !PLAYER_GUARD