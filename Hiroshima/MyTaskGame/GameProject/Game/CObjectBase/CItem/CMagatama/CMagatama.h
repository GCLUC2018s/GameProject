#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

#define MAGATAMA_POS_X 0

class CMagatama :public CObjectBase {
public:
	CMagatama();
	~CMagatama();
	void Update();
};

#endif // !MAGATAMA_GUARD