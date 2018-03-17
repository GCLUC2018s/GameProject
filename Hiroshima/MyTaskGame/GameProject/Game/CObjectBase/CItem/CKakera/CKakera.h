#ifndef KAKERA_GUARD
#define KAKERA_GUARD

#include "../CItemBase/CItemBase.h"

class CKakera :public CItemBase {

public:
	CKakera(CVector3D * pos);
	~CKakera();
	void Hit(CObjectBase * t);
};

#endif // !KAKERA_GUARD