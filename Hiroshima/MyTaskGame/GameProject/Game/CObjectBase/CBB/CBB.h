#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

#define BB_COL_PA 0.7 //�ǂ̔Z���Ŏ~�߂邩�B
#define BB_COL_DOWN 0.02 //�ǂꂭ�炢�����炷��
/*

����ҁ@�{��

*/
class CBB : public CObjectBase
{
public:
	//�Ăяo������A��ʂ��Â��Ȃ��āA���΂炭�������������N���X
	//�\���b���i���̊ԁA�v���C���[�͑���s�\�j,	true�Ȃ�u�G��|���I�v�\��,true�Ȃ�t�F�[�h�C��
	CBB(const int time,const bool flag,const bool in_flag);
	~CBB();
	void Update();
	void Draw();
private:
	int m_cnt;	//50���J�E���g
	int m_time;	//50���ҋ@���ԁi�����Ŏw��j
	bool m_flag; //true�Ȃ�A�u�G��|���I�v�\��
	bool m_in_flag; //true�Ȃ�t�F�[�h�C��
};
#endif // !BB_GUARD
