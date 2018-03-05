#pragma once
#include "CBase.h"

class CBullet :public CBase {
private:
	int m_type = 0;
public:
	CBullet(int type,CVector2D pos,CVector2D vec);
	~CBullet();
	void Update();
	void HitCallback(CBase * b);
};