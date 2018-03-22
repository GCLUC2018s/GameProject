#ifndef TASK_GUARD
#define TASK_GUARD

#include "../Global.h"
#include "CTaskLinker.h"

class CObjectBase;

//�X�V����
enum {
	eU_System,
	eU_Player,
	eU_Bullet,
	eU_Enemy,
	eU_Gimmick,
	eU_Item,
	eU_UI,
	eU_Effect,
	eU_Map,
	eU_Back,
	eU_Scene,
	eU_Null,
};
//�`�揇��
enum {
	eD_Back,
	eD_Cloud,
	eD_Bamboo,
	eD_Ground,
	eD_Object,
	eD_Effect,
	eD_UI,
	eD_Null,
};
//ID
enum {
	eID_UI,
	eID_HPUI,
	eID_Player,
	eID_Bullet,
	eID_Enemy,
	eID_Boss,
	eID_Item,
	eID_Gimmick,
	eID_Effect,
	eID_Magatama,
	eID_Ground,
	eID_Null,
};

class CTask
{
protected:
	bool m_destroy;	//true�Ȃ�A���̃^�X�N�͍폜�����
	bool m_pause;	//true�Ȃ�X�V��~
	int m_id;		//��{0

	CTaskLinker m_UPD_link;		// Update�p��CTaskLinker 
	CTaskLinker m_DRW_link;		// Draw�p��CTaskLinker 
public:
	CTask();	//�f�t�H���g�R���X�g���N�^�B�g��Ȃ����ǂ���炵��
	/*
	�P�Ԗڂ̈����uid�v�́A��{0
	�Q�Ԗڂ̈����uUPD_prio�v�́A�X�V���ʁBenum�ō���Ă�
	�R�Ԗڂ̈����uDRW_prio�v�́A�`�揇�ʁBenum�ō���Ă�
	*/
	CTask(int id,int UPD_prio,int DRW_prio);
	virtual ~CTask();
	virtual void Update();
	virtual void Draw();
	virtual void HitCheck(CTask *t1, CTask *t2);
	virtual void Hit(CObjectBase *t);


	//�X�V���ʎ擾�֐�
	int GetUpdatePrio() const;
	//�`�揇�ʎ擾�֐�
	int GetDrawPrio() const;
	//ID�擾�֐�
	int GetID() const {
		return m_id;
	};

	//�X�V���ʕύX
	void ChangeUpdatePrio(int updatePrio);
	//�`�揇�ʕύX
	void ChangeDrawPriority(int drawPrio);

	// �폜�t���O�𗧂Ă� 
	void SetKill()
	{
		m_destroy = true;
	};
	friend class CTaskManager;

	//���ׂẲ��y���~
	void MusicStop() {
		SOUND("BGM_Title")->Stop();
		SOUND("BGM_Main")->Stop();
		SOUND("BGM_Boss")->Stop();
		SOUND("BGM_Ending")->Stop();
		SOUND("BGM_GameOver")->Stop();
	};

};

#endif // !TASK_GUARD
