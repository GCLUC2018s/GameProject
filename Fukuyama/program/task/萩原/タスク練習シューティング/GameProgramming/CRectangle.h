#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTexture.h"
#include "CTask.h"
#include "windows.h"

class CRectangle:public CTask{
public:
	CTexture tPlayer;
	CTexture tPlayerBullet;
	void Init();
	int mRight, mLeft, mBottom, mTop;
	void SetVertex(int Left, int Right, int Bottom, int top);
};

#endif