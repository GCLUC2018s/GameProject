#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include"../CObjectBase.h"
/*

êßçÏé“Å@òZé‘Å@

*/

class CPlayer :public CObjectBase {
public:
	CPlayer();
	~CPlayer();
	 void Update();
	 void Draw();
private:
	enum {
		eNutral,
		eAttack,
	};
	void Nutral();
	void Attack();
	bool	m_punch1;
	bool	m_punch2;
	bool	m_jump;
	bool	m_move_length;
	bool	m_move_side;
	int		m_anim;
	int		m_y;
	int		m_cnt;
	int		m_dash;
	bool	m_squat;
	float	m_variation;
};

#endif // !PLAYER_GUARD