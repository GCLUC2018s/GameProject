#ifndef FIELDSKY_GUARD
#define FIELDSKY_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

/*

êßçÏé“Å@òZé‘

*/
class CFieldSky :public CObjectBase {
public:
	CFieldSky();
	~CFieldSky();
	void Update();
	void Draw();
private:
	CAnimImage m_img_2;
};
#endif // !FIELDSKY_GUARD