#include "CCollider.h"
#include "task\CTaskManager.h"
#include "math.h"
/*
�����͍����珇��
���g
���g�̉e
�Ώۑ���
�Ώۑ���̉e
*/
bool C_Collider::Collision(C_Object* ip_MyCol, C_Object* ip_YouCol, C_Vector3* ip_MyShadowCol, C_Vector3* ip_YouShadowCol){
	if (ip_MyCol->m_Colimage.m_Enabled&&ip_YouCol->m_Colimage.m_Enabled){
		//�����蔻�����
		//fabs���g���A��Βl�̒l(����)�����g�ƑΏۑ���̒l(����)�����傫���ꍇ
		if (fabs(ip_MyShadowCol->z - ip_YouShadowCol->z) > ip_MyCol->m_Objvalue + ip_YouCol->m_Objvalue){
			//return�ŕԂ�
			return false;
		}
		else{
			//z���̔���
			//C_Collider::CCollisionY(ip_MyCol, ip_YouCol);
			//return true;
			//x���̔���
			if (ip_MyCol->m_Colimage.m_Left >= ip_YouCol->m_Colimage.m_Right ||
				ip_MyCol->m_Colimage.m_Right <= ip_YouCol->m_Colimage.m_Left ||
				ip_MyCol->m_Colimage.m_Bottom >= ip_YouCol->m_Colimage.m_Top ||
				ip_MyCol->m_Colimage.m_Top <= ip_YouCol->m_Colimage.m_Bottom){
				return false;
			}
			else{
				//ip_Col1���Aip_Col2�E����̏ꍇ
				//������
				if (ip_MyCol->m_Colimage.m_Left >= ip_YouCol->m_Colimage.m_Left){
					ip_MyCol->m_Colimage.m_AdjustX = ip_YouCol->m_Colimage.m_Right - ip_MyCol->m_Colimage.m_Left;
				}
				//ip_Col1�E�Aip_Col2������̏ꍇ
				//�E����
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
	//ip_Col1��ip_Col2���ǂ�������݂���ꍇ
	if (ip_Col1->m_Colimage.m_Enabled&&ip_Col2->m_Colimage.m_Enabled){
		if (ip_Col1->m_Colimage.m_Left >= ip_Col2->m_Colimage.m_Right ||
			ip_Col1->m_Colimage.m_Right <= ip_Col2->m_Colimage.m_Left ||
			ip_Col1->m_Colimage.m_Bottom >= ip_Col2->m_Colimage.m_Top ||
			ip_Col1->m_Colimage.m_Top <= ip_Col2->m_Colimage.m_Bottom){
			return false;
		}
		//ip_Col1���Aip_Col2�㔻��
		//�㔻��
		if (ip_Col1->m_Colimage.m_Bottom >= ip_Col2->m_Colimage.m_Bottom){
			ip_Col1->m_Colimage.m_AdjustZ = ip_Col2->m_Colimage.m_Top - ip_Col1->m_Colimage.m_Bottom;
			return true;
		}
		//ip_Col1��Aip_Col2������
		//������
		if (ip_Col1->m_Colimage.m_Top <= ip_Col2->m_Colimage.m_Top){
			ip_Col1->m_Colimage.m_AdjustZ = ip_Col2->m_Colimage.m_Bottom - ip_Col1->m_Colimage.m_Top;
			return true;
		}
	}
	return false;
}