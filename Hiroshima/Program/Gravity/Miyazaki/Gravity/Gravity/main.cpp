#include "stdio.h"
#include <math.h>
const int FPS = 60;
struct Vector3
{
	float x, y, z;
};

void Update(Vector3& pos, Vector3& speed, Vector3 &gravity,float deltatime) {
	pos.x += speed.x;
	pos.y += speed.y;// + gravity.y * pow(deltatime, 2) / 2;
	pos.z += speed.z;
	speed.y -= gravity.y * deltatime;
}

void main() {
	int time = 5;
	Vector3 pos;	//P0（初期位置を代入して）
	pos.x = 2.0f;
	pos.y = 3.0f;
	pos.z = 4.0f;
	Vector3 pos1;	//P1
	pos1.x = 10.0f;
	pos1.y = 5.0f;
	pos1.z = -8.5f;
	Vector3 gravity;
	gravity.x = 0.0f;
	gravity.y = 9.8f;
	gravity.z = 0.0f;
	Vector3 speed;
	speed.x = 1.6f;
	speed.y = 24.9f;
	speed.z = -2.5f;
	//speed.x = (pos1.x - pos.x) / time;
	//speed.y = ((pos1.y - pos.y) + ((gravity.y * (time * time)) / 2)) / time;
	//speed.z = (pos1.z - pos.z) / time;

	for (int i = 0; i < time; i++) {
		Update(pos, speed, gravity, i);
		printf("%d秒後　%f,%f,%f\n", i, pos.x, pos.y, pos.z);
	}
	getchar();
}

