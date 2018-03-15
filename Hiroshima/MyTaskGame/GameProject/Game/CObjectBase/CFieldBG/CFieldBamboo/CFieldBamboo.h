#ifndef FIELDBAMBOO_GUARD
#define FIELDBAMBOO_GUARD

#include"../GameProject/Game/CObjectBase/CObjectBase.h"

/*

製作者　六車

*/
class CFieldBamboo :public CObjectBase {
public:
	CFieldBamboo(const bool flag); //竹。trueなら画面右外に生成
	~CFieldBamboo();
	void Draw();
private:
};

#endif // !FIELDBAMBOO_GUARD
