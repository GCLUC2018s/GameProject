#ifndef STDLIBRARY_H
#define STDLIBRARY_H

//ヘッダーファイル
#include "DxLib.h"
#include <stdio.h>
#include "assert.h"
#include "memory.h"

//プリプロセッサ
#define STRUCT_ZERO_CLEAR(X)		memset(&X, 0,sizeof(X))
#define FPS							(60)
#define FRAMETIME					(1.0f/FPS)
#define DEG2RAD						(0.0174f)

#endif STDLIBRARY_H
