#ifndef CMYRECT_H
#define CMYRECT_H

#include "CTexture.h"
#include "../task/CTask.h"
#include "../task/CTaskManager.h"

class CRectangle:public CTask{
public:
	float mLeft, mRight, mBottom, mTop;
	float mAdjust;
	void Init(){};
	void Update(){};
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool mEnabled;
};

#endif