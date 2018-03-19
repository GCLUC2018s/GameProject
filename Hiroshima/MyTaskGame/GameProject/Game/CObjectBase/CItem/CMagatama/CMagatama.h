#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

#define MAGATAMA_POS_X 0
#define MAGATAMA_POS_Y 0

class CMagatama :public CObjectBase {
private:
	int m_cnt;

public:
	CMagatama();
	~CMagatama();
	void Update();
	void Draw();
	//“–‚½‚Á‚½‚Ìˆ—
	void Hit(CObjectBase *t);
	//•KE‹Z”­“®
	void SetAttack();
};

#endif // !MAGATAMA_GUARD