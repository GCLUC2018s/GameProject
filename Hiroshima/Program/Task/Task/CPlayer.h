#ifndef PLYER_GUARD
#define PLYER_GUARD

#include "Task.h"
#include "Task.h"

class Player : public Task
{
public:
	Player(int i);
	void Update() {
		printf("player%d\n",m_num);
		if (m_num == 4) {
			m_kill = true;
		}
	};
private:
	int m_num;

};
#endif // !PLYER_GUARD