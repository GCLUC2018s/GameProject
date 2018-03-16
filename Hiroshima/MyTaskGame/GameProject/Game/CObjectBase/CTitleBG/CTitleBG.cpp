#include "CTitleBG.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CTitleBG::CTitleBG() :CObjectBase(0, eU_Back, eD_Null)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_end_flag = false;
	m_color.w = 0.0;
}

CTitleBG::~CTitleBG()
{
	//�����A�ύX���邩��
	//���C���Ɉړ����Ă�
	NEW_SCENE(eMain)
}

void CTitleBG::Update()
{
	BGUpdate();
	RogoUpdate();
	PushStartUpdate();
	
}

void CTitleBG::Draw()
{
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
}

void CTitleBG::BGUpdate()
{

	if (PUSH_ENTER) {
		//�t�F�[�h�A�E�g�t���O���Ă�
		SOUND("SE_Title_Enter")->Play(false);
		m_end_flag = true;
	}
	if (m_end_flag) {
		//�t�F�[�h�A�E�g
		m_color.a -= 0.01;
		m_color.w -= 0.01;
	}
	if (m_color.w < -1.0) {
		SetKill();
	}
}

void CTitleBG::RogoUpdate()
{
}

void CTitleBG::PushStartUpdate()
{
}
