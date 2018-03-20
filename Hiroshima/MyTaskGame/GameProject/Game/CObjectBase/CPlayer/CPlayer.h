#ifndef PLAYER_GUARD
#define PLAYER_GUARD
#define REPULSION 0.8f
#define GRAVITY_DIE 1.001f
#define PLAYER_HP 100

#include"../CObjectBase.h"

class CMagatama;

/*

制作者　六車　

*/

class CPlayer :public CObjectBase {
public:
	CPlayer();
	~CPlayer();
	 void Update();
	 void Draw();
	 void Hit(CObjectBase *t);
	 void SetJump(bool flag) {
		 m_jump = flag;
	 };
	 bool GetJump() {
		 return m_jump;
	 };
	 void SetHP(int hp) {
		 m_hp += hp;
		 if (m_hp >= PLAYER_HP)
			 m_hp = PLAYER_HP;
	 };

private:
	float m_sc_plus;
	enum {
		eNutral,
		eAttack,
		eBill,
		eDamage,
		eFall,
	};

	CVector2D damage_vec;
	CVector3D Die(CVector3D vec);			//やられた時の動き
	void Nutral();		//通常時の行動関数
	void Attack();		//攻撃時の行動関数
	void Bill();		//お札攻撃時の行動関数
	void Damage();		//攻撃を受けた時の行動関数
	void Fall();		//やられた時の行動関数
	bool	m_punch1;	//パンチ一回目
	bool	m_punch2;	//パンチ二回目
	bool	m_kick;		//キック一回目
	bool	m_jump;		//trueならジャンプ中
	bool	m_move_length;	//trueなら上下に移動中（宮﨑：lenghtって長さの事だけどどゆこと？）
	bool	m_move_right;	//trueなら右に移動中
	bool	m_move_left;	//trueなら左に移動中
	bool	m_squat;		//trueならしゃがみ中
	bool	m_roof;			//屋根の上に乗ったか乗ってないか
	int		m_die;			//やられた時に使う
	int		m_anim;			//アニメーションナンバー。ChangeAnimationで呼ばれる
	int		m_y;			//使われてない
	int		m_cnt;			//足音SE再生用。m_cnt % 30 == 0なら足音が再生される
	int		m_dash;			//3種類ある足音をランダムで再生する用
	float	m_variation;	//奥に行ったら少しずれるようにしたくて、その数値
};

#endif // !PLAYER_GUARD