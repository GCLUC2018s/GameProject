#ifndef KAKERA_GUARD
#define KAKERA_GUARD

#include "../CItemBase/CItemBase.h"

class CKakera :public CItemBase {

public:
	CKakera(CVector3D * pos);
	~CKakera();
	void Draw();
};

#endif // !KAKERA_GUARD