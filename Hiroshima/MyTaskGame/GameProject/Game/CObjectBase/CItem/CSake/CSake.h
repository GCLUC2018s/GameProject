#ifndef SAKE_GUARD
#define SAKE_GUARD
#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CSake :public CObjectBase {
public:
	CSake(CVector3D *pos);
	~CSake();
	void Update();
};

#endif // !SAKE_GUARD