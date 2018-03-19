#include"CBossStage.h"

CBossStage::CBossStage() :CObjectBase(eID_Ground, eU_Map, eD_Ground){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("BossStage"));
}

CBossStage::~CBossStage() {

}