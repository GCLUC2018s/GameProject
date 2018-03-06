#ifndef CRECTANGLE_H
#define CRECTANGLE_H
#include <Windows.h>
#include "CVector2.h"
#include "glut.h"
class CRectangle{
public: 
	float mAjust = 0.0f;
	bool mEnabled;
	void SetVer(float left, float right, float bottom, float top);
	float mLeft, mRight, mBottom, mTop;
	void RectRender();
};
#endif