#ifndef CRECTANGLE_H
#define CRECTANGLE_H
#include "glut.h"
#include "windows.h"
#include "CTexture.h"
#include "CTask.h"
class CRectangle : public CTask{
public:
	CTexture mTexture;
	void Init();
	void Update();
	float uv[4];
	float mLeft, mRight, mBottom, mTop;
	void SetVer(float left, float right, float bottom, float top);
	void Render();
	bool mEnabled;
};
#endif