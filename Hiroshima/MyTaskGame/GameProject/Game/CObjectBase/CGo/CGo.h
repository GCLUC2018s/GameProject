#ifndef GO_GUARD
#define GO_GUARD

#include "../CObjectBase.h"

#define GO_SIZ 128
#define GO_TIME 50


class CGo : public CObjectBase
{
public:
	CGo();
	~CGo();
	void Update();
};
#endif // !GO_GUARD
