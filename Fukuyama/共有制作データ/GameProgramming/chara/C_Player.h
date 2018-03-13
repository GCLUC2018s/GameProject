#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/CRectangle.h"
#include "../draw/scroll.h"

#define PLAYER_LR_SPEED SCROLL_SPEED     //�v���C���[�̍��E�ړ����x
#define PLAYER_UD_SPEED 5     //�v���C���[�̏㉺�ړ����x

class C_Player :public C_Rectangle{}
public:

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
	virtual void Init();
	virtual void Update();
	virtual void Draw();
};

#endif