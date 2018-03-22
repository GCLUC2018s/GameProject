#include "myLib.h"

const int OFFSET = 10;
const int CHIPSIZE = 60;

//Vector2Dへの加算
CVector3D& CVector3D::operator+=(const CVector3D& ope){
	pos_x += ope.pos_x;
	pos_y += ope.pos_y;
	pos_z += ope.pos_z;
	return *this;
}

//Vector2Dからの減算
CVector3D& CVector3D::operator-=(const CVector3D& ope){
	pos_x -= ope.pos_x;
	pos_y -= ope.pos_y;
	pos_z -= ope.pos_z;
	return *this;
}
//Vector2Dへの代入
CVector3D& CVector3D::operator=(const CVector3D& ope){
	pos_x = ope.pos_x;
	pos_y = ope.pos_y;
	pos_z = ope.pos_z;
	return *this;
}
CVector3D& CVector3D::operator+(const CVector3D&ope){
	pos_x += ope.pos_x;
	pos_y += ope.pos_y;
	pos_z += ope.pos_z;
	return *this;
	//return CVector3D(pos_x + ope.pos_x, pos_y + ope.pos_y, pos_z + ope.pos_z);
}
int CVector3D::operator==(const CVector3D&ope){
	if (pos_x == ope.pos_x &&
		pos_y == ope.pos_y &&
		pos_z == ope.pos_z)
		return 1;
	return 0;
}

int CVector3D::operator!=(const CVector3D&ope){
	if (pos_x != ope.pos_x ||
		pos_y != ope.pos_y ||
		pos_z != ope.pos_z)
		return 1;
	return 0;
}

bool IsXKeyTrigger(int key){
	static int g_akey_prev;
	if (key & PAD_INPUT_2){
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

bool IsHitCircle(float c1, float c2, CVector3D* pos1, CVector3D* pos2){
	float _length = c1 + c2;
	float _xsplint = pos1->getX() - pos2->getX();
	float _ysplint = pos1->getY() - pos2->getY();
	float _zsplint = pos1->getZ() - pos2->getZ();
	if (_length * _length >= _xsplint * _xsplint + _ysplint * _ysplint + _zsplint * _zsplint)
		return true;
	else
		return false;
}

//返却値　TRUE:衝突　FALSE:非衝突
bool IsHitBox(CVector3D pos1, CVector3D pos2,int type){
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
	float ax1 = pos1.getX() + OFFSET;				//左上X
	float ay1 = pos1.getY() + OFFSET;				//左下Y
	float ax2 = pos1.getX() + CHIPSIZE - OFFSET;	//右上X
	float ay2 = pos1.getY() + CHIPSIZE - OFFSET;	//右下Y

	float bx1 = pos2.getX() + OFFSET;				//左上X
	float by1 = pos2.getY() + OFFSET;				//左下Y
	float bx2 = pos2.getX() + CHIP_SIZEX - OFFSET;	//右上X
	float by2 = pos2.getY() + CHIP_SIZEY - OFFSET;	//右下Y

	if ((ax1 < bx2) && (bx1 < ax2) && (ay1 < by2) && (by1 < ay2))return TRUE;
	return FALSE;
}

bool IsHitKeyTrigger(int key, int chk){
	static int g_akey_prev;
	if (key & chk){
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