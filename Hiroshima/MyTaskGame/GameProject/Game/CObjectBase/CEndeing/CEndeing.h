#ifndef ENDEING_GUARD
#define ENDEING_GUARD

#include "../CObjectBase.h"

#define ENDEING_SIZ_X 1000
#define ENDEING_SIZ_Y 5859

/*

����ҁ@�{��

*/
class CEnding : public CObjectBase
{
public:
	//�^�C�g���摜
	CEnding();
	~CEnding();
	void Update();
private:
	bool m_end_flag;	//�I���܂���t���O
	float m_vol;

};

#endif // !ENDEING_GUARD
