#ifndef CTASK_H
#define CTASK_H

#include <stdio.h>

class CTask
{
public:
	CTask*mp_Next;
	bool m_Enabled;          //—LŒø‚©–³Œø‚©

	virtual void Update();
};

#endif