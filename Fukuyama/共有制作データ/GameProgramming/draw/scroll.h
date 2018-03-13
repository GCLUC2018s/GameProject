#ifndef SCROLL_H
#define SCROLL_H

#include "CRectangle.h"

#define SCROLL_SPEED 8

class C_Scroll{
private:
	float m_Left, m_Right;
public:
	void Scroll(float left,float right);
};

#endif