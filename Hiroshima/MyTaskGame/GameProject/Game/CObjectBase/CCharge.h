#ifndef Charge_EFFECT_GUARD
#define Charge_EFFECT_GUARD

#include "../CObjectBase/CEffectBase/CEffectBase.h"

/*

����@�͖�

*/


class CCharge :public CEffectBase {
public:
	CCharge(CVector2D pos,bool flag);
	void Update();
	void Draw();
private:
	bool m_flag;
};

#endif // !Charge_EFFECT_GUARD
