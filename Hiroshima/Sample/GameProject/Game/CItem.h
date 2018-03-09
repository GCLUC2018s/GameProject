#ifndef ITEM_GUARD
#define ITEM_GUARD

#include "CBase.h"

class CItem : public CBase {
public:
	CItem(CVector2D pos);
	~CItem();
	void Update();
};


#endif // !ITEM_GUARD
