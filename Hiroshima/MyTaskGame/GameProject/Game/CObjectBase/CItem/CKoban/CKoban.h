#ifndef KOBAN_GUARD
#define KOBAN_GUARD

#include "../CItemBase/CItemBase.h"

class CKoban :public CItemBase {
public:
	CKoban(CVector3D *pos);
	~CKoban();
};

#endif // !KOBAN_GUARD