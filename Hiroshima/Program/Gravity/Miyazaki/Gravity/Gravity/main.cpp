#include "stdio.h"
const int FPS = 60;
struct Vector3
{
	float x, y, z;
};

void Update(Vector3& u_pos, Vector3& u_speed, const Vector3 u_gravity,float deltatime) {
	//そくど
	u_speed.x += u_gravity.x * deltatime;
	u_speed.z += u_gravity.z * deltatime;
	u_speed.y += u_gravity.y * deltatime;

	//位置
	u_pos.x += u_speed.x * deltatime;
	u_pos.z += u_speed.z * deltatime;
	u_pos.y += u_speed.y * deltatime;
}

void main() {
	Vector3 pos;	//P0（初期位置を代入して）
	pos.x = 2.0f, pos.y = 3.0f, pos.z = -4.0f;
	Vector3 speed;
	speed.x = 1.6f;
	speed.y = 4.9f;
	speed.z = -2.5f;
	//speed.x = pos1.x - pos.x;
	//speed.y = pos1.y - pos.y;
	//speed.z = pos1.z - pos.z;
	Vector3 gravity;
	gravity.x = 0.0f, gravity.y = -9.8f, gravity.z = 0.0f;

	for (int i = 0; i < 5 * FPS; i++) {
		Update(pos, speed, gravity, 1.0f / (float)FPS);
	}
	printf("%f,%f,%f", pos.x, pos.y, pos.z);
	getchar();
}

