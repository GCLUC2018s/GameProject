#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

����ҁ@�{��
�Ăяo������A��ʂ��Â��Ȃ��āA�G���^�[�L�[���������������N���X

*/
class CBB : public CObjectBase
{
public:
	CBB(const int time);
	~CBB();
	void Update();
private:
	int m_cnt;	//50���J�E���g
	int m_time;	//50���ҋ@���ԁi�����Ŏw��j
};
#endif // !BB_GUARD
