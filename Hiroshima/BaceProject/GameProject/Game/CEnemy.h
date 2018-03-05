#pragma once
#include "CBase.h">

class CEnemy :public CBase {
private:
	int m_state;
	int m_cnt;
	int m_bull_cnt;
public:
	CEnemy(CVector2D pos);
	virtual void Update();
	void HitCallback(CBase* b);
};
