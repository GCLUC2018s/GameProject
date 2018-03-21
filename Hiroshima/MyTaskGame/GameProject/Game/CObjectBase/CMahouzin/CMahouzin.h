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
	CAnimImage m_img_ef;
	int m_time;
	int m_size;
	CPlayer *PL;

};


#endif // !MAHOUZIN_GUARD
