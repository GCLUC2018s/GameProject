#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CEffectBase/CEffectBase.h"
/*

����ҁ@�͖�

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