#ifndef CRECTANGLE_H
#define CRECTANGLE_H
#include"CTask.h"
#include"CTexture.h"
class CRectangle :public CTask{
public:
	float mLeft, mRight, mBottom, mTop;
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	void SetTexture(CTexture *t, float left, float right, float bottom, float top);
	CTexture *mpTexture;
	float uv[4];
};
#endif