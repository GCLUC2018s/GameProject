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
	enum {
		eNutral,
		eAttack,
	};
	void Nutral();		//�ʏ펞�̍s���֐�
	void Attack();		//�U�����̍s���֐�
	bool	m_punch1;	//�p���`����
	bool	m_punch2;	//�L�b�N���ځi�{���F�p���`�͕���킵�������j
	bool	m_jump;		//true�Ȃ�W�����v��
	bool	m_move_length;	//true�Ȃ�㉺�Ɉړ����i�{���Flenght���Ē����̎������ǂǂ䂱�ƁH�j
	bool	m_move_side;	//true�Ȃ獶�E�Ɉړ���
	bool	m_squat;		//true�Ȃ炵�Ⴊ�ݒ�
	int		m_anim;			//�A�j���[�V�����i���o�[�BChangeAnimation�ŌĂ΂��
	int		m_y;			//�g���ĂȂ�
	int		m_cnt;			//����SE�Đ��p�Bm_cnt % 30 == 0�Ȃ瑫�����Đ������
	int		m_dash;			//3��ނ��鑫���������_���ōĐ�����p
	float	m_variation;	//���ɍs�����班�������悤�ɂ������āA���̐��l
};

#endif // !PLAYER_GUARD