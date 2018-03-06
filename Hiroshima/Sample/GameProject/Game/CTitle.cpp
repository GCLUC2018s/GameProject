#include "CTitle.h"

CTitle::CTitle():CBase(eTagUI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title"));
	m_img.SetSize(1280, 720);
}

CTitle::~CTitle()
{
}

void CTitle::Update()
{
}
