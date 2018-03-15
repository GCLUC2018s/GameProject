#include "CMagatama.h"

CMagatama::CMagatama() :CObjectBase(0, eU_Item, eD_Item) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Magatama"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(128, 128);

}

CMagatama::~CMagatama() {

}

void CMagatama::Update() {
	if (m_pos3D.x < SCREEN_WIDTH  && m_pos3D.x - SCREEN_WIDTH) {
		m_scroll.x = m_pos3D.x - SCREEN_WIDTH;
	}
}