#ifndef CTASK_H
#define CTASK_H

#include <stdio.h>

class CTask
{
public:
	CTask*mp_Next;
	bool m_Enabled;          //�L����������

	virtual void Update();
};

#endif