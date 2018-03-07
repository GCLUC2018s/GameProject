#include "CEnemy.h"
const int FPS = 60;
void main(){
	for (int i = 0; i < 10; i++){
		//virtual関数は親クラスに使用
		//型は親、実態は子
		CTask *p = new CEnemy();
		p->Update();
		delete(p);
	}
	getchar();
}