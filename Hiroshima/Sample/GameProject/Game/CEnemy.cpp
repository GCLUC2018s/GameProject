#include "CEnemy.h"
/*

����ҁ@��

*/
CEnemy::CEnemy() :CBase(eTagPlayer) {
}

CEnemy::~CEnemy() {
}

void CEnemy::Update() {
}


//�ȉ��ǉ��p

//��������

//ADD_RESOURCE("Eenmy", CAnimImage::LoadImage("enemy.png", anim_enemy_data, 96, 96));
//image_enemy = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
//ENE = new CEnemy();
//
//
//ENE->Update();
//image_enemy.ChangeAnimation(0);
//image_enemy.UpdateAnimation();
//image_enemy.SetSize(213, 256);
//image_enemy.SetPos(PL->GetPos());
//image_enemy.Draw();
//
//
//CAnimImage image_enemy;
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
////��������
//#include "../GameProject/Game/CEnemy.h"