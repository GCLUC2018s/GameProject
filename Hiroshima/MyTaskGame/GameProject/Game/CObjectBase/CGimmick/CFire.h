#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CEffectBase/CEffectBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CFire :public CEffectBase {
public:
	CFire(CObjectBase *ob);
	~CFire();
	void Update();
private:
	CObjectBase *OB;
};

#endif // !GIMMICK_GUARD