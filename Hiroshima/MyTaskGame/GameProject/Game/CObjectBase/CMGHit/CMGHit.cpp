#include "CMGHit.h"
#include "../GameProject/Game/CObjectBase/CGimmick/CFire.h"
#include "../CEnemy/CEnemyBase.h"

CMGHit::CMGHit(CVector3D & pos) :CObjectBase(eID_Bullet, eU_Player, eD_Effect)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_aura1"));
	m_img.SetSize(680, 657);
	m_img.SetCenter(276, 248);
	m_pos3D = pos;
	m_pos3D.x++;
	m_time = 0;
	m_size = 0;
	m_img.ChangeAnimation(0);
	CheckOverlap();
}

CMGHit::~CMGHit()
{
}

void CMGHit::Update()
{
	m_time++;
	if (m_time > 60 * 4) {
		m_rect = CRect(-72 - m_size, -208 - m_size, 227 + m_size, 295 + m_size);
		m_size += 5;
		m_color.w -= 0.01;
	}
	if (m_color.w < 0) {
		SetKill();
	}
	m_img.UpdateAnimation();
}

void CMGHit::Draw()
{
	m_img.SetSize(680 + m_size * 2 * 2.656, 657 + m_size * 2.566);
	m_img.SetCenter(276 + m_size * 2.656, 248 + m_size * 1.567);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
}

void CMGHit::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Enemy) {
		CEnemyBase *Ene = dynamic_cast<CEnemyBase*>(t);
		if (Ene->GetHP() != -1)
			new CFire(t);
	}
}
