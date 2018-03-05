#include "CFlag.h"
#include "CMap.h"

CFlag::CFlag() :CBase(eTagUI) {
	m_img = g_image[eImageFlag];
	m_pos = CVector2D(64 * 3, 576);
	m_img.SetSize(64, 64);
	m_mask = MASK_PLAYER;
}
CFlag::~CFlag() {

}
void CFlag::Update() {
}