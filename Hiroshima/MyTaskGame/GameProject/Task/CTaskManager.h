#ifndef TASK_MANAGER_GUARD
#define TASK_MANAGER_GUARD

class CTask;
class CTaskLinker;

class CTaskManager
{
private:
	static CTaskManager *mp_instance;	//���������Ȃ�����
protected:
	CTaskLinker *mp_U_Top;	//Update�p�̐擪�|�C���^
	CTaskLinker *mp_U_End;	//Update�p�̖����|�C���^

	CTaskLinker *mp_D_Top;	//Draw�p�̐擪�|�C���^
	CTaskLinker *mp_D_End;	//Draw�p�̖����|�C���^
public:
	CTaskManager();
	~CTaskManager();
	//���X�g�ǉ��֐�
	void Add(CTask *p);
	//���X�g���폜�֐�
	CTask* Kill(CTask *p);
	//���X�g���w��폜�֐�
	void KillAppoint();
	//�^�X�N��S�폜
	void KillAll();
	//�S�^�X�N�̍폜�t���O��true�ɂ���
	void SetKillAll();
	//�w���ID�̃|�[�Y�t���O������ɃZ�b�g����
	void SetPause(int ID, bool flag);
	//���X�g�X�V�֐�
	void UpdateAll();
	//���X�g�`��֐�
	void DrawAll();
	// �X�V�D��x��ύX 
	void ChangeUpdatePrio(CTask *p, int prio);
	// �`��D��x��ύX 
	void ChangeDrawPrio(CTask *p, int prio);
	////�`�揇�ʓ���ւ�
	//void SwapDrawPrio(CTask *p1, CTask *p2);

	//�^�X�N�擾�֐�
	CTask* GetTask(int id);
	//�^�X�N�J�E���g�֐�
	int GetCount(int id);

	//CTaskManager�𐶐����ĕϐ��Ɋi�[
	static CTaskManager* GetInstance();
	//�i�[����Ă�����̂��폜
	static void ClearInstance();

private:
	// ���X�g�ǉ��������� 
	void AddTask(CTaskLinker *p, CTaskLinker **pTop, CTaskLinker **pEnd);

	// ���X�g����O�� 
	void RemoveTask(CTaskLinker *p, CTaskLinker **pTop, CTaskLinker **pEnd);



};
#endif // !TASK_MANAGER_GUARD

