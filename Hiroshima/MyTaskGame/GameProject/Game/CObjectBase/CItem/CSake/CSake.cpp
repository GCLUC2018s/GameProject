#include "CSake.h"

CSake::CSake(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(64, 256, 128, 320);
	m_img.SetSize(20, 20);
}

CSake::~CSake() {

}
