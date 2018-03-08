#include "CBG.h"

CBG::CBG() : CTask(eID_Map, eUDP_Map, eDWP_Map)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("BG"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
}
