#ifndef PLAYER_GUARD
#define PLAYER_GUARD
#define REPULSION 0.8f
#define GRAVITY_DIE 1.001f
#define PLAYER_HP 100

#include"../CObjectBase.h"

class CMagatama;

/*

����ҁ@�Z�ԁ@

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
	CVector3D Die(CVector3D vec);			//���ꂽ���̓���
	void Nutral();		//�ʏ펞�̍s���֐�
	void Attack();		//�U�����̍s���֐�
	void Bill();		//���D�U�����̍s���֐�
	void Damage();		//�U�����󂯂����̍s���֐�
	void Fall();		//���ꂽ���̍s���֐�
	bool	m_punch1;	//�p���`����
	bool	m_punch2;	//�p���`����
	bool	m_kick;		//�L�b�N����
	bool	m_jump;		//true�Ȃ�W�����v��
	bool	m_move_length;	//true�Ȃ�㉺�Ɉړ����i�{���Flenght���Ē����̎������ǂǂ䂱�ƁH�j
	bool	m_move_right;	//true�Ȃ�E�Ɉړ���
	bool	m_move_left;	//true�Ȃ獶�Ɉړ���
	bool	m_squat;		//true�Ȃ炵�Ⴊ�ݒ�
	bool	m_roof;			//�����̏�ɏ����������ĂȂ���
	int		m_die;			//���ꂽ���Ɏg��
	int		m_anim;			//�A�j���[�V�����i���o�[�BChangeAnimation�ŌĂ΂��
	int		m_y;			//�g���ĂȂ�
	int		m_cnt;			//����SE�Đ��p�Bm_cnt % 30 == 0�Ȃ瑫�����Đ������
	int		m_dash;			//3��ނ��鑫���������_���ōĐ�����p
	float	m_variation;	//���ɍs�����班�������悤�ɂ������āA���̐��l
};

#endif // !PLAYER_GUARD