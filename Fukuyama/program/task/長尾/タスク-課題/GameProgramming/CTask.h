#ifndef CTASK_H
#define CTASK_H
#include <stdio.h>
class CTask{
public:
	void Init();
	bool m_DEAD;
	virtual void Update();
	//���|�C���^
	CTask *mpNext;
};
class CTaskManager{
private:
	//�擪�|�C���^
	CTask *mpHead;
	//�����|�C���^
	CTask *mpTail;
	CTaskManager()
		:mpHead(0)
		, mpTail(0)
	{}
public:
	static CTaskManager *Get();
	void Add(CTask *p);
};
#endif