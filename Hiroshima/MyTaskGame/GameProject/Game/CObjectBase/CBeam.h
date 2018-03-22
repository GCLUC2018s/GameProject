#ifndef Beam_EFFECT_GUARD
#define Beam_EFFECT_GUARD

#include "../CObjectBase/CEffectBase/CEffectBase.h"

/*

êªçÏÅ@âÕñÏ

*/


class CBeam :public CEffectBase {
public:
	CBeam(CVector2D pos);
	void Update();
	void Draw();
};

#endif // !Beam_EFFECT_GUARD

