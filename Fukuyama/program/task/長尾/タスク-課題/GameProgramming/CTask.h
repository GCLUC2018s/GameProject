#ifndef CTASK_H
#define CTASK_H
#include <stdio.h>
class CTask{
public:
	void Init();
	bool m_DEAD;
	virtual void Update();
	//次ポインタ
	CTask *mpNext;
};
class CTaskManager{
private:
	//先頭ポインタ
	CTask *mpHead;
	//末尾ポインタ
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