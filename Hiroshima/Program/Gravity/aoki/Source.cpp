#include"stdio.h"

const int  FPS = 60;

struct Vector3
{

	float x,y,z;

};

Vector3 Update(Vector3 pos, Vector3 speed, Vector3 gravity) {
	pos.x += speed.x + gravity.x;
	pos.y += speed.y + gravity.y;
	pos.z += speed.z + gravity.z;
	return pos;
}

void main(){
	Vector3 pos;   //PO�i�����ʒu�������āj
	pos.x = 2.0f;
	pos.y = 3.0f;
	pos.z = 4.0f;
	Vector3 speed; //��7�̓���
	speed.x = 1.6f;
	speed.y = 4.9f;
	speed.z = -2.5;
	Vector3 gravity;
	gravity.x = 0.0f;
	gravity.y = -9.8f;
	gravity.z = 0.0f;


	//�P�b
	for (int i = 0; i < 5*FPS; ++i) {
		pos = Update(pos, speed, gravity);
	}
	printf("%f %f %f", pos.x, pos.y, pos.z);
	getchar();
}

void Update() {

}

