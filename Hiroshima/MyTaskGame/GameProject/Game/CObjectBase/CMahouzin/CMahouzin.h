#ifndef MAHOUZIN_GUARD
#define MAHOUZIN_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

class CMahouzin :public CObjectBase {
public:
	CMahouzin();
	~CMahouzin();
	void Update();
private:
	int m_time;

};


#endif // !MAHOUZIN_GUARD
