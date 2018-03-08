
#include "TaskManager.h"
#include "CPlayer.h"
void main() {
	//ˆê‰ñ‚¾‚¯‚Ìˆ—
	TaskManager::m_instance = new TaskManager();
	for (int i = 0; i < 10; i++) {
		new Player();
	}
	//ƒ‹[ƒvˆ—
	while (1) {
		TaskManager::m_instance->Update();
	}
}