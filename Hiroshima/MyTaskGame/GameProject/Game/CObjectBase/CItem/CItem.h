#ifndef ITEM_GUARD
#define ITEM_GUARD

#include "../CObjectBase.h"

class CItem :public CObjectBase {
public:
	CItem(CVector3D *pos);
	~CItem();
	void Update();
};

#endif // !ITEM_GUARD
