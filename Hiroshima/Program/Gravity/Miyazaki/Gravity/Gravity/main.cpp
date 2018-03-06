#include "stdio.h"
const int FPS = 60;
struct Vector3
{
	float x, y, z;
};

Vector3 Update(Vector3 u_pos, Vector3 u_speed, Vector3 u_gravity,float deltatime) {
	//そくど
	u_speed.x += u_gravity.x * deltatime;
	u_speed.z += u_gravity.z * deltatime;
	u_speed.y += u_gravity.y * deltatime;

	//位置
	u_pos.x += u_speed.x * deltatime;
	u_pos.z += u_speed.z * deltatime;
	u_pos.y += u_speed.y * deltatime;

	return u_pos;
}

void main() {
	Vector3 pos;	//P0（初期位置を代入して）
	pos.x = 2.0, pos.y = 3.0, pos.z = -4.0;
	Vector3 pos1;	//P1（初期位置を代入して）
	pos1.x = 10.0, pos1.y = 5.0, pos1.z = -8.5;
	Vector3 speed;
	speed.x = pos1.x - pos.x;
	speed.y = pos1.y - pos.y;
	speed.z = pos1.z - pos.z;
	Vector3 gravity;
	gravity.x = 0.0, gravity.y = 9.8, gravity.z = 0.0;
	Vector3 an_pos;

	for (int i = 0; i < 5 * FPS; i++) {
		an_pos = Update(pos, speed, gravity, 1.0f / (float)FPS);
	}
	printf("%f,%f,%f", an_pos.x, an_pos.y, an_pos.z);
	getchar();
}

