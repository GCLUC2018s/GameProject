
#include "CTaskManager.h"
#include "CPlayer.h"
void main() {
	//一回だけの処理
	CTaskManager::m_instance = new CTaskManager();
	for (int i = 0; i < 10; i++) {
		new Player(i);
	}
	//ループ処理
	while (1) {
		CTaskManager::m_instance->Update();
	}
}