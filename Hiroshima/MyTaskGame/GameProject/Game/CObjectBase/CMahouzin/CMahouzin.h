#ifndef MAHOUZIN_GUARD
#define MAHOUZIN_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

/*

êßçÏÅ@òZé‘

*/

class CPlayer;

class CMahouzin :public CObjectBase {
public:
	CMahouzin();
	~CMahouzin();
	void Update();
	void Draw();
private:
	int m_time;
	int m_size;
	CPlayer *PL;

};


#endif // !MAHOUZIN_GUARD
