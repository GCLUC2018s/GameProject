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
	void Draw();
private:
	bool m_end_flag;	//�G���^�[�����ꂽ�̂ŏI���܂���t���O
	CAnimImage m_img_pika;
	bool m_pika_flag;	//false�Ȃ�҂���������Btrue�Ȃ�҂����o��
};

#endif // !TITLE_BG_GUARD
