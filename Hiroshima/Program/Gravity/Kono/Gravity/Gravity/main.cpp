#include "stdio.h"

const int FPS = 60;

struct Vector3 {
	float x, y, z;
};

Vector3 Update( Vector3 pos, Vector3 speed, Vector3 gravity, float time) {
	//‘¬“x
	//ˆÊ’u
	pos.x += speed.x * time;
	pos.y += speed.y * time + (gravity.y * time ) / 2;
	pos.z += speed.z * time;
	return pos;
}

void main() {
	Vector3 pos;
	pos.x = 2.0f;
	pos.y = 3.0f;
	pos.z = 4.0f;
	Vector3 speed;
	speed.x = 1.6f;
	speed.y = 4.9f;
	speed.z = -2.5f;
	Vector3 gravity;
	gravity.x = 0.0f;
	gravity.y = -9.8f;
	gravity.z = 0.0f;
	//1•b
	for (int i = 0; i < 5 * FPS ; ++i) {
		pos = Update(pos, speed, gravity, 1.0f / (float)FPS);
	}
	printf("%f %f %f", pos.x, pos.y, pos.z);
	getchar();
}

