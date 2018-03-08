#include "CBG.h"

CBG::CBG()
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("BG"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
}
