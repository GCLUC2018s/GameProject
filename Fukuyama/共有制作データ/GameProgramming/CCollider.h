#ifndef CCOLLIDER_H
#define CCOLLIDER_H
#include "object\C_Object.h"

//�{�b�N�Xx�{�b�N�X�̂����蔻��
class C_BoxCollider{
public:
	static bool CCollisionX(C_Rectangle *mp_R1, const C_Rectangle &i_R2); //���E�Փ˔���,r1�͏Փ˂��ɍs����,r2�͏Փ˂�����
	static bool CCollisionY(C_Rectangle *mp_R1, const C_Rectangle &i_R2); //�㉺�Փ˔���,r1�͏Փ˂��ɍs����,r2�͏Փ˂�����
};
#endif