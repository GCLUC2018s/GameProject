#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "object\C_Object.h"

class C_Collider : public C_Object{
public:
	static bool Collision(C_Object* ip_MyCol, C_Object* ip_YouCol, C_Vector3* ip_MyShadowCol, C_Vector3* ip_YouShadowCol);
	static bool CCollisionX(C_Object *ip_Col, const C_Object *ip_Col2); //¶‰EÕ“Ë”»’è,r1‚ÍÕ“Ë‚µ‚És‚­•û,r2‚ÍÕ“Ë‚³‚ê‚é•û
	static bool CCollisionY(C_Object *ip_Col, const C_Object *ip_Col2); //ã‰ºÕ“Ë”»’è,r1‚ÍÕ“Ë‚µ‚És‚­•û,r2‚ÍÕ“Ë‚³‚ê‚é•û
};
#endif