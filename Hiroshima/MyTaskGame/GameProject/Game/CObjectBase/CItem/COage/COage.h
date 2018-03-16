#ifndef OAGE_GUARD
#define OAGE_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class COage :public CObjectBase {
public:
	COage(CVector3D *pos);
	~COage();
	void Update();
	void Draw();
	//当たった時の処理
	void Hit(CTask *t);
};

#endif // !OAGE_GUARD

