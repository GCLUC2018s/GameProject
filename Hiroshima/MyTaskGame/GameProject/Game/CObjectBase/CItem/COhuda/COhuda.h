#ifndef OHUDA_GUARD
#define OHUDA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class COhuda :public CObjectBase {
public:
	COhuda(CVector3D *pos);
	~COhuda();
	void Update();
};

#endif // !OHUDA_GUARD
