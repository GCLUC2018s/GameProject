#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/scroll.h"
#include <stdio.h>
#include "../object/C_Object.h"

#define PLAYER_LR_SPEED SCROLL_SPEED     //�v���C���[�̍��E�ړ����x
#define PLAYER_UD_SPEED 4     //�v���C���[�̏㉺�ړ����x
#define RUN_ANIME_INTERVAL 8   //�A�j���[�V����1��������̃t���[����
#define RUN_ANIME_FRAME 6    //����A�j���̊G�̐�
#define RUN_ANIME RUN_ANIME_INTERVAL*RUN_ANIME_FRAME    //�A�j���[�V�����p�ϐ����񂷏��

class C_Player :public C_Object{
public:
	C_Player() 
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,0)
		,m_Anime(0)           //�A�j���[�V�����J�E���^�̏�����
		, m_Turn(E_RIGHT)
	{
		m_image.m_Enabled = true;
		//�v���C���[�̃T�C�Y
		m_image.SetVertex(0, 90, 0, 135);
		//�L�����N�^�[�A�j���[�V�����摜�̓ǂݍ���
		i_Chara_Motion_1.Load("image/chara/chara_motion_1_16bit.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);
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
	int m_Anime_Taiki;      //�A�j���[�V�����Ǘ��ϐ�
	int m_Turn;             //�E�������Ă��邩���������Ă��邩
	virtual void Update();
	virtual void Draw();
};

class C_Test :public C_Object{
public:
	C_Test()
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,-450)
		, m_Anime(0)           //�A�j���[�V�����J�E���^�̏�����
	{
		m_image.m_Enabled = true;
		//�v���C���[�̃T�C�Y
		m_image.SetVertex(-600, 600, -450, -330);
	}
	int m_Anime;            //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_Taiki;      //�A�j���[�V�����Ǘ��ϐ�
	int m_Turn;             //�E�������Ă��邩���������Ă��邩
	virtual void Update();
	virtual void Draw();
};

#endif