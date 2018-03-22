#include "CTitleBG.h"
#include "../GameProject/Game/CScene/CSceneManager.h"
#include "../CBB/CBB.h"

CTitleBG::CTitleBG() :CObjectBase(0, eU_Back, eD_Back)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title"));
	m_img_rogo = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title_rogo"));
	m_img_rogo_s = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title_rogo_s"));
	m_img_start = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title_start"));
	m_img_start_2 = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title_start"));
	m_img_huda = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title_huda"));

	//SIZ
	m_st_siz = CVector2D(START_SIZ_X / 2, START_SIZ_Y / 2);
	m_logo_siz = CVector2D(ROGO_SIZ_X / 2, ROGO_SIZ_Y / 2);
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_img_rogo.SetSize(ROGO_SIZ_X, ROGO_SIZ_Y);
	m_img_rogo_s.SetSize(ROGO_SIZ_X, ROGO_SIZ_Y);
	m_img_huda.SetSize(544, 544);
	m_img_start.SetSize(START_SIZ_X, START_SIZ_Y);
	m_img_start_2.SetSize(m_st_siz);

	//center
	m_img_start_2.SetCenter(START_SIZ_X / 2, START_SIZ_Y / 2);
	m_img_rogo_s.SetCenter(ROGO_SIZ_X / 2, ROGO_SIZ_Y / 2);
	m_img_huda.SetCenter(544 / 2, 544 / 2);

	//POS
	m_img.SetPos(0, 0);
	m_img_rogo.SetPos(749, 0);
	m_img_rogo_s.SetPos(749 + m_logo_siz.x, 0 + m_logo_siz.y);
	m_img_start.SetPos(820, 595);
	m_img_start_2.SetPos(820 + m_st_siz.x, 595 + m_st_siz.y);
	m_img_huda.SetPos(712 + 544 / 2, 45 + 544 / 2);
	//col
	m_color = CColorRGBA(1.0, 1.0, 1.0, 1.0);
	m_col_rogo = CColorRGBA(1.0, 1.0, 1.0, 1.0);
	m_col_rogo_s = CColorRGBA(1.0, 1.0, 1.0, 0.0);
	m_col_start = CColorRGBA(1.0, 1.0, 1.0, 1.0);
	m_col_start_2 = CColorRGBA(1.0, 1.0, 1.0, 0.0);
	m_img_huda.SetColor(1, 1, 1, 1);

	m_sabun_flag = false;
	m_end_flag = false;
	m_f_time = 0.0;
	m_time = 0;
	m_log_time = 0;
	m_ohuda_time = 0.0;
}

CTitleBG::~CTitleBG()
{
	//ここ、変更するかも
	//メインに移動してる
	NEW_SCENE(eMain)
}

void CTitleBG::Update()
{
	RogoUpdate();
	PushStartUpdate();

	if (m_end_flag) {
		//もう一個のプッシュスタートがほわーーーってなる
		m_col_start_2.w -= 0.01;
		m_st_siz.x += 3.5 * 0.2;
		m_st_siz.y += 1 * 0.2;
	}

	if (m_end_flag)m_time++;
	if (m_end_flag && m_time > 60 * 2) {
		if (m_f_time == 0.0) {
			new CBB(0, 0, false);
		}
		m_f_time -= BB_COL_DOWN_2;
	}
	if (m_f_time < -3.0) {
		SetKill();
	}
}

void CTitleBG::Draw()
{
	m_img_start_2.SetSize(m_st_siz * 2);
	m_img_start_2.SetCenter(m_st_siz);
	m_img_rogo_s.SetSize(m_logo_siz * 2);
	m_img_rogo_s.SetCenter(m_logo_siz);


	//色
	m_img.SetColor(1, 1, 1, m_color.w);
	m_img_rogo.SetColor(1, 1, 1, m_col_rogo.w);
	m_img_rogo_s.SetColor(1, 1, 1, (m_col_rogo_s.w) / 1.3);
	m_img_start.SetColor(1,1,1, m_col_start.w);
	m_img_start_2.SetColor(1,1,1, m_col_start_2.w);
	//描画
	m_img.Draw();
	m_img_huda.Draw();
	m_img_rogo.Draw();
	m_img_rogo_s.Draw();
	m_img_start.Draw();
	m_img_start_2.Draw();
}

void CTitleBG::RogoUpdate()
{
	//お札回転
	m_ohuda_time += 0.005;
	m_img_huda.SetAng(m_ohuda_time);

	m_log_time++;
	if (m_col_rogo_s.w <= 0.0) {
		m_sabun_flag = true;
	}
	if (m_sabun_flag) {
		m_logo_siz = CVector2D(ROGO_SIZ_X / 2, ROGO_SIZ_Y / 2);
		if (m_log_time % 200 == 0) {
			m_col_rogo_s.w = 1.0;
			m_sabun_flag = false;
		}
	}
	else {
		m_logo_siz += CVector2D(0.66, 1);
		FadeOut(&m_col_rogo_s.w);
	}
}

void CTitleBG::PushStartUpdate()
{
	if (m_end_flag == false && PUSH_ENTER) {
		SOUND("SE_Title_Enter")->Play(false);
		m_col_start_2.w = 1.0;
		m_end_flag = true;
	}

}

void CTitleBG::FadeIn(float *a)
{
	(*a) += 0.5;
}

void CTitleBG::FadeOut(float *a)
{
	(*a) -= 0.005;
}
