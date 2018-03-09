#ifndef CPLAYER_H
#define CPLAYER_H
#include "CRectangle.h"
class CPlayer : public CRectangle{
public:
	void Init();
private:
	void Update();
	void Draw();
};
#endif