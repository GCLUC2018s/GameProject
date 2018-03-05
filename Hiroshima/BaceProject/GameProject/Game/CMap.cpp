#include "CMap.h"

CMap *g_map;

int _map_tip[MAP_HEIGHT][MAP_WIDTH] = {
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

CMap::CMap() : CBase(eTagMap) {
	m_img = g_image[eImageMap];
	backGround = g_image[eImageBackGround];
}
CMap::~CMap() {

}
void CMap::Draw() {
	backGround.SetPos(-m_scroll.x / 2, 0);
	backGround.Draw();
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (_map_tip[i][j] == 0) continue;
			int x = _map_tip[i][j];
			m_img.Draw();
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);
			m_img.SetRect(64 * (x % 4), 64 * (x / 4), 64 + 64 * (x % 4), 64 + 64 * (x / 4));
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
		}
	}
}
int CMap::GetTipNo(int x, int y, int *px, int *py) {
	Utility::DrawQuad(CVector2D(x, y) - m_scroll, CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	int tx = x / MAP_TIP_SIZE;
	int ty = y / MAP_TIP_SIZE;
	if (tx < 0) tx = 0;
	if (tx > MAP_WIDTH - 1) tx = MAP_WIDTH - 1;
	if (ty < 0) ty = 0;
	if (ty > MAP_HEIGHT - 1) ty = MAP_HEIGHT - 1;
	if (px) *px = tx;
	if (py) *py = ty;
	return _map_tip[ty][tx];
}