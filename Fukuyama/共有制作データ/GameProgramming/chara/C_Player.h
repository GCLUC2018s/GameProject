#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/scroll.h"
#include <stdio.h>
#include "../object/C_Object.h"
#include "../object/CColorBall.h"

#define PLAYER_LR_SPEED SCROLL_SPEED     //�v���C���[�̍��E�ړ����x
#define PLAYER_UD_SPEED 4     //�v���C���[�̏㉺�ړ����x
#define JUMP_FIRST_SPEED 10    //�W�����v�̏���
#define JUMP_ANIME 15    //���n���[�V�����̎���
#define SET_INTERVAL 180       //�J���[�{�[���ݒu�Ԋu
#define THROW_INTERVAL 60      //�J���[�{�[�������Ԋu
#define SPRAY_INTERVAL 600     //�X�v���[�̃N�[���^�C��

class C_Player :public C_Object{
public:
	C_Player() 
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,0)
		, i_JumpPoint(0,0,0)
		, m_SetInterval(SET_INTERVAL)
		, m_ThrowInterval(THROW_INTERVAL)
		, m_SprayInterval(SPRAY_INTERVAL)
	{
		m_image.m_Enabled = true;
		//�v���C���[�̃T�C�Y
		m_image.SetVertex(0, 90, 0, 135);
		//�e�̃T�C�Y
		i_Shadow.SetVertex(0, 60, 0, 135);
		//�L�����N�^�[�A�j���[�V�����摜�̓ǂݍ���
		i_Chara_Motion_1.Load("image/chara/chara_motion_1_16bit.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);

		//��Ԃɉ������X�e�[�^�X���擾
		m_Turn = E_RIGHT;
		m_Jump = E_NJUMP;
		m_Throw = E_NTHROW;
		m_Set = E_NSET;
		m_Spray = E_NSPRAY;

		m_Speed.y = JUMP_FIRST_SPEED; //�W�����v�̏�����ݒ肵�܂��B
		m_Playerpoint = this;
	}
	static C_Player *m_Playerpoint;
	C_Vector3 i_JumpPoint;
	bool Collision(C_Task*, C_Task*);
protected:
	//�e�N�X�`���[�̃C���X�^���X�錾
	CTexture i_Chara_Motion_1;
	CTexture i_Chara_Motion_2;
	float m_JumpTime;       //�W�����v���Ă��璅�n�܂ł̎���
	int m_SetInterval;        //�ݒu�Ԋu
	int m_ThrowInterval;          //�����Ԋu
	int m_SprayInterval;          //�X�v���[�g�p�Ԋu
	void Jump(C_Vector3& pos, C_Vector3& speed, const C_Vector3& gravity, float deltatime);
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