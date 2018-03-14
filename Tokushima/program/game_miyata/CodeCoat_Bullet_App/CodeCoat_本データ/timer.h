#ifndef TIMER_H
#define	TIMER_H

#include "myLib.h"

const int TIMER_SPACE = 35;

class timer{
public:
	CVector2D pos;
	CVector2D movepos;
	float time;
};

class CTimeData{
private:
	timer m_timer;
	int Tnumimg[22];
public:
	void load();
	void init();
	void move(CVector2D pos);
	void draw();
	float GetTime(){ return m_timer.time; };
};

#endif TIMER_H