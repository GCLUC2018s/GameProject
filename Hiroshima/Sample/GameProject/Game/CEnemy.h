#pragma once
#include "CBase.h"
/*

»ìÒ@Â–Ø

*/
class CEnemy :public CBase {
public:
	CEnemy(CVector2D pos);
	~CEnemy();
	virtual void Update();
};