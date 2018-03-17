#ifndef ITEM_BASE_GUARD
#define ITEM_BASE_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CItemBase :public CObjectBase {
public:
	CItemBase(CVector3D *pos);
	~CItemBase();
	void Update();
	void Draw();
	//“–‚½‚Á‚½‚Ìˆ—
	void Hit(CObjectBase * t);
};

#endif // !ITEM_BASE_GUARD
