#ifndef ITEM_BASE_GUARD
#define ITEM_BASE_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CItemBase :public CObjectBase {
public:
	CItemBase(CVector3D *pos);
	~CItemBase();
	void Update();
	void Draw();
	//当たった時の処理
	virtual void Hit(CObjectBase * t);
protected:
	int m_time;		//くるくる回る時間
	bool m_get;		//trueならゲットされた
	void Vanush();	//消える処理
	virtual void Action(CObjectBase * a);
};

#endif // !ITEM_BASE_GUARD
