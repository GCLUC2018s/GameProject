#ifndef CCOLLIDER_H
#define CCOLLIDER_H
#include "object\C_Object.h"

//ボックスxボックスのあたり判定
class C_BoxCollider{
public:
	static bool CCollisionX(C_Rectangle *mp_R1, const C_Rectangle &i_R2); //左右衝突判定,r1は衝突しに行く方,r2は衝突される方
	static bool CCollisionY(C_Rectangle *mp_R1, const C_Rectangle &i_R2); //上下衝突判定,r1は衝突しに行く方,r2は衝突される方
};
#endif