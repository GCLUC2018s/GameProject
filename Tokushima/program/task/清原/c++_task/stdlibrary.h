#ifndef STDLIBRARY_H
#define STDLIBRARY_H

//�w�b�_�[�t�@�C��
#include "DxLib.h"
#include <stdio.h>
#include "assert.h"
#include "memory.h"

//�v���v���Z�b�T
#define STRUCT_ZERO_CLEAR(X)		memset(&X, 0,sizeof(X))
#define FPS							(60)
#define FRAMETIME					(1.0f/FPS)
#define DEG2RAD						(0.0174f)

#endif STDLIBRARY_H
