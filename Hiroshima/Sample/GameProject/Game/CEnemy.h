#pragma once
#include "CBase.h"
/*

����ҁ@��

*/
class CEnemy :public CBase {
public:
	CEnemy(CVector2D pos);
	~CEnemy();
	virtual void Update();
};