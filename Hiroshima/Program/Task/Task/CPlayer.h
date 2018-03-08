#ifndef PLYER_GUARD
#define PLYER_GUARD

#include "CTask.h"
#include "CTask.h"

class Player : public CTask
{
public:
	Player(int i);
	void Update() {
		printf("player%d\n",m_num);
		if (m_num == 4) {
			m_kill = true;
		}
	};

};
#endif // !PLYER_GUARD