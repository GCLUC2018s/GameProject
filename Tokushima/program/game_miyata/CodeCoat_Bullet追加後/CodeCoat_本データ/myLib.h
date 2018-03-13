#ifndef __MYLIB_H__
#define __MYLIB_H__

//ヘッダファイル
#include <DxLib.h>
#include "assert.h"
#include "memory.h"

#pragma once

//プリプロセッサ
//#define STRUCT_ZERO_CLEAR(X) memset( &X, 0, sizeof(X))
#define FPS (60)
#define FRAMETIME (0.0166666)//=(1.0f/FPS)
#define DEG2RAD (0.0174f) //=(2.0f*3.1415f/360.0f)
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define PI    3.1415926535897932384626433832795f
#define CHECK(a,b)					((a)&(1<<(b)))
const int IMG_CHIPSIZE = 60;

//列挙体
enum AtariInfo{ UL, UR, DL, DR, GL, GR ,HL,HR,ML,MR}; //主人公の各辺と一マス上下の左右の点

//キートリガー処理
bool IsXKeyTrigger(int key);

class CVector2D{
private:
	float pos_x;
	float pos_y;
public:
	CVector2D() :pos_x(0), pos_y(0){};
	CVector2D(float x, float y) :pos_x(x), pos_y(y){};
	float getX(void){ return pos_x; }
	float getY(void){ return pos_y; }
	void setX(float x){ pos_x = x; }
	void setY(float y){ pos_y = y; }

	//Vector2Dへの加算
	CVector2D& operator+=(const CVector2D& ope);
	//Vector2Dからの減算
	CVector2D& operator-=(const CVector2D& ope);
	//Vector2Dへの代入
	CVector2D& operator=(const CVector2D& ope);
	CVector2D& operator+(const CVector2D&ope);
	int operator==(const CVector2D&ope);
	int operator!=(const CVector2D&ope);
};

//ボックス判定処理
bool IsHitBox(CVector2D pos1, CVector2D pos2,int type);

#endif __MYLIB_H__