#include "CScene.h"
#include "CImage.h"

class CTitle : public CScene{
private:
	CImage img;
public:
	CTitle();
	void Update();
	void Render();

};