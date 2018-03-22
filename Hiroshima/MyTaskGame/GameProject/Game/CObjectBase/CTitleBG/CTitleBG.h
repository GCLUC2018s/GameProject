#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#define ROGO_SIZ_X 485
#define ROGO_SIZ_Y 735

#define START_SIZ_X 350
#define START_SIZ_Y 100

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
	CAnimImage m_img_start;		//�X�^�[�g�摜
	CAnimImage m_img_start_2;		//�X�^�[�g�摜
	CAnimImage m_img_huda;		//���D

	CColorRGBA m_col_rogo;			//���S�摜�J���[
	CColorRGBA m_col_rogo_s;		//���S�摜�����J���[
	CColorRGBA m_col_start;			//�X�^�[�g�摜�J���[
	CColorRGBA m_col_start_2;			//�X�^�[�g�摜�J���[

	CVector2D m_st_siz;
	CVector2D m_logo_siz;

	bool m_end_flag;			//�{���ɏI���܂���t���O
	bool m_sabun_flag;			//false�Ȃ獷����������Btrue�Ȃ獷�����o��
	float m_f_time;					//(�t�F�[�h�A�E�g�ʎQ�l)
	int   m_time;					//�G���^�[�L�[�������Ă���̎���(�t�F�[�h�A�E�g�ʎQ�l)

	int m_log_time;		//���S���o�[�����ĂȂ鎞��
	float m_ohuda_time;	//���D��]�p

	void RogoUpdate();			//���S�摜�{�̂̃A�b�v�f�[�g
	void PushStartUpdate();		//PushStart�摜�{�̂̃A�b�v�f�[�g
	void FadeIn(float *a);				//�t�F�[�h�C��
	void FadeOut(float *a);				//�t�F�[�h�A�E�g

};

#endif // !TITLE_BG_GUARD
