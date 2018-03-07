#ifndef PLYER_GUARD
#define PLYER_GUARD

#include "Task.h"

class Player : public Task
{
public:
	void Update() {
		printf("player\n");
	};

};
#endif // !PLYER_GUARD