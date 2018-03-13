#ifndef SCROLL_H
#define SCROLL_H

#include "CRectangle.h"
#include "../task/CTask.h"

#define SCROLL_SPEED 8

class C_Scroll{
public:
	float m_Left, m_Right;
	void Scroll(float left, float right);
};

#endif