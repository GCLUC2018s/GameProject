
#include "CTaskManager.h"
#include "CPlayer.h"
void main() {
	//��񂾂��̏���
	CTaskManager::m_instance = new CTaskManager();
	for (int i = 0; i < 10; i++) {
		new Player(i);
	}
	//���[�v����
	while (1) {
		CTaskManager::m_instance->Update();
	}
}