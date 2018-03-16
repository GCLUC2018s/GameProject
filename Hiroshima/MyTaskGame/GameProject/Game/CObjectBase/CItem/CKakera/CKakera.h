#ifndef KAKERA_GUARD
#define KAKERA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CKakera :public CObjectBase {

public:
	CKakera(CVector3D * pos);
	~CKakera();
	void Update();
	void Draw();
	//�����������̏���
	void Hit(CTask *t);
};

#endif // !KAKERA_GUARD