#ifndef GIMMICK_GUARD
#define GIMMICK_GUARD

#include "../CObjectBase.h"
/*

����ҁ@�͖�

*/

class CFire :public CObjectBase {
public:
	CFire(CVector3D *pos);
	~CFire();
	void Update();
	void Draw();

private:
	int m_cnt;	//�킩���
};

#endif // !GIMMICK_GUARD