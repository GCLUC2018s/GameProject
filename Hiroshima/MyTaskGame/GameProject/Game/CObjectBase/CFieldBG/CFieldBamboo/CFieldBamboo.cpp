#include "CFieldBamboo.h"
/*
宮﨑：
たぶんこれ考え方間違ってた;;
端まで行ってキルしたら、真っ白になっちゃうから
端まで行ったら、その向こう側（pos.xに1280足した位置）から新しく生成してその繰り返し。。。
しかも戻れるから、重くならないようになんか上手いことしよう！

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
