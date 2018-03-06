#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "CRectangle.h"
#include "CVector2.h"
class CCollision{
public:
	CRectangle *mptas;
	CVector2 mPosition;
	float mRadus;
	static bool CircleCollision(CCollision *p1,CCollision *p2);
	static bool CollisionX(CRectangle *r1, CRectangle &r2);
	static bool CollisionY(CRectangle *r1, CRectangle &r2);
};
#endif