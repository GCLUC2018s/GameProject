#ifndef Charge_EFFECT_GUARD
#define Charge_EFFECT_GUARD

#include "../CObjectBase/CEffectBase/CEffectBase.h"

/*

êªçÏÅ@âÕñÏ

*/


class CCharge :public CEffectBase {
public:
	CCharge(CVector2D pos);
	void Update();
	void Draw();
};

#endif // !Charge_EFFECT_GUARD
