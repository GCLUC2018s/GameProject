#ifndef GO_GUARD
#define GO_GUARD

#include "../CObjectBase.h"

#define GO_SIZ 128
#define GO_TIME 0.1f


class CGo : public CObjectBase
{
public:
	CGo();
	~CGo();
	void Update();
private:
	float m_a;
};
#endif // !GO_GUARD
