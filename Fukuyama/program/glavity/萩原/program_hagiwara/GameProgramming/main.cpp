#include <stdio.h>
#include "math.h"

const int FPS = 60;

class Vector3
{
public:
	float x, y, z;
};

Vector3 Update(Vector3& pos, Vector3& speed, const Vector3& gravity,float deltatime)
{
	speed.x += gravity.x*deltatime;
	speed.y += gravity.y*deltatime;
	speed.z += gravity.z*deltatime;

	pos.x += speed.x*deltatime;
	pos.y += speed.y*deltatime;
	pos.z += speed.z*deltatime;

	printf("最終結果（%f,%f,%f)    ", pos.x, pos.y, pos.z);
	printf("デルタタイム    %f\n", deltatime);

	return pos;
}

void main(){
	Vector3 pos1 = { 2.0f, 3.0f, 4.0f };
	Vector3 speed = { 1.6f, 24.9f, -2.5f };
	Vector3 gravity = { 0.0f, -9.8f, 0.0f };

	for (int i = 0; i < 5 * FPS; ++i){
		pos1 = Update(pos1, speed, gravity,1.0f/FPS);
	}

	getchar();
}