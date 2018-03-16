#ifndef ITEMBOX_GUARD
#define ITEMBOX_GUARD

#include "../CObjectBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CItemBox :public CObjectBase {
public:
	CItemBox(CVector3D *pos, int state);
	~CItemBox();
	void	Update();
	void	Draw();
private:
	bool	m_break;
	int		m_cnt;
};

#endif // !ITEMBOX_GUARD
