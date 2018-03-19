#ifndef GO_GUARD
#define GO_GUARD

#include "../CObjectBase.h"

#define GO_SIZ_X 250
#define GO_SIZ_Y 150
#define GO_POS_X SCREEN_WIDTH-GO_SIZ_Y-150
#define GO_TIME 0.1f


class CGo : public CObjectBase
{
public:
	//trueÇ»ÇÁÅAbossÇ…à⁄ìÆ
	CGo(bool end_flag);
	~CGo();
	void Update();
private:
	float m_a;
	bool m_end_flag;
};
#endif // !GO_GUARD
