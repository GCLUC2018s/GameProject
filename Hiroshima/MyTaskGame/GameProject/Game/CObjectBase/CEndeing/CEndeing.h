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
	CFont font;
	int m_time;			//�o�ߎ���
	int m_taxt;			//�\���ꏊ
	bool m_ac;			//�t�F�[�h�^�C�~���O�@true�Ȃ�v���X
};

#endif // !ENDEING_GUARD
