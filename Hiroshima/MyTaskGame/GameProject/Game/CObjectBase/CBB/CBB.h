#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

#define BB_COL_PA 0.7 //�ǂ̔Z���Ŏ~�߂邩�B
#define BB_COL_DOWN 0.05 //�ǂꂭ�炢�����炷��
#define BB_COL_DOWN_2 0.01 //�ǂꂭ�炢�����炷��2
/*

����ҁ@�{��

*/
class CBB : public CObjectBase
{
public:
	//�Ăяo������t�F�[�h�A�E�g�C������
	//�\���b���i���̊ԁA�v���C���[�͑���s�\�j,	true�Ȃ�u�G��|���I�v�\��,true�Ȃ�A���񂾂񍕂��Ȃ�
	CBB(const int &time, const int &flag, const bool &flagin);
	~CBB();
	void Update();
	void Draw();
private:
	int m_cnt;	//50���J�E���g
	int m_time;	//50���ҋ@���ԁi�����Ŏw��j
	//1�Ȃ�A�u�G��|���I�v�\��
	//2�Ȃ�ABoss�Ɉړ�
	int m_flag; 
	bool m_in_flag; //true�Ȃ�A���񂾂񍕂��Ȃ�
};
#endif // !BB_GUARD
