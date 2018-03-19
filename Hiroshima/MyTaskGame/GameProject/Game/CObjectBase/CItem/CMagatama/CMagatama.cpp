#include "CMagatama.h"
#include "../GameProject/Game/CObjectBase/CMahouzin/CMahouzin.h"

CMagatama::CMagatama() :CObjectBase(eID_Magatama, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(100, 100);
	m_pos3D = CVector3D(20, 20, 0);
	m_cnt = 0;
}

CMagatama::~CMagatama() {

}

void CMagatama::Update()
{
	if (PUSH_Q) {
		if (m_cnt >= 10) SetAttack();
		else SOUND("SE_BB")->Play(false);
	}
}

void CMagatama::Draw()
{
	m_img.SetRect(128 * m_cnt, 0, 128 + 128 * m_cnt, 128);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
}

void CMagatama::Hit(CObjectBase * t) {
	if (m_cnt < 10)
		m_cnt++;
}

void CMagatama::SetAttack()
{
	//この中で魔法陣を呼ぶ。
	//手順は
	/*
	m_cntが10以上なら0に戻す
	その後必殺技を呼ぶ

	*/
	m_cnt = 0;
	new CMahouzin();
	SOUND("SE_KKN")->Play(false);
	//カットイン発動
	//必殺技発動
}

