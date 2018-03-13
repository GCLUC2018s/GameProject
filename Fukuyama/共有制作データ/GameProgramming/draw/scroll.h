#ifndef SCROLL_H
#define SCROLL_H

#include "CRectangle.h"
#include "../task/CTask.h"

#define SCROLL_SPEED 8

class C_Scroll{
	C_Scroll(){
		m_Scroll = 210;
	}
public:
	static float m_Scroll;
	static void Scroll(C_Rectangle*p);
};

#endif