#include "CEndeing.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

static std::string end[] = {
	"�@�@�@�@�@���ā@�u�ЂƁv�̑��Ɓu���₩���v�̑����������@�@�@�@",
	"�@�@�@�@ �@�@ �@�@�����������Ƃ͂Ȃ��������@�@�@�@�@�@�@�@�@�@�@\n�@�@ �@ �@�@�@�@�@�@�n�̍���Ȃ������������� �@�@�@�@�@�@�@�@�@�@",
	"�@�@�@ �@�@ �@�@�@�ӂ��̑��̒�����莝�̂� �@�@�@�@�@�@�@�@�@�@\n�@�@�@ �@�@�@�@�@�@�u�����́v�̑��ł������@�@�@�@�@�@�@�@�@�@�@�@",
	"�@�@�@�������@�u���₩���v�������u�ЂƁv���P���悤�ɂȂ����@�@�@",
	"�@�@�@�@�@�u�����́v�́u�ЂƁv�̑��Ɓu���₩���v�̑����@�@�@�@�@ \n�@�@�@�@�@�@�@�@�@�@���Ă̏�Ԃɖ߂����߁@�@�@�@�@�@�@�@�@�@�@�@",
	"�@�@�@�@�u�����́v�̑��̒��́@���̛ޏ��ł���u�t���v�Ɂ@�@�@�@�@",
	"�@�@�@ �@�w�u���₩���v�̒��ɂ����������Ȃ����x�Ɩ��� �@�@�@�@�@",
	"�@�@�@�t���́@�u���₩���v�̒��ɉ�ɍs�����̂ł������E�E�E�@",
	"�@�@�@�@�@�@�@�@�@ �u���₩���v�̑��̒��́@�@�@�@ �@�@�@�@�@�@�@",
	"�@ �w�܂�����̑��̎҂�����Ȉ��������Ă����Ƃ́@�m��Ȃ������x �@",
	"�@�@�@�@�@�@�@�@�w���̎҂ɂ͂��������Ă����x�@�@�@�@�@�@�@�@�@",
	"�@�@�w�u�ЂƁv�̑��ɂ����f���������Ɓ@����l�т����悤�x�@�@�@",
	"�@�������ā@�u�ЂƁv�̑��Ɓu���₩���v�̑��Ɓu�����́v�̑��́@�@\n�@�@�@�@�@�̂̂悤�ȁ@���a�Ȋ֌W�ɖ߂����̂ł������E�E�E�@�@�@�@",
};
CEnding::CEnding() :CObjectBase(0, eU_Back, eD_UI), font("HG�s����", 40)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("EndStaff"));
	m_img.SetSize(ENDEING_SIZ_X / 2, ENDEING_SIZ_Y / 2);
	m_img.SetCenter(ENDEING_SIZ_X / 4, 0);
	m_pos3D = CVector3D(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 1.2, 0);
	m_color.w = 0;
	SOUND("BGM_Ending")->Play(false);
	m_time = 0;
	m_taxt = 0;
	m_ac = true;
}

CEnding::~CEnding()
{
	SOUND("BGM_Ending")->Stop();
	NEW_SCENE(eGameStart)
}

void CEnding::Update()
{
	m_time++;
	if (m_taxt <= 12) {
		if (m_color.w == -1.0) {
			m_taxt++;
		}
		if (m_ac) {
			m_color.w += 0.05;
			if (m_color.w > 4.0)
				m_ac = false;
		}
		else {
			m_color.w -= 0.05;
			if (m_color.w < -1.0) {
				m_color.w = -1.0;
				m_ac = true;
			}
		}
	}else {
		if (m_pos3D.y - SCREEN_HEIGHT / 1.2 + ENDEING_SIZ_Y / 2 > 0){
			m_pos3D.y--;
			m_color.w = 2.0;
		}
		else
			m_color.w -= 0.01;

		if (m_color.w < -1.0) {
			SetKill();
		}
	}
}

void CEnding::Draw()
{
	font.Draw(0, m_pos3D.y - SCREEN_HEIGHT /1.5 , m_color.w, m_color.w, m_color.w, end[m_taxt].c_str());
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
	font.Draw(SCREEN_WIDTH / 2 - 250, m_pos3D.y - SCREEN_HEIGHT / 1.2 + ENDEING_SIZ_Y / 2 + 600, m_color.w, m_color.w, m_color.w, "���Ȃ��̓��_�́c�@%5d�_", m_score);
}