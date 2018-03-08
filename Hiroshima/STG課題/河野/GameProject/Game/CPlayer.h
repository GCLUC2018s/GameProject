#ifndef PLYER_GUARD
#define PLYER_GUARD

#include "../Task/CTask.h"

class CPlayer : public CTask{
public:
	CPlayer();
	void Update();
	void Draw();
};
#endif // !PLYER_GUARD
