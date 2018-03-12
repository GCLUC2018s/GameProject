#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

#define PLAYER_SCROLL ((100-SCROLL_PERCENTAGE)/100)*1200    //�v���C���[�ƃX�N���[����_�̋���
#define PLAYER_START_BOTTOM -135               //�v���C���[�̏����ʒu�i���j���㉺�ʒu�����͉��̂ݕύX���Ă��������B
#define PLAYER_START_TOP (PLAYER_START_BOTTOM+135)          //�v���C���[�̏����ʒu�i��j
#define PLAYER_START_RIGHT (-PLAYER_SCROLL)          //�v���C���[�̏����ʒu�i�E�j
#define PLAYER_START_LEFT (PLAYER_START_RIGHT-90)       //�v���C���[�̏����ʒu�i���j

class C_Player :public C_Scroll{
protected:
	C_Player(){
		//�L�����N�^�[�A�j���[�V�����摜�̓ǂݍ���
		i_Chara_Motion_1.Load("../image/chara_motion_1.tga");
		i_Chara_Motion_2.Load("../image/chara_motion_2.tga");
		//ID�ƃv���C�I���e�B��ݒ肵�܂�
		C_Player::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
		//�v���C���[�̃T�C�Y
		SetVertex(PLAYER_START_LEFT, PLAYER_START_RIGHT, PLAYER_START_BOTTOM, PLAYER_START_TOP);
		//�v���C���[�̏�������
		m_Turn = E_RIGHT;
	}
public:
	enum TURN_TAG{
		E_RIGHT,
		E_LEFT,
	};

	CTexture i_Chara_Motion_1;
	CTexture i_Chara_Motion_2;
	int m_Anime;            //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_s;          //�A�j���[�V�����b���Ǘ�
	int m_Anime_Taiki;      //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_Taiki_s;    //�A�j���[�V�����b���Ǘ�(�ҋ@)
	int m_Turn;             //�E�������Ă��邩���������Ă��邩
	void Init();
	void Update();
	void Draw();
};

#endif