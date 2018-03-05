#pragma once
#include "CBase.h"

class CGimmick :public CBase {
public:
	CGimmick(CVector2D pos);
	~CGimmick();
	virtual void Update();
};
