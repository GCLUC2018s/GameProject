
#include "TaskManager.h"
#include "CPlayer.h"
void main() {
	//��񂾂��̏���
	TaskManager::m_instan = new TaskManager();
	for (int i = 0; i < 10; i++) {
		new Player();
	}
	//���[�v����
	while (1) {
		TaskManager::m_instan->Update();
	}
}