#pragma once
#include "CBase.h"
/*

製作者　青木

*/
class CEnemy :public CBase {
public:
	CEnemy(CVector2D pos);
	~CEnemy();
	virtual void Update();
};