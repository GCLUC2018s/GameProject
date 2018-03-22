#ifndef EFFECT_GUARD
#define EFFECT_GUARD

#include "../CObjectBase.h"

/*

制作　宮﨑

*/

enum {
	eFire,
	ePanch,
	eBress,
};

class CEffectBase :public CObjectBase {
public:
	CEffectBase();
	virtual void Update();
	virtual void Draw();
	//1以上なら判定できる
	float GetHit() {
		return m_color.w;
	};
	int GetEFtype() {
		return m_effect_type;
	};
protected:
	int m_effect_type;	//エフェクトの種類
};

#endif // !EFFECT_GUARD
