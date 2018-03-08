/**
* @file		CTask.h
* @brief	�^�X�N�V�X�e�����N���X
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "CTaskLinker.h"
#include "CAnimImage.h"
#include "../Global.h"


//�X�V����
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Bullet,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};
//�`�揇��
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Bullet,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Tutorial,
	eDWP_Null,
};
//ID
enum E_IDPrio
{
	eID_Map,
	eID_Bullet,
	eID_Player,
	eID_Enemy,
	eID_Tutorial,
	eID_Null,
};


class CTask
{
protected:
	bool m_destroyFlg;				//�폜�t���O
	bool m_pauseFlg;				//�X�V��~�t���O
	int m_id;

	CTaskLinker		m_updLinker;		// Update�p��CTaskLinker 
	CTaskLinker		m_drwLinker;		// Draw�p��CTaskLinker 

public:
	CTask();						//CTask�N���X�̃R���X�g���N�^
	CTask(int id, int updateprio, int drawPrio);
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_old_pos;
	CVector2D m_vec;
	CRect m_rect;
	CRect m_BG_rect = CRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	bool m_activ;
	virtual ~CTask();				//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Draw();			//�h����N���X�ł̕`�ʂ��s���֐�

	//�����蔻��
	void Hit() {
	}

	//�X�V���ʎ擾�֐�
	int GetUpdatePrio() const;
	//�`�揇�ʎ擾�֐�
	int GetDrawPrio() const;
	//�X�V���ʕύX
	void ChangeUpdatePrio(int updatePrio);
	//�`�揇�ʕύX
	void ChangeDrawPriority(int drawPrio);

	// �폜�t���O�𗧂Ă� 
	void SetKill() 
	{
		m_destroyFlg = true;
	}
	friend class CTaskManager;
};

#endif