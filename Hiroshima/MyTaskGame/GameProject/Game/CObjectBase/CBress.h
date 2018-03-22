#ifndef Bress_EFFECT_GUARD
#define Bress_EFFECT_GUARD

#include "../CObjectBase/CEffectBase/CEffectBase.h"

/*

êªçÏÅ@âÕñÏ

*/


class CBress :public CEffectBase {
public:
	CBress(CVector2D pos);
	void Update();
	void Draw();
};

#endif // !Bress_EFFECT_GUARD

