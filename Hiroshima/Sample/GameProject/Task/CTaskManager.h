#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

class CTask;

enum {
	eUpdate,
	eDraw,
};

class CTaskManager
{	
private:
	CTaskManager(); 
	static CTaskManager* mp_instance;	//�Q�[�����Ŏg���^�X�N�}�l�[�W���[�̃|�C���^�B�O������͕ς��Ȃ��ŁB�g�������Ȃ�GetInstance()�łǂ���
	// ���X�g�ǉ��������� 
	void AddTaskIn(CTask **p, CTask **pTop, CTask **pEnd,bool flag);
	// ���X�g����O�� 
	void RemoveTask(CTask **p, CTask **pTop, CTask **pEnd,bool flag);

public:
	~CTaskManager();
	//���X�g�ǉ��֐�
	void Add(CTask *p);
	//���X�g���폜�֐�
	CTask* Kill(CTask *p);
	//���X�g���w��폜�֐�
	void KillAppoint();
	//���X�g�X�V�֐�
	void UpdateAll();
	//���X�g�`��֐�
	void DrawAll();
	/*
	CTaskManager�𐶐����ĕϐ��Ɋi�[
	CTaskManager�́A�Q�[�����ň��������Ȃ��̂ŁA���������̂�j�~����
	*/
	static CTaskManager* GetInstance();
protected:
	CTask* mp_Upd_Top;		  //Update�Ŏg���A�擪�������|�C���^
	CTask* mp_Upd_End;		  //Update�Ŏg���A�I���������|�C���^
	CTask* mp_Drw_Top;		  //Draw�Ŏg���A�擪�������|�C���^
	CTask* mp_Drw_End;		  //Draw�Ŏg���A�I���������|�C���^

};

#endif	//!TASKMANAGER_GUARD