#ifndef ENDEING_GUARD
#define ENDEING_GUARD

#include "../CObjectBase.h"

#define ENDEING_SIZ_X 1000
#define ENDEING_SIZ_Y 6394

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
	void Draw();
private:
	bool m_end_flag;	//�I���܂���t���O

};

#endif // !ENDEING_GUARD
