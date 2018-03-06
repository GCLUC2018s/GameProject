#ifndef TEST_H
#define TEST_H
#include "CRectangle.h"
class test : public CRectangle{
public:
	void Init();
	void Update();
	void Render();
	bool enabled;
};
class test2 : public CRectangle{
public:
	void Init();
	void Update();
	void Render();
	bool enabled;
};
#endif