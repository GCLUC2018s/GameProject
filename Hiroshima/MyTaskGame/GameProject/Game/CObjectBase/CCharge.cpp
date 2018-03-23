#include "CCharge.h"
#include "CBress.h"
#include "../GameProject/Game/CObjectBase/CEnemy/BossBase.h"

CCharge::CCharge(CVector2D pos, bool flag){
	m_effect_type = eBress;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_charge"));
	m_pos2D = pos;
	m_pos3D.x = pos.x;
	m_pos3D.y = pos.y;
	m_img.SetCenter(120, 120);
	m_rect = CRect(-120, -120, 0, 0);
	m_img.SetPos(m_pos2D);
	m_flag = flag;
	CheckOverlap();
}

void CCharge::Update() {
	if (m_flag) {
		if (m_img.GetIndex() == 10) {
			new CBress(m_pos2D);
			SetKill();
		}
		m_img.ChangeAnimation(0, false);
		m_img.UpdateAnimation();
		CheckOverlap();
	}
	else {
		//CBossBase *ene = dynamic_cast<CBossBase*>(CTaskManager::GetInstance()->GetTask(eID_Boss));
		//m_pos3D.x = ene->GetPos().x;
	}
}

void CCharge::Draw(){
		m_img.SetPos(m_pos2D.x, m_pos2D.y - m_scroll.y);
		m_img.Draw();
		//Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7/*+ m_variation*/ - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));

}
