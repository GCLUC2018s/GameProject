#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include"../CObjectBase.h"
/*

����ҁ@�Z�ԁ@

*/

class CPlayer :public CObjectBase {
public:
	CPlayer();
	~CPlayer();
	 void Update();
	 void Draw();
private:
	bool	m_punch;
	int		m_anim;
	bool	m_squat;
};

#endif // !PLAYER_GUARD