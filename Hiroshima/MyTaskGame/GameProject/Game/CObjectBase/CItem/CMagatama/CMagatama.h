#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

#define MAGATAMA_POS_X 0
#define MAGATAMA_POS_Y 0

class CMagatama :public CObjectBase {
private:
	float m_kakera;
	int i;

public:
	CMagatama();
	~CMagatama();
	void Update();
	//“–‚½‚Á‚½‚Ìˆ—
	void Hit(CTask *t);
};

#endif // !MAGATAMA_GUARD