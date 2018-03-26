#ifndef CLEAVE_EFFECT_GUARD
#define CLEAVE_EFFECT_GUARD

#include "../CObjectBase/CEffectBase/CEffectBase.h"

/*

êªçÏÅ@âÕñÏ

*/


class CCleave :public CEffectBase {
public:
	CCleave(CVector2D pos);
	void Update();
	void Draw();
};

#endif // !CLEAVE_EFFECT_GUARD
