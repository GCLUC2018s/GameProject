#ifndef myLib_H
#define myLib_H

//�w�b�_�[�t�@�C��
#include "DxLib.h"
#include "assert.h"
#include "memory.h"

//�v���v���Z�b�T
//#define STRUCT_ZERO_CLEAR(X)		memset(&X, 0,sizeof(X))
#define FPS							(60)
#define FRAMETIME					(0.016666)		//(1.0f/FPS)
#define DEG2RAD						(0.0174528)		//(0.0174f)
#define ARRAY_SIZE(a)				(sizeof(a)/sizeof(a[0]))

BOOL IsKeyTrigger(int key);

#endif myLib_H
