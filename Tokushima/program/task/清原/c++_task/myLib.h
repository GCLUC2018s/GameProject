#ifndef myLib_H
#define myLib_H

//ヘッダーファイル
#include "DxLib.h"
#include "assert.h"
#include "memory.h"

//プリプロセッサ
//#define STRUCT_ZERO_CLEAR(X)		memset(&X, 0,sizeof(X))
#define FPS							(60)
#define FRAMETIME					(0.016666)		//(1.0f/FPS)
#define DEG2RAD						(0.0174528)		//(0.0174f)
#define ARRAY_SIZE(a)				(sizeof(a)/sizeof(a[0]))

BOOL IsKeyTrigger(int key);

#endif myLib_H
