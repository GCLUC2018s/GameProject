#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/CRectangle.h"
#include "../draw/scroll.h"
#include <stdio.h>

#define PLAYER_LR_SPEED SCROLL_SPEED     //�v���C���[�̍��E�ړ����x
#define PLAYER_UD_SPEED 5     //�v���C���[�̏㉺�ړ����x

class C_Player :public C_Rectangle{
public:
	C_Player() :C_Rectangle(E_PLAYER, eUDP_Player, eDWP_Player)
	{
		m_Enabled = true;
		//�A�j���[�V�����J�E���^�̏�����
		m_Anime = 0;
		m_Anime_s = 0;
		//�v���C���[�̃T�C�Y
		SetVertex(0, 90, 0, 135);
		//�L�����N�^�[�A�j���[�V�����摜�̓ǂݍ���
		i_Chara_Motion_1.Load("image/chara/chara_motion_1.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_Left, m_Right, m_Bottom, m_Top);
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
	virtual void Update();
	virtual void Draw();
};

#endif