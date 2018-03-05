#pragma once
#include "CBase.h"
//横のブロック数
#define MAP_WIDTH    32
//縦のブロック数
#define MAP_HEIGHT   11
//ブロックのサイズ
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