#include "CFieldBamboo.h"
/*
{ú±F
½Ôñ±êl¦ûÔáÁÄ½;;
[ÜÅsÁÄLµ½çA^ÁÉÈÁ¿á¤©ç
[ÜÅsÁ½çA»Ìü±¤¤ipos.xÉ1280«µ½Êuj©çVµ­¶¬µÄ»ÌJèÔµBBB
µ©àßêé©çAd­ÈçÈ¢æ¤ÉÈñ©ãè¢±Æµæ¤I

*/
CFieldBamboo::CFieldBamboo():CObjectBase(0,eU_Map,eD_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Bamboo"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
}

CFieldBamboo::~CFieldBamboo(){
	new CFieldBamboo();
}

void CFieldBamboo::Update(){
	m_pos3D = CVector3D(m_scroll.x/1.3,0,0);
	if (m_pos3D.x == GROUND_WIDTH) {
		SetKill();
	}
}
