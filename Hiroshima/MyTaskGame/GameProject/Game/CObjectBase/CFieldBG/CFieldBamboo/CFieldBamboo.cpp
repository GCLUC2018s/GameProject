#include "CFieldBamboo.h"
/*
�{���F
���Ԃ񂱂�l�����Ԉ���Ă�;;
�[�܂ōs���ăL��������A�^�����ɂȂ����Ⴄ����
�[�܂ōs������A���̌��������ipos.x��1280�������ʒu�j����V�����������Ă��̌J��Ԃ��B�B�B
�������߂�邩��A�d���Ȃ�Ȃ��悤�ɂȂ񂩏�肢���Ƃ��悤�I

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
