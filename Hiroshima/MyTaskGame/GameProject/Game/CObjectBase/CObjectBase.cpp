#include "CObjectBase.h"

CVector2D CObjectBase::m_scroll(0, 0);

CObjectBase::CObjectBase(int id, int updatePrio, int drawPrio) :
	CTask(id, updatePrio, drawPrio) {
	m_pos3D = CVector3D(0, 0, 0);
	m_vec3D = CVector3D(0, 0, 0);
	m_flipH = false;
	m_type = 0;
	m_move = false;
	m_color = CColorRGBA(1.0, 1.0, 1.0, 1.0);
}
void CObjectBase::Draw()
{
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_scroll.x, m_pos3D.y - m_scroll.y);
	m_img.Draw();
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
