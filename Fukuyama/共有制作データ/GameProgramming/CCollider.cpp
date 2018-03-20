#include "CCollider.h"
#include "task\CTaskManager.h"
#include "math.h"
/*
引数は左から順に
自身
自身の影
対象相手
対象相手の影
*/
bool C_Collider::Collision(C_Object* ip_MyCol, C_Object* ip_YouCol, C_Vector3* ip_MyShadowCol, C_Vector3* ip_YouShadowCol){
	if (ip_MyCol->m_Colimage.m_Enabled&&ip_YouCol->m_Colimage.m_Enabled){
		//あたり判定条件
		//fabsを使い、絶対値の値(距離)が自身と対象相手の値(距離)よりも大きい場合
		if (fabs(ip_MyShadowCol->z - ip_YouShadowCol->z) > ip_MyCol->m_Objvalue + ip_YouCol->m_Objvalue){
			//returnで返す
			return false;
		}
		else{
			//z軸の判定
			//C_Collider::CCollisionY(ip_MyCol, ip_YouCol);
			//return true;
			//x軸の判定
			if (ip_MyCol->m_Colimage.m_Left >= ip_YouCol->m_Colimage.m_Right ||
				ip_MyCol->m_Colimage.m_Right <= ip_YouCol->m_Colimage.m_Left ||
				ip_MyCol->m_Colimage.m_Bottom >= ip_YouCol->m_Colimage.m_Top ||
				ip_MyCol->m_Colimage.m_Top <= ip_YouCol->m_Colimage.m_Bottom){
				return false;
			}
			else{
				//ip_Col1左、ip_Col2右判定の場合
				//左判定
				if (ip_MyCol->m_Colimage.m_Left >= ip_YouCol->m_Colimage.m_Left){
					ip_MyCol->m_Colimage.m_AdjustX = ip_YouCol->m_Colimage.m_Right - ip_MyCol->m_Colimage.m_Left;
				}
				//ip_Col1右、ip_Col2左判定の場合
				//右判定
				if (ip_MyCol->m_Colimage.m_Right <= ip_YouCol->m_Colimage.m_Right){
					ip_MyCol->m_Colimage.m_AdjustX = ip_YouCol->m_Colimage.m_Left - ip_MyCol->m_Colimage.m_Right;
				}
				return true;
			}
		}
	}
	return false;
}

bool C_Collider::CCollisionY(C_Object *ip_Col1, const C_Object *ip_Col2){
	ip_Col1->m_Colimage.m_AdjustZ = 0.0f;
	//ip_Col1とip_Col2がどちらも存在する場合
	if (ip_Col1->m_Colimage.m_Enabled&&ip_Col2->m_Colimage.m_Enabled){
		if (ip_Col1->m_Colimage.m_Left >= ip_Col2->m_Colimage.m_Right ||
			ip_Col1->m_Colimage.m_Right <= ip_Col2->m_Colimage.m_Left ||
			ip_Col1->m_Colimage.m_Bottom >= ip_Col2->m_Colimage.m_Top ||
			ip_Col1->m_Colimage.m_Top <= ip_Col2->m_Colimage.m_Bottom){
			return false;
		}
		//ip_Col1下、ip_Col2上判定
		//上判定
		if (ip_Col1->m_Colimage.m_Bottom >= ip_Col2->m_Colimage.m_Bottom){
			ip_Col1->m_Colimage.m_AdjustZ = ip_Col2->m_Colimage.m_Top - ip_Col1->m_Colimage.m_Bottom;
			return true;
		}
		//ip_Col1上、ip_Col2下判定
		//下判定
		if (ip_Col1->m_Colimage.m_Top <= ip_Col2->m_Colimage.m_Top){
			ip_Col1->m_Colimage.m_AdjustZ = ip_Col2->m_Colimage.m_Bottom - ip_Col1->m_Colimage.m_Top;
			return true;
		}
	}
	return false;
}