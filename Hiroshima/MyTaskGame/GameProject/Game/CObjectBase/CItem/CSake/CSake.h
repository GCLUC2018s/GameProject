#ifndef SAKE_GUARD
#define SAKE_GUARD
#include "../CItemBase/CItemBase.h"

class CSake :public CItemBase {
public:
	CSake(CVector3D *pos);
	~CSake();
	void Action(CObjectBase * a);
};

#endif // !SAKE_GUARD