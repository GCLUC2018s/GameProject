#include"CBossStage.h"
#include"../GameProject/Game/CObjectBase/CEnemy/CBoss.h"

CBossStage::CBossStage() :CObjectBase(eID_Ground, eU_Map, eD_Ground){
	m_state = eBossGround;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("BossStage"));
	m_img.SetSize(SCREEN_WIDTH, 1200);
	m_img.SetCenter(0, 1200 - SCREEN_HEIGHT);
	m_img.SetPos(0, 0);
	new CBoss(&(CVector3D(500, -200, -500)), &(CVector3D(350, 0, -500)),
		&(CVector3D(650, 0, -500)), &(CVector3D(500, 200, -500)));
}

CBossStage::~CBossStage() {

}

void CBossStage::Draw() {
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
}