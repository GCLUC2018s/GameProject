#ifndef PLAYER_GUARD
#define PLAYER_GUARD

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
	};
	void Nutral();		//通常時の行動関数
	void Attack();		//攻撃時の行動関数
	bool	m_punch1;	//パンチ一回目
	bool	m_punch2;	//キック一回目（宮﨑：パンチは紛らわしいかも）
	bool	m_jump;		//trueならジャンプ中
	bool	m_move_length;	//trueなら上下に移動中（宮﨑：lenghtって長さの事だけどどゆこと？）
	bool	m_move_side;	//trueなら左右に移動中
	bool	m_squat;		//trueならしゃがみ中
	int		m_anim;			//アニメーションナンバー。ChangeAnimationで呼ばれる
	int		m_y;			//使われてない
	int		m_cnt;			//足音SE再生用。m_cnt % 30 == 0なら足音が再生される
	int		m_dash;			//3種類ある足音をランダムで再生する用
	float	m_variation;	//奥に行ったら少しずれるようにしたくて、その数値
};

#endif // !PLAYER_GUARD