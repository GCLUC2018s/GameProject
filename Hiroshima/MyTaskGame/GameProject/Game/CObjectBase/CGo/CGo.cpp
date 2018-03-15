#include "CGo.h"

CGo::CGo() : CObjectBase(eID_Flag,eU_UI,eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("GO"));
	m_img.SetSize(GO_SIZ, GO_SIZ);
	m_pos3D = CVector3D(SCREEN_WIDTH - 50, 400, 0);
}

CGo::~CGo()
{
}

void CGo::Update()
{
	m_pos3D.y = sin(GO_TIME);
}
