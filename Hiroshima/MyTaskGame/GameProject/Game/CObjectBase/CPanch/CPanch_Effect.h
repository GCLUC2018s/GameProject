#ifndef PANCH_EF_GUARD
#define PANCH_EF_GUARD

#include "../CObjectBase.h"

class CPanchEF : public CObjectBase{
public:
	CPanchEF(bool frip,const CVector3D pos);
	void Update();
private:

}
#endif // !PANCH_EF_GUARD
