#ifndef TASK_H
#define TASK_H

#include "stdlibrary.h"

//タスク(個々の処理)
class Task{
public:
	bool m_kill;
	virtual void update();
};

#endif TASK_H