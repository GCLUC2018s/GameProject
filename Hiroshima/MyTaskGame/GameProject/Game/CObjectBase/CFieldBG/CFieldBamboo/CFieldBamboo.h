#ifndef FIELDBAMBOO_GUARD
#define FIELDBAMBOO_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

/*

����ҁ@�Z��

*/
class CFieldBamboo :public CObjectBase {
public:
	CFieldBamboo(const bool flag); //�|�Btrue�Ȃ��ʉE�O�ɐ���
	~CFieldBamboo();
	void Draw();
private:
};

#endif // !FIELDBAMBOO_GUARD
