#include "CObjectBase.h"
#include "CPlayer\CPlayer.h"
#include "CFieldBG\CFieldGround\CFieldGround.h"

CVector2D CObjectBase::m_scroll(0, 0);
bool CObjectBase::m_wave_flag = true;
bool CObjectBase::m_sc_flag_x = false;
int CObjectBase::m_score = 0;
bool CObjectBase::m_deathblow = false;

CObjectBase::CObjectBase(int id, int updatePrio, int drawPrio) :
	CTask(id, updatePrio, drawPrio) ,
	m_pos3D(0, 0, 0),
	m_vec3D(0, 0, 0),
	m_flipH(false),
	m_type(0),
	m_move(false),
	m_color(1.0, 1.0, 1.0, 1.0){
}

void CObjectBase::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
//	Utility::DrawQuad(CVector2D(m_pos3D.x - m_scroll.x + m_rect.m_left, m_pos3D.y - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right, m_rect.m_bottom), CVector4D(1, 0, 0, 0.3));
}

void CObjectBase::HitCheck(CTask * t1, CTask * t2)
{

	if ((t1->GetID() == eID_Effect && t2->GetID() == eID_Enemy) ||
		(t2->GetID() == eID_Effect && t1->GetID() == eID_Enemy) || 
		(t1->GetID() == eID_Player && t2->GetID() == eID_Item) ||
		(t2->GetID() == eID_Player && t1->GetID() == eID_Item) || 
		(t1->GetID() == eID_Enemy && t2->GetID() == eID_Bullet) ||
		(t2->GetID() == eID_Enemy && t1->GetID() == eID_Bullet) || 
		(t1->GetID() == eID_Enemy && t2->GetID() == eID_Player) ||
		(t2->GetID() == eID_Enemy && t1->GetID() == eID_Player)){
		//PLとENEの判定
		CObjectBase* o1 = dynamic_cast<CObjectBase*>(t1);
		CObjectBase* o2 = dynamic_cast<CObjectBase*>(t2);
		if (abs(o1->m_pos3D.z - o2->m_pos3D.z) < 130 || m_deathblow) {
			if (o1->m_pos3D.x + o1->m_rect.m_right > o2->m_pos3D.x + o2->m_rect.m_left &&
				o1->m_pos3D.x + o1->m_rect.m_left  <o2->m_pos3D.x + o2->m_rect.m_right &&
				o1->m_pos3D.y + o1->m_rect.m_bottom>o2->m_pos3D.y + o2->m_rect.m_top &&
				o1->m_pos3D.y + o1->m_rect.m_top < o2->m_pos3D.y + o2->m_rect.m_bottom) {
				o1->Hit(o2);
				o2->Hit(o1);
			}
		}
	}
}
void CObjectBase::Hit(CObjectBase * t)
{
//	printf("hit\n");
}
////描画順序チェック関数
//void CObjectBase::CheckOverlapAll()
//{
//	//先頭から順にチェックしていく
//	CTaskLinker *p1 = mp_D_Top;
//	while (p1)
//	{
//		CTaskLinker *p2 = mp_D_Top;
//		while (p2)
//		{
//			if (p1 != p2 && p1->m_priority == eD_Chara && p2->m_priority == eD_Chara) {
//				p1->mp_task->CheckOverlap(p1->mp_task, p2->mp_task);
//			}
//			p2 = p2->mp_next;
//		}
//		p1 = p1->mp_next;
//	}
//
//}
////描画順位入れ替え
//void CObjectBase::SwapDrawPriority(CObjectBase * t)
//{
//	CTaskManager::GetInstance()->SwapDrawPrio(this, t);
//}
//
//
//void CObjectBase::CheckOverlap(CObjectBase * t1, CObjectBase * t2)
//{
//	if (t1->GetPos().y + t1->GetRect_F().m_bottom < t2->GetPos().y + t2->GetRect_F().m_bottom) {
//		//t2が手前にいなきゃいけないような配置で
//		//t1のほうが早く描画されてたら入れ替え
//		if (t1->GetDrawPrio() < t2->GetDrawPrio()) {
//			t1->SwapDrawPriority(t2);
//		}
//	}
//	else if (t1->GetPos().y + t1->GetRect_F().m_bottom > t2->GetPos().y + t2->GetRect_F().m_bottom) {
//		//t1が手前にいなきゃいけないような配置で
//		//t2のほうが早く描画されてたら入れ替え
//		if (t1->GetDrawPrio() > t2->GetDrawPrio()) {
//			t2->SwapDrawPriority(t1);
//		}
//	}
//}
