#pragma once
#include "CBase.h"
//���̃u���b�N��
#define MAP_WIDTH    32
//�c�̃u���b�N��
#define MAP_HEIGHT   11
//�u���b�N�̃T�C�Y
#define MAP_TIP_SIZE 64

class CMap :public CBase {
private:
	CImage backGround;
public:
	CMap();
	~CMap();
	void Draw();
	int GetTipNo(int x, int y, int *px = nullptr, int *py = nullptr);
};
extern CMap *g_map;