#ifndef TASK_GUARD
#define TASK_GUARD

#include <stdio.h>

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
	eUDP_Gimmick,
	eDWP_Player,
	eDWP_Enemy,
	eUDP_Item,
	eDWP_Tutorial,
	eDWP_Null,
};

//�^�X�N�w�b�_�[
class CTask
{
protected:
	bool m_death_flag;	//���S�t���O
	bool m_swap_flag;	//����ւ��t���O
	bool m_pause_flag;	//�X�V��~�t���O
	int	m_id;

	int m_Update_prio;
	int	m_Draw_prio;

	CTask* m_Update_next;	//�����̎��̃A�h���X�i�X�V�j
	CTask* m_Draw_next;		//�����̎��̃A�h���X�i�`��j
	CTask* m_Update_prev;	//�����̑O�̃A�h���X�i�X�V�j
	CTask* m_Draw_prev;		//�����̑O�̃A�h���X�i�`��j

public:
	/*
	CTask�N���X�̃R���X�g���N�^
	m_id			�����炭�O�Œ�ł���
	m_updatePrio	���̍X�V�����Q��
	m_drawPrio		���̕`�揇���Q��
	*/
	CTask(int id, int updatePrio, int drawPrio);
	virtual ~CTask();
	virtual void Update();	//�h����N���X�ł̍X�V���s���֐�
	virtual void Draw();	//�h����N���X�ł̕`�ʂ��s���֐�
	
	//�Ăяo�����Ώۂ̎��S�t���O�𗧂Ă�
	void SetDeath() {
		m_death_flag = true;
	};
	static void HitCheck(CTask* t1, CTask* t2);
	static void Swap_Draw(CTask* t1, CTask* t2);
	static void Swap_Update(CTask* t1, CTask* t2);

	friend class CTaskManager;

};
#endif // !TASK_GUARD