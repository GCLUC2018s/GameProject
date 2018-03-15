#ifndef PLAYER_GUARD
#define PLAYER_GUARD
#define REPULSION 0.8f
#define GRAVITY 1.2f
#define GRAVITY_DIE 1.001f

#include"../CObjectBase.h"
/*

制作者　六車　

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
	bool	m_punch2;	//キック一回目（宮�ｱ：パンチは紛らわしいかも）
	bool	m_jump;		//trueならジャンプ中
	bool	m_move_length;	//trueなら上下に移動中（宮�ｱ：lenghtって長さの事だけどどゆこと？）
	bool	m_move_side;	//trueなら左右に移動中
	bool	m_squat;		//trueならしゃがみ中
	int		m_die;			//やられた時に使う
	int		m_anim;			//アニメーションナンバー。ChangeAnimationで呼ばれる
	int		m_y;			//使われてない
	int		m_cnt;			//足音SE再生用。m_cnt % 30 == 0なら足音が再生される
	int		m_dash;			//3種類ある足音をランダムで再生する用
	int		m_hp;			//体力
	float	m_variation;	//奥に行ったら少しずれるようにしたくて、その数値
};

#endif // !PLAYER_GUARD