#ifndef BOSSGUARD
#define BOSSGUARD

#include"../CObjectBase.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
class CBoss :public CObjectBase {
public:
	CBoss(CVector3D *pos);
	~CBoss();
	void Update();
};




#endif // !EBEMY1GUARD
