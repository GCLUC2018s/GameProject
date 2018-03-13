#include "myLib.h"

const int OFFSET = 10;
const int CHIPSIZE = 60;

//Vector2D�ւ̉��Z
CVector2D& CVector2D::operator+=(const CVector2D& ope){
	pos_x += ope.pos_x;
	pos_y += ope.pos_y;
	return *this;
}

//Vector2D����̌��Z
CVector2D& CVector2D::operator-=(const CVector2D& ope){
	pos_x -= ope.pos_x;
	pos_y -= ope.pos_y;
	return *this;
}
//Vector2D�ւ̑��
CVector2D& CVector2D::operator=(const CVector2D& ope){
	pos_x = ope.pos_x;
	pos_y = ope.pos_y;
	return *this;
}
CVector2D& CVector2D::operator+(const CVector2D&ope){
	pos_x += ope.pos_x;
	pos_y += ope.pos_y;
	return *this;
}
int CVector2D::operator==(const CVector2D&ope){
	if (pos_x == ope.pos_x &&
		pos_y == ope.pos_y)
		return 1;
	return 0;
}

int CVector2D::operator!=(const CVector2D&ope){
	if (pos_x != ope.pos_x ||
		pos_y != ope.pos_y)
		return 1;
	return 0;
}

bool IsXKeyTrigger(int key){
	static int g_akey_prev;
	if (key & PAD_INPUT_X){
		if (g_akey_prev == false){
			g_akey_prev = true;
			return true;
		}
	}
	else{
		g_akey_prev = false;
	}
	return false;
}

//�ԋp�l�@TRUE:�Փˁ@FALSE:��Փ�
bool IsHitBox(CVector2D pos1, CVector2D pos2,int type){
	float CHIP_SIZEX = 0;
	float CHIP_SIZEY = 0;
	switch (type)
	{
	case 0:
		CHIP_SIZEX = 120;
		CHIP_SIZEY = 120;
		break;
	case 1:
		CHIP_SIZEX = 180;
		CHIP_SIZEY = 180;
		break;
	case 2:
		CHIP_SIZEX = 60;
		CHIP_SIZEY = 120;
		break;
	default:
		CHIP_SIZEX = 60;
		CHIP_SIZEY = 60;
		break;
	}
	float ax1 = pos1.getX() + OFFSET;				//����X
	float ay1 = pos1.getY() + OFFSET;				//����Y
	float ax2 = pos1.getX() + CHIPSIZE - OFFSET;	//�E��X
	float ay2 = pos1.getY() + CHIPSIZE - OFFSET;	//�E��Y

	float bx1 = pos2.getX() + OFFSET;				//����X
	float by1 = pos2.getY() + OFFSET;				//����Y
	float bx2 = pos2.getX() + CHIP_SIZEX - OFFSET;	//�E��X
	float by2 = pos2.getY() + CHIP_SIZEY - OFFSET;	//�E��Y

	if ((ax1 < bx2) && (bx1 < ax2) && (ay1 < by2) && (by1 < ay2))return TRUE;
	return FALSE;
}