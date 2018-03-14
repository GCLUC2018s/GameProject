#include "CTitleBG.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CTitleBG::CTitleBG() :CObjectBase(0, eU_Back, eD_Null)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_img_pika = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title_pika"));
	m_img_pika.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_pika_flag = false;
	m_end_flag = false;
	m_color.a = 0.0;
	m_color.r = 0.0;
}

CTitleBG::~CTitleBG()
{
	//ここ、変更するかも
	//メインに移動してる
	NEW_SCENE(eMain)
}

void CTitleBG::Update()
{
	m_img_pika.SetColor(1, 1, 1, m_color.r);
	m_img.SetColor(1, 1, 1, m_color.a);
	if (m_end_flag == false) {
		m_color.a += 0.05;
		if (m_color.a > 1.0) {
			if (m_pika_flag) {
				m_color.r += 0.05;
				if (m_color.r > 2.0) {
					m_pika_flag = false;
				}
			}
			else {
				m_color.r -= 0.05;
				if (m_color.r < -2.0) {
					m_pika_flag = true;
				}
			}
		}
		if (PUSH_ENTER) {
			//フェードアウトフラグ立てる
			SOUND("SE_Title_Enter")->Play(false);
			m_end_flag = true;
			m_color.a = 2.0;

		}
		
	}
	else {
		//フェードアウト
		m_color.a -= 0.01;
		m_color.r -= 0.01;
	}
	if (m_color.a < -1.0) {
		SetKill();
	}
}

void CTitleBG::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
	m_img_pika.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img_pika.Draw();
//	Utility::DrawQuad(CVector2D(m_pos3D.x, m_pos3D.y), CVector2D(m_rect.m_right, m_rect.m_bottom), CVector4D(1, 0, 0, 0.5));
}
