#ifndef PUSH_START_BG_GUARD
#define PUSH_START_BG_GUARD

#include "../CObjectBase.h"

/*

����ҁ@�{��

*/
class CPushStart : public CObjectBase
{
public:
	//PushStart�摜
	CPushStart();
	~CPushStart();
	void Update();
	void SetEnd() {
		m_end_flag = true;
	}
private:
	bool m_end_flag;	//�I���܂���t���O
};

#endif // !TITLE_BG_GUARD