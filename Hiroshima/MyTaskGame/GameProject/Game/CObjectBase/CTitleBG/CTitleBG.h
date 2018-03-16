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
	CAnimImage m_img_rogo;		//���S�摜
	CAnimImage m_img_rogo_s;	//���S�摜����
	CAnimImage m_img_start;	//���S�摜����
	bool m_end_flag;			//�G���^�[�����ꂽ�̂ŏI���܂���t���O
	bool m_pika_flag;			//false�Ȃ�҂���������Btrue�Ȃ�҂����o��
	void BGUpdate();			//�^�C�g���摜�{�̂̃A�b�v�f�[�g
	void RogoUpdate();			//���S�摜�{�̂̃A�b�v�f�[�g
	void PushStartUpdate();		//PushStart�摜�{�̂̃A�b�v�f�[�g

};

#endif // !TITLE_BG_GUARD
