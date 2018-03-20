#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "object\C_Object.h"

class C_Collider : public C_Object{
public:
	static bool Collision(C_Object* ip_MyCol, C_Object* ip_YouCol, C_Vector3* ip_MyShadowCol, C_Vector3* ip_YouShadowCol);
	static bool CCollisionX(C_Object *ip_Col, const C_Object *ip_Col2); //���E�Փ˔���,r1�͏Փ˂��ɍs����,r2�͏Փ˂�����
	static bool CCollisionY(C_Object *ip_Col, const C_Object *ip_Col2); //�㉺�Փ˔���,r1�͏Փ˂��ɍs����,r2�͏Փ˂�����
};
#endif