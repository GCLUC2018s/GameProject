#pragma once
#ifndef EBEMY1GUAD
#define EBEMY1GUAD

#include "CBase.h"
/*

����ҁ@��

*/
class CEnemy1 :public CBase {
public:
	CEnemy1(CVector2D pos);
	~CEnemy1();
	virtual void Update();
};




#endif // !EBEMY1GUAD