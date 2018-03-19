#ifndef OHUDA_GUARD
#define OHUDA_GUARD

#include "../../CObjectBase.h"

class COhuda :public CObjectBase {
private:
	int m_cnt;
public:
	COhuda(CVector3D *pos, bool * flipH);
	~COhuda();
	void Update();
	void Draw();
	//�����������̏���
	void Hit(CObjectBase * t);
};

#endif // !OHUDA_GUARD
