#include "CRectangle.h"
#include "CTexture.h"

class CPlayer :public CRectangle{
public:
	//���ˊ��o
	int fire;

	CRectangle *PlayerBullet;
	void Init();
	void Update();
	void Draw();
};