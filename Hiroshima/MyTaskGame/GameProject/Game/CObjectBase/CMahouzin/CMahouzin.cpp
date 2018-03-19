#include "CMahouzin.h"
#include "../CPlayer/CPlayer.h"
#include "../GameProject/Task/CTaskManager.h"

CMahouzin::CMahouzin() : CObjectBase(eID_UI, eU_UI, eD_Ground) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Mahouzin"));
	m_img.SetSize(256, 128);
	m_img.SetCenter(65, -300*2);
	CPlayer* PL = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(eID_Player));
	m_pos3D = PL->GetPos();
	m_time = 0;
}

CMahouzin::~CMahouzin()
{
}

void CMahouzin::Update(){
	m_time++;
	if (m_time < 300) {
		m_color.w -= 0.01;
	}
	if (m_color.w < 0) {
		SetKill();
	}
}
