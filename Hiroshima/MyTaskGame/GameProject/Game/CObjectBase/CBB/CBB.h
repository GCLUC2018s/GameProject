#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

����ҁ@�{��

*/
class CBB : public CObjectBase
{
public:
	//�Ăяo������A��ʂ��Â��Ȃ��āA�G���^�[�L�[���������������N���X
	//�\���b���i���̊ԁA�v���C���[�͑���s�\�j,	true�Ȃ�u�G��|���I�v�\��
	CBB(const int time,const bool flag);
	~CBB();
	void Update();
private:
	int m_cnt;	//50���J�E���g
	int m_time;	//50���ҋ@���ԁi�����Ŏw��j
//	bool m_flag; //true�Ȃ�A�u�G��|���I�v�\��
};
#endif // !BB_GUARD
