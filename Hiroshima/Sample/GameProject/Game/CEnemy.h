#pragma once
#include "CBase.h"

class CEnemy :public CBase {
public:
	CEnemy();
	~CEnemy();
	virtual void Update();
};