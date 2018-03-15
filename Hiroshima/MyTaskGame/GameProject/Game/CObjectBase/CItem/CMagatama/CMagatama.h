#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CMagatama :public CObjectBase {
public:
	CMagatama();
	~CMagatama();
	void Update();
};

#endif // !MAGATAMA_GUARD