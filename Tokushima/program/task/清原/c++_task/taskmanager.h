#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "task.h"

class TaskManager{
public:
	int num;
	Task *BTask;
	void update(){
		if (BTask != NULL)
			BTask->update();
	}
};


#endif	TASKMANAGER_H