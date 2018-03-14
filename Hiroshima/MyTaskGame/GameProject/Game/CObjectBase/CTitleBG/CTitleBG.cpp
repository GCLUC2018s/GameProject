#include "CTitleBG.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CTitleBG::CTitleBG() :CObjectBase(0, eU_Back, eD_Null)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_end_flag = false;
	m_color.a = 0.0;
}

CTitleBG::~CTitleBG()
{
	//�����A�ύX���邩��
	//���C���Ɉړ����Ă�
	NEW_SCENE(eMain)
}

void CTitleBG::Update()
{
	m_img.SetColor(m_color.r, m_color.g, m_color.b, m_color.a);
	if (m_end_flag == false) {
		m_color.a += 0.05;
		if (PUSH_ENTER) {
			//�t�F�[�h�A�E�g�t���O���Ă�
			SOUND("SE_Title_Enter")->Play(false);
			m_end_flag = true;
			m_color.a = 2.0;
		}
	}else {
		//�t�F�[�h�A�E�g
		m_color.a -= 0.01;
	}
	if (m_color.a < -1.0) {
		SetKill();
	}
}
