#ifndef CPLAYER_H
#define CPLAYER_H
#include"CRectangle.h"
#include"CTexture.h"
class CPlayer :public CRectangle{
public:
	CTexture mTexture;
	void Init();
	void Update();
	void Draw();

};
#endif