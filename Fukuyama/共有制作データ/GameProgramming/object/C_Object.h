#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "../task/CTask.h"
#include "CVector3.h"
#include "../draw/CRectangle.h"

#define RUN_ANIME_INTERVAL 8   //�A�j���[�V����1��������̃t���[����
#define RUN_ANIME_FRAME 6    //����A�j���̊G�̐�
#define RUN_ANIME RUN_ANIME_INTERVAL*RUN_ANIME_FRAME    //�A�j���[�V�����p�ϐ����񂷏��
#define THROW_ANIME_INTERVAL 7  //�A�j���[�V����1��������̃t���[����
#define THROW_ANIME_FRAME 2    //����A�j���̊G�̐�
#define THROW_ANIME THROW_ANIME_INTERVAL*THROW_ANIME_FRAME    //�A�j���[�V�����p�ϐ����񂷏��
#define SET_ANIME_INTERVAL 7  //�A�j���[�V����1��������̃t���[����
#define SET_ANIME_FRAME 2    //����A�j���̊G�̐�
#define SET_ANIME THROW_ANIME_INTERVAL*THROW_ANIME_FRAME    //�A�j���[�V�����p�ϐ����񂷏��

enum PLAYER_STATE{
	E_RIGHT,    //�E����
	E_LEFT,     //������
	E_JUMP,     //�W�����v��
	E_NJUMP,    //�W�����v���ł͂Ȃ�
	E_THROW,    //�J���[�{�[��������
	E_NTHROW,   //�J���[�{�[���������ł͂Ȃ�
	E_SET,      //�J���[�{�[���ݒu��
	E_NSET,     //�J���[�{�[���ݒu���ł͂Ȃ�
};

class C_Object :public CTask{
public:
	//�R���X�g���N�^��id�ƃv���C�I���e�B�̐ݒ�ƃ����o�[�̏�����
	C_Object(int id, int updatePrio, int drawPrio, float posx, float posy, float posz)
		:CTask(id, updatePrio, drawPrio)
		, init(false)
		, m_Position(posx, posy, posz)
		, m_Anime(0)        //�A�j���[�V�����J�E���^�̏�����
		, m_Anime_Jump(50)      //�W�����v�p�A�j���[�V�����J�E���^�̏�����
		, m_Anime_Set(SET_ANIME+2)       //�ݒu�A�j���[�V�����J�E���^�̏�����
		, m_Anime_Throw(THROW_ANIME+2)     //�����A�j���[�V�����J�E���^�̏�����
		, m_Speed(0.0f, 0.0f, 0.0f)
		, m_Gravity(0.0f,-9.8f,0.0f)
	{}
	bool init;  //Init��ʂ������ǂ���
	void Init();
	C_Vector3 m_Position;  //���W���Ǘ�
	static float m_Scroll;  //�X�N���[����_
	int m_Turn;             //�E�������Ă��邩���������Ă��邩
	int m_Jump;             //�W�����v���Ă��邩���Ă��Ȃ��̂�
	int m_Throw;            //�{�[���𓊂��Ă��邩
	int m_Set;              //�{�[����ݒu���Ă��邩�ǂ���
	int m_Anime;            //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_Taiki;      //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_Jump;       //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_Set;        //�A�j���[�V�����Ǘ��ϐ�
	int m_Anime_Throw;      //�A�j���[�V�����Ǘ��ϐ�

	void RunAnime(CTexture *image, int id);      //����A�j��
	void TaikiAnime(CTexture *image, int id);    //�ҋ@�A�j��
protected:
	C_Rectangle i_Shadow;   //�e�p�C���X�^���X
	C_Rectangle m_image;  //�����o�[�ϐ��ɂ���
	C_Vector3 m_Speed;  //���x���Ǘ�
	C_Vector3 m_Gravity;  //�d��
	void Rect(C_Rectangle* image,const C_Vector3* pos);  //�|�W�V�����̏ꏊ��C_Rectangle�\��
	void Scroll(C_Vector3 *m_pos,float m_Scroll);     //�X�N���[�����������܂�
};
#endif