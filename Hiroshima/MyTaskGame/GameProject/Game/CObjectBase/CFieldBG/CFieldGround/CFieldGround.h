#ifndef FIELDGROUND_GUARD
#define FIELDGROUND_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

class CPlayer;

/*

»ìÒ@ZÔ
ÒW@@{ú±

*/

class CFieldGround : public CObjectBase {
public:
	CFieldGround(const bool flag);	//nÊBtrueÈçæÊEOÉ¶¬
	~CFieldGround();
	void Update();
	void Draw();
private:
	//CRect m_rect_tourou1;
	//CRect m_rect_tourou2;
	//CRect m_rect_tourou3;
	//CRect m_rect_tourou4;
	
	
	bool m_flag;
};

#endif // !FIELDGROUND_GUARD
