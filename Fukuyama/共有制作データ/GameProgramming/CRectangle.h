#ifndef CMYRECT_H
#define CMYRECT_H

class CRectangle{
public:
	float mLeft, mRight, mBottom, mTop;
	float mAdjust;
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool mEnabled;
};

#endif