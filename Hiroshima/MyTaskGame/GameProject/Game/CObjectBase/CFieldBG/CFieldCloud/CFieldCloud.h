#ifndef FIELDCLOUD_GUARD
#define FIELDCLOUD_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

/*

製作者　六車

*/
class CFieldCloud :public CObjectBase {
public:
	CFieldCloud(const bool flag);	//雲。trueなら画面右外に生成
	~CFieldCloud();
	void Draw();
private:
};

#endif // !FIELDCLOUD_GUARD