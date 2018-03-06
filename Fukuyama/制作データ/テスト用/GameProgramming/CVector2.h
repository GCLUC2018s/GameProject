#ifndef CVECTOR2_H
#define CVECTOR2_H
#include "math.h"
class CVector2{
public:
	//コンストラクタで未初期化を防ぐ
	CVector2()
		:x(0.0f)
		, y(0.0f)
	{}
	float x;
	float y;
	float Lenght();
	const CVector2 operator+(const CVector2 &v)const;
	const CVector2 operator-(const CVector2 &v)const;
	CVector2(float x,float y)
		:x(x)
		, y(y)
	{}
};
#endif