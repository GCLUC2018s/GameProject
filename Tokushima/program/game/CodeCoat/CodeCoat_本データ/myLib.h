#ifndef __MYLIB_H__
#define __MYLIB_H__

//�w�b�_�t�@�C��
#include <DxLib.h>
#include "assert.h"
#include "memory.h"

#pragma once

//�v���v���Z�b�T
//#define STRUCT_ZERO_CLEAR(X) memset( &X, 0, sizeof(X))
#define FPS (60)
#define FRAMETIME (0.0166666)//=(1.0f/FPS)
#define DEG2RAD (0.0174f) //=(2.0f*3.1415f/360.0f)
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define PI    3.1415926535897932384626433832795f
#define CHECK(a,b)					((a)&(1<<(b)))
const int IMG_CHIPSIZE = 60;
const int SCREEN_SIZE_X = 1280;
const int ITEM_RAND = 5;		//�A�C�e���̃h���b�v�m��

//�񋓑�
enum AtariInfo{ UL, UR, DL, DR, GL, GR ,HL,HR,ML,MR}; //��l���̊e�ӂƈ�}�X�㉺�̍��E�̓_

//�L�[�g���K�[����
bool IsXKeyTrigger(int key);

class CVector3D{
private:
	float pos_x;
	float pos_y;
	float pos_z;
public:
	CVector3D() :pos_x(0), pos_y(0){};
	CVector3D(float x, float y,float z) :pos_x(x), pos_y(y),pos_z(z){};
	float getX(void){ return pos_x; }
	float getY(void){ return pos_y; }
	float getZ(void){ return pos_z; }
	void setX(float x){ pos_x = x; }
	void setY(float y){ pos_y = y; }
	void setZ(float z){ pos_z = z; }
	//Vector2D�ւ̉��Z
	CVector3D& operator+=(const CVector3D& ope);
	//Vector2D����̌��Z
	CVector3D& operator-=(const CVector3D& ope);
	//Vector2D�ւ̑��
	CVector3D& operator=(const CVector3D& ope);
	CVector3D& operator+(const CVector3D&ope);
	int operator==(const CVector3D&ope);
	int operator!=(const CVector3D&ope);
};

//�{�b�N�X���菈��
bool IsHitBox(CVector3D pos1, CVector3D pos2,int type);
bool IsHitCircle(float c1, float c2, CVector3D* pos1, CVector3D* pos2);
bool IsHitKeyTrigger(int key, int chk);

#endif __MYLIB_H__