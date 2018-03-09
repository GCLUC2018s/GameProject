#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include "../Task/CTask.h"

class CPlayer : public CTask{
public:
	CPlayer();
	void Update();
	void Draw();
private:
	CImage p_img;
	CVector2D p_pos;
	CVector2D p_vec;
	int m_time;
};
#endif // !PLAYER_GUARD
