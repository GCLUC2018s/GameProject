#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

class C_Player :public C_Rectangle{
public:
	C_Player(){
		//�L�����N�^�[�A�j���[�V�����摜�̓ǂݍ���
		i_Chara_Motion_1.Load("../image/chara_motion_1.tga");
		i_Chara_Motion_2.Load("../image/chara_motion_2.tga");
		//ID�ƃv���C�I���e�B��ݒ肵�܂�
		C_Player::CTask(E_SCROLL, eUDP_Player, eDWP_Player);
		//�v���C���[�̏�������
		m_Turn = E_RIGHT;
	}

	//�v���C���[�̌����t���O
	enum TURN_TAG{
		E_RIGHT,
		E_LEFT,
	};

	//�e�N�X�`���[�̃C���X�^���X�錾
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