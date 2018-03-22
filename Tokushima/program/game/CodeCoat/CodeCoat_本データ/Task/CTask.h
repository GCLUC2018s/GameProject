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
	eUDP_Npc,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Item,
	eUDP_Map,
	eUDP_Bullet,
	eUDP_Null,
	eUDP_Ui,
	eUDP_Rank,
};
//�`�揇��
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Npc,
	eDWP_Enemy,
	eDWP_BBullet,
	eDWP_BItem,
	eDWP_Player,
	eDWP_FEnemy,
	eDWP_Bullet,
	eDWP_Item,
	eDWP_Tutorial,
	eDWP_Null,
	eDWP_Ui,
	eDWP_Rank
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