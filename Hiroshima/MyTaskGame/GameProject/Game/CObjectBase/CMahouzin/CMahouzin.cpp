#include "CMahouzin.h"
#include "../CPlayer/CPlayer.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CBB/CBB.h"
#include "../GameProject/Game/CObjectBase/CItem/COhuda/COhuda.h"

CMahouzin::CMahouzin() : CObjectBase(eID_UI, eU_UI, eD_Ground) {
	new CBB(60 * 6, 0, true);
	m_deathblow = true;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Mahouzin"));
	m_img.SetSize(256, 128);
	m_img.SetCenter(64, -600);
	PL = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(eID_Player));
	m_pos3D = PL->GetPos();
	m_time = 0;
	m_size = 0;
}

CMahouzin::~CMahouzin()
{
	m_deathblow = false;
}

void CMahouzin::Update(){
	m_time++;
	if (m_time > 60 * 5) {
		if (m_size == 0) {
			new COhuda(m_pos3D, PL->GetFlip());
		}
		m_size+=5;
		m_img.SetSize(256 + m_size * 2, 128 + m_size);
		m_img.SetCenter(64 + m_size, -600 + m_size/2 );
		m_color.w -= 0.01;
	}
	if (m_color.w < 0) {
		SetKill();
	}
}

void CMahouzin::Draw() {
	
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();

}