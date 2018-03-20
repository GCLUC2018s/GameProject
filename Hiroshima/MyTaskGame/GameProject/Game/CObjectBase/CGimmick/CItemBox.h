#ifndef ITEMBOX_GUARD
#define ITEMBOX_GUARD

#include "../GameProject/Game/CObjectBase/CItem/CItemBase/CItemBase.h"
/*

êªçÏé“Å@âÕñÏ

*/

class CItemBox :public CItemBase {
public:
	CItemBox(CVector3D *pos, int state);
	~CItemBox();
	void	Update();
	void Hit(CObjectBase * t);
	void Draw();
private:
	bool	m_break;
	int		m_cnt;
};

#endif // !ITEMBOX_GUARD
