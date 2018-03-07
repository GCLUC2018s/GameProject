#include "stdio.h"
#include<math.h>

const int FPS = 60;

struct Vector3 {
	float x, y, z;
};

Vector3 Update(Vector3 &pos, Vector3 &speed, Vector3 &gravity,float t) {
	pos.x += speed.x;
	pos.y += speed.y + gravity.y*pow(t,2) / 2;
	pos.z += speed.z;
	speed.y += gravity.y*t;
	return pos;
}

void main() {
	Vector3 pos;
	pos.x = 2.0f;
	pos.y = 3.0f;
	pos.z = 4.0f;
	Vector3 speed;
	speed.x = (10-2)/5;
	speed.y = 24.9f;
	speed.z = -2.5f;
	Vector3 gravity;
	gravity.x = 0.0f;
	gravity.y = -9.8f;
	gravity.z = 0.0f;
	//1•b
	for (int i = 0; i < 5; ++i) {
		pos = Update(pos, speed, gravity,float(FPS));
	}
	printf("%f %f %f", pos.x, pos.y, pos.z);
	getchar();
}