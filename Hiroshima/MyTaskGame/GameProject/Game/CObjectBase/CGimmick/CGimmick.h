#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CObjectBase.h"
/*

����ҁ@�͖�

*/

class CGimmick :public CObjectBase {
public:
	CGimmick(CVector3D *pos);
	~CGimmick();
	void Update();
	void Draw();

private:
	int m_cnt;	//�킩���
};

#endif // !GIMMICK_GUARD