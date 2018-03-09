#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "../Task/CTask.h"

class CPlayer : public CTask{
public:
	CPlayer();
	void Update();
	void Draw();
};
#endif // !PLAYER_GUARD
