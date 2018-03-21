#ifndef MG_HIT_GUARD
#define MG_HIT_GUARD

#include "../CObjectBase.h"

/*

êªçÏÅ@ã{˙±

*/


class CMGHit :public CObjectBase {
public:
	CMGHit(CVector3D &pos);
	~CMGHit();
	void Update();
	void Draw();
	void Hit(CObjectBase * t);
private:
	int m_time;
	int m_size;
};
#endif // !MG_HIT_GUARD
