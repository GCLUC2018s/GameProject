#ifndef ITEMBOX_GUARD
#define ITEMBOX_GUARD

#include "../CObjectBase.h"
/*

����ҁ@�͖�

*/

class CItemBox :public CObjectBase {
public:
	CItemBox(CVector3D *pos);
	~CItemBox();
	void Update();
	void Draw();

private:
};

#endif // !ITEMBOX_GUARD
