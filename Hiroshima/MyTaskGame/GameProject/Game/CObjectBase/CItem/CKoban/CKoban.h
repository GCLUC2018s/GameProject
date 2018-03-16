#ifndef KOBAN_GUARD
#define KOBAN_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CKoban :public CObjectBase {
public:
	CKoban(CVector3D *pos);
	~CKoban();
	void Update();
	void Draw();
	//当たった時の処理
	void Hit(CTask *t);
};

#endif // !KOBAN_GUARD