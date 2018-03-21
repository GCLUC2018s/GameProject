#ifndef PANCH_EFFECT_GUARD
#define PANCH_EFFECT_GUARD

#include "../CEffectBase/CEffectBase.h"

/*

êªçÏÅ@ã{˙±

*/

class CPlayer;

class CPanchEF :public CEffectBase {
public:
	CPanchEF(bool frip,CPlayer *pl,int anim_num);
	void Update();
private:
	CPlayer *PL;
};

#endif // !PANCH_EFFECT_GUARD
