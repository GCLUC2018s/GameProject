#include "CMagatama.h"

CMagatama::CMagatama() :CObjectBase(eID_Null, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(128, 128);
}

CMagatama::~CMagatama() {

}

void CMagatama::Update() {
	m_pos3D.x = MAGATAMA_POS_X + m_scroll.x;
	m_pos3D.y = MAGATAMA_POS_Y + m_scroll.y;


	if (PUSH_V) {
		Hit(this);
	}
}

void CMagatama::Hit(CTask * t){
	m_kakera++;
	if (m_kakera <= 10) 
		m_img.SetRect(128 * m_kakera, 0, 128 + 128 * m_kakera, 128);
}

