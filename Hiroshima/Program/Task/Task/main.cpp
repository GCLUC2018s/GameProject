
#include "TaskManager.h"
#include "CPlayer.h"
void main() {
	//��񂾂��̏���
	TaskManager::m_instance = new TaskManager();
	for (int i = 0; i < 10; i++) {
		new Player();
	}
	//���[�v����
	while (1) {
		TaskManager::m_instance->Update();
	}
}