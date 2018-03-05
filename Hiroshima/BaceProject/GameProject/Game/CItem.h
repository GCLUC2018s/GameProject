#pragma once
#include "CBase.h"

class CItem :public CBase {
public:
	CItem(CVector2D pos);
	~CItem();
	void Update();
};
