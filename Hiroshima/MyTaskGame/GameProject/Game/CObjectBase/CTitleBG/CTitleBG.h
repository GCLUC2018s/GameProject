#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#include "../CObjectBase.h"

/*

����ҁ@�{��

*/
class CTitleBG : public CObjectBase
{
public:
	//�^�C�g���摜
	CTitleBG();
	~CTitleBG();
	void Update();
private:
	bool m_end_flag;	//�G���^�[�����ꂽ�̂ŏI���܂���t���O
};

#endif // !TITLE_BG_GUARD
