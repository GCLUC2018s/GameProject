#include "CEnemy.h"
const int FPS = 60;
void main(){
	for (int i = 0; i < 10; i++){
		//virtual�֐��͐e�N���X�Ɏg�p
		//�^�͐e�A���Ԃ͎q
		CTask *p = new CEnemy();
		p->Update();
		delete(p);
	}
	getchar();
}