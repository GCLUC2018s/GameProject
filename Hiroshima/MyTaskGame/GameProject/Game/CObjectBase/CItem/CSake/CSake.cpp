#include "CSake.h"

CSake::CSake(CVector3D * pos) :CObjectBase(0, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sake"));
	m_img.SetRect(64, 256, 128, 320);
	m_img.SetSize(64, 64);
	m_pos3D = *pos;

}

CSake::~CSake() {

}

void CSake::Update() {
}