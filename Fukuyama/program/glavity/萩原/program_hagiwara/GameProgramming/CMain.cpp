#include "math.h"
#include <stdio.h>
#include "glut.h"

const int FPS = 60;

struct Vector3
{
	float x, y, z;
};

Vector3 Update(Vector3 pos, Vector3 speed, Vector3 gravity)
{
	return pos;
}

void main(){
	Vector3 pos = { 2.0f, 3.0f, 4.0f };
	Vector3 speed = {1.6f,28.9f,-2.5f};
	Vector3 gravity{ 0.0f, -9.8f, 0.0f };

	for (int i = 0; i < 5 * FPS; ++i){
		pos = Update(pos, speed, gravity);
	}

	printf("%d",pos.x, pos.y, pos.z);
}