#ifndef CUTIN_GUARD
#define CUTIN_GUARD

#include "../CObjectBase.h"

/*

制作　宮﨑

*/
class CCutIn : public CObjectBase
{
public:
	//カットイン
	CCutIn();
	~CCutIn();
	void Update();
private:
	int m_time;

};

#endif // !CUTIN_GUARD