#include "CMagatama.h"
#include "../GameProject/Game/CObjectBase/CMahouzin/CMahouzin.h"
#include "../GameProject/Game/CObjectBase/CCutIn/CCutIn.h"

CMagatama::CMagatama(int a) :CObjectBase(eID_Magatama, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img_max = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_MagaMax"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(100, 100);
	m_pos3D = CVector3D(20, 20, 0);
	m_maga_cnt = a;
	m_img_max.SetSize(180, 180);
	m_img_max.SetPos(m_pos3D.x -40, m_pos3D.y -40);
	m_img_max.ChangeAnimation(1);
}

CMagatama::~CMagatama() {

}

void CMagatama::Update()
{
	if (PUSH_Q) {
		CObjectBase *PL = dynamic_cast<CObjectBase*>(CTaskManager::GetInstance()->GetTask(eID_Player));
		if (m_maga_cnt >= 10 && PL->GetPos().y == 0) SetAttack();
		else SOUND("SE_BB")->Play(false);
	}
	m_img_max.UpdateAnimation();
}

void CMagatama::Draw()
{
	if (m_maga_cnt >= 10) {
		m_img_max.Draw();
	}
	m_img.SetRect(128 * m_maga_cnt, 0, 128 + 128 * m_maga_cnt, 128);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
}

void CMagatama::Hit(CObjectBase * t) {
	if (m_maga_cnt < 10)
		m_maga_cnt++;
}

void CMagatama::SetAttack()
{
	//この中で魔法陣を呼ぶ。
	//手順は
	/*
	m_cntが10以上なら0に戻す
	その後必殺技を呼ぶ

	*/

	m_maga_cnt = 0;
	new CMahouzin();
	new CCutIn();
	//カットイン発動
	//必殺技発動
}

