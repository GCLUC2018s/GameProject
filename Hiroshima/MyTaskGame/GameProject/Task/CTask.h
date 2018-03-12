#ifndef TASK_GUARD
#define TASK_GUARD

#include "../Global.h"

//�X�V����
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Gimmick,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Item,
	eUDP_Map,
	eUDP_Null,
};
//�`�揇��
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Gimmick,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Item,
	eDWP_Tutorial,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_death_flag;				//�폜�t���O
	bool m_pause_flag;				//�X�V��~�t���O
	//int m_id;

public:
	CTask(/*int id, int updateprio, int drawPrio*/);//CTask�N���X�̃R���X�g���N�^
	virtual ~CTask();				//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Draw();			//�h����N���X�ł̕`�ʂ��s���֐�
	CTask*		mp_Upd_next;		// Update�p��next
	CTask*		mp_Upd_prev;		// Update�p��prev
	CTask*		mp_Drw_next;		// Draw�p��next 
	CTask*		mp_Drw_prev;		// Draw�p��prev

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
		m_death_flag = true;
	}
	friend class CTaskManager;
};


#endif // !TASK_GUARD
