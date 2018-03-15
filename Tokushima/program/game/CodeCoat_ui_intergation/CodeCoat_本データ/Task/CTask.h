/**
* @file		CTask.h
* @brief	�^�X�N�V�X�e�����N���X
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "CTaskLinker.h"

//�X�V����
enum E_UpdatePrio
{
	eUDP_Tutorial = 0,
	eUDP_Player = 1,
	eUDP_Camera = 2,
	eUDP_Enemy,
	eUDP_Item,
	eUDP_Map,
	eUDP_Bullet,
	eUDP_Null,
	eUDP_Ui
};
//�`�揇��
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Enemy,
	eDWP_Player,
	eDWP_Bullet,
	eDWP_Item,
	eDWP_Tutorial,
	eDWP_Null,
	eDWP_Ui
};

class CTask
{
private:
	
protected:
	bool m_destroyFlg;				//�폜�t���O
	bool m_pauseFlg;				//�X�V��~�t���O
	int m_id;

	CTaskLinker		m_updLinker;		// Update�p��CTaskLinker 
	CTaskLinker		m_drwLinker;		// Draw�p��CTaskLinker 
	CTask();
public:
					//CTask�N���X�̃R���X�g���N�^
	CTask(int id, int updateprio, int drawPrio);
	virtual ~CTask();				//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Draw();			//�h����N���X�ł̕`�ʂ��s���֐�

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
	friend class CPlayerManager;
	friend class CItemManager;
	friend class CBulletManager;
	friend class CMapManager;
};

#endif