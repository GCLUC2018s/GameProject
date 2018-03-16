#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

#define MAGATAMA_POS_X 0

class CMagatama :public CObjectBase {
private:
	float m_kakera;
	int i;

public:
	CMagatama();
	~CMagatama();
	void Update();
	void Draw();
};

#endif // !MAGATAMA_GUARD