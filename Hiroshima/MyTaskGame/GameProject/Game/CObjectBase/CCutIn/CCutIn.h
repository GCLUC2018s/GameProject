#ifndef CUTIN_GUARD
#define CUTIN_GUARD

#include "../CObjectBase.h"

/*

����@�{��

*/
class CCutIn : public CObjectBase
{
public:
	//�J�b�g�C��
	CCutIn();
	~CCutIn();
	void Update();
private:
	int m_time;

};

#endif // !CUTIN_GUARD