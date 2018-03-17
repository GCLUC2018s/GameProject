#ifndef OHUDA_GUARD
#define OHUDA_GUARD

#include "../CItemBase/CItemBase.h"

class COhuda :public CItemBase {
public:
	COhuda(CVector3D *pos, bool * flipH);
	~COhuda();
	void Update();
	//“–‚½‚Á‚½‚Ìˆ—
	void Hit(CObjectBase * t);
};

#endif // !OHUDA_GUARD
