#include"math.h"
#include"stdio.h"

const int     FPS = 60;

struct Vector3
{
	float x, y, z;
};
Vector3 Update(Vector3 pos, Vector3 speed, Vector3 gravity);
void main()
{
	Vector3 pos =
	{ 2.0f, 3.0f, 4.0f };
	Vector3 speed =
	{ 1.6f,28.9f , -2.5f };
	Vector3 gravity =
	{ 0.0f, -9.8f, 0.0f };

	//5•b
	for (int i = 0; i < 5 * FPS; ++i){
		pos = Update(pos, speed, gravity);
	}
	printf("%f pos.x,%f pos,y,%f pos.z,",speed.x,speed.y,speed.z);
	getchar();
}
Vector3 Update(Vector3 pos, Vector3 speed, Vector3 gravity){
	return pos;
}