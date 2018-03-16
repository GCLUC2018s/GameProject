#include "CMagatama.h"

CMagatama::CMagatama() :CObjectBase(0, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Magatama"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(128, 128);

}

CMagatama::~CMagatama() {

}

void CMagatama::Update() {
	m_pos3D.x = MAGATAMA_POS_X + m_scroll.x;
}