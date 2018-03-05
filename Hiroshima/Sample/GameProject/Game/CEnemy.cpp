#include "CEnemy.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
CEnemy::CEnemy(CVector2D pos) :CBase(eTagPlayer) {
}

CEnemy::~CEnemy() {
}

void CEnemy::Update() {
}


//à»â∫í«â¡óp


//çüèàÇ©ÇÁ

//ADD_RESOURCE("Eenmy", CAnimImage::LoadImage("enemy.png", anim_enemy_data, 96, 96));
//m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
//ENE = new CEnemy(CVector2D(500,500));
//
//
//ENE->Update();


//m_img.ChangeAnimation(0);
//m_img.UpdateAnimation();
//m_img.SetSize(213, 256);
//m_pos=pos;
//
//
//
//
//CBase* ENE;
//
//
//TexAnim _anim_enemy[] = {
//	{ 4,5 },
//	{ 5,5 },
//	{ 6,5 },
//	{ 7,5 },
//
//};
//
//TexAnimData anim_enemy_data[] = {
//	ANIMDATA(_anim_enemy),
//};
//

//#include "../GameProject/Game/CEnemy.h"