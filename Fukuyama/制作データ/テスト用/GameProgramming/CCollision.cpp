#include "CCollision.h"
bool CCollision::CollisionX(CRectangle *r1, CRectangle &r2){
	r1->mAjust = 0.0f;
	if (r1->mEnabled&&r2.mEnabled){
		if (r1->mLeft >= r2.mRight ||
			r1->mRight<=r2.mLeft ||
			r1->mBottom>=r2.mTop ||
			r1->mTop <= r2.mBottom){
			return false;
		}
		if (r2.mLeft < r1->mLeft){
			r1->mAjust = r2.mRight - r1->mLeft;
			r2.mAjust = -r1->mAjust;
			return true;
		}
		if (r2.mRight>r1->mRight){
			r1->mAjust = r2.mLeft - r1->mRight;
			r2.mAjust = -r1->mAjust;
			return true;
		}
	}
	return false;
}
bool CCollision::CollisionY(CRectangle *r1, CRectangle &r2){
	r1->mAjust = 0.0f;
	if (r1->mEnabled&&r2.mEnabled){
		if (r1->mLeft >= r2.mRight ||
			r1->mRight <= r2.mLeft ||
			r1->mBottom >= r2.mTop ||
			r1->mTop <= r2.mBottom){
			return false;
		}
		if (r2.mBottom < r1->mBottom){
			r1->mAjust = r2.mTop - r1->mBottom;
			r2.mAjust = -r1->mAjust;
			return true;
		}
		if (r2.mTop>r1->mTop){
			r1->mAjust = r2.mBottom - r1->mTop;
			r2.mAjust = -r1->mAjust;
			return true;
		}
	}
	return false;
}
bool CCollision::CircleCollision(CCollision *p1, CCollision *p2){
	CVector2 pos1 = p1->mptas  p1->mPosition;
	CVector2 pos2=p2->mptas
}