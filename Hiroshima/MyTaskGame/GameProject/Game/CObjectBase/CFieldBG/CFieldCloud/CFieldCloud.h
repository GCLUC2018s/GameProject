#ifndef FIELDCLOUD_GUARD
#define FIELDCLOUD_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

/*

����ҁ@�Z��

*/
class CFieldCloud :public CObjectBase {
public:
	CFieldCloud(const bool flag);	//�_�Btrue�Ȃ��ʉE�O�ɐ���
	~CFieldCloud();
	void Draw();
private:
};

#endif // !FIELDCLOUD_GUARD