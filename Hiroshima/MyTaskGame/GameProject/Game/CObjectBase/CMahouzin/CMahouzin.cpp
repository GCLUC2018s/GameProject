#include "CMahouzin.h"
#include "../CPlayer/CPlayer.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CBB/CBB.h"
#include "../GameProject/Game/CObjectBase/CItem/COhuda/COhuda.h"
#include "../CMGHit/CMGHit.h"

/*

àÍïîï“èWÅ@ã{˙±

*/

CMahouzin::CMahouzin() : CObjectBase(eID_UI, eU_UI, eD_Ground) {
	new CBB(60 * 5, 0, true);
	m_deathblow = true;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Mahouzin"));
	m_img_ef = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_aura2"));
	m_img.SetSize(256, 128);
	m_img.SetCenter(64, -150);
	m_img_ef.SetSize(680, 657);
	m_img_ef.SetCenter(276, 248);
	PL = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(eID_Player));
	new CMGHit(PL->GetPos());
	m_pos3D = PL->GetPos();
	SOUND("SE_Mahou_Charge")->Play(false);
	m_time = 0;
	m_size = 0;
	m_img_ef.ChangeAnimation(0);
}

CMahouzin::~CMahouzin()
{
	m_deathblow = false;
}

void CMahouzin::Update(){
	m_time++;
	if (m_time > 60 * 4) {
		if (m_size == 0) {
			new COhuda(m_pos3D, PL->GetFlip());
			SOUND("SE_Mahou_Charge")->Stop();
			SOUND("SE_Mahou_Kaen")->Play(false);
		}
		m_size+=5;
		m_color.w -= 0.01;
	}
	if (m_color.w < 0) {
		SetKill();
	}
	m_img_ef.UpdateAnimation();
}

void CMahouzin::Draw() {
	//SetSize
	m_img.SetSize(256 + m_size * 2, 128 + m_size);
	m_img_ef.SetSize(680 + m_size * 2 * 2.656, 657 + m_size * 2.566);
	//SetCenter
	m_img.SetCenter(64 + m_size, -150 + m_size / 2);
	m_img_ef.SetCenter(276 + m_size * 2.656, 248 + m_size * 1.567);
	//SetColor
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img_ef.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	//SetPos
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img_ef.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	//Draw
	m_img_ef.Draw();
	m_img.Draw();
}