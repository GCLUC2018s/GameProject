#include <math.h>
#include <stdio.h>
#include <string.h>
const int FPS = 60;
class  Vector3
{
public:
	float x, y, z;
};
void  Update(){
	
}
void main(){
	Vector3 pos = { 0.0f, 0.0f, 0.0f };
		for (int i = 0; i < 5; i++){
			Vector3 pos1 = { 2.0f, 3.0f, 4.0f };   //P0(‰ŠúˆÊ’u‚ð‘ã“ü)(P0 2.0f,3.0f,4.0f)
			Vector3 pos2 = { 10.0f, 5.0f, -8.5f }; //P1(‰ŠúˆÊ’u10.0f,5.0f,-8.5f)
			Vector3 gravity = { 0.0f, -9.8f, 0.0f }; //d—Í(0.0f,-9.8f,0.0f)
			pos.x = (pos2.x - pos1.x) / 5;
			pos.z = (pos2.z - pos1.z) / 5;
			pos.y = pos1.y + pos2.y * 5 + 1 / 2 * gravity.y*(5 ^ 2);
			printf(" %f\n %f\n %f", pos.x, pos.y, pos.z);
			getchar();
		}
}