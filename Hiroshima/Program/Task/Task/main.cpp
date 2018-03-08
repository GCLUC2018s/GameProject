
#include "CTaskManager.h"
#include "CPlayer.h"
void main() {
	//ˆê‰ñ‚¾‚¯‚Ìˆ—
	CTaskManager::m_instance = new CTaskManager();
	for (int i = 0; i < 10; i++) {
		new Player(i);
	}
	//ƒ‹[ƒvˆ—
	while (1) {
		CTaskManager::m_instance->Update();
	}
}