#include "CRectangle.h"
#include "CTexture.h"

class CPlayer :public CRectangle{
public:
	//”­ŽËŠ´Šo
	int fire;

	CRectangle *PlayerBullet;
	void Init();
	void Update();
	void Draw();
};