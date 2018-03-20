#ifndef OAGE_GUARD
#define OAGE_GUARD

#include "../CItemBase/CItemBase.h"

class COage :public CItemBase {
public:
	COage(CVector3D *pos);
	~COage();
	void Action(CObjectBase * a);
};

#endif // !OAGE_GUARD

