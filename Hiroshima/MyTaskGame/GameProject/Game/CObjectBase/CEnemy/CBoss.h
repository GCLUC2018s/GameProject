#ifndef BOSSGUAD
#define BOSSGUAD

#include"../CObjectBase.h"
/*

製作者　青木

*/
class CBoss :public CObjectBase {
public:
	CBoss(CVector2D *pos);
	~CBoss();
	void Update();
};




#endif // !EBEMY1GUAD
