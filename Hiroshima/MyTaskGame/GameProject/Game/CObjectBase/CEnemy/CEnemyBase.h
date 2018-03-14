#ifndef ENEMYBASEGUARD
#define ENEMYBASEGUARD

//敵のサイズ
#define ENEMY_SIZ_X 213
#define ENEMY_SIZ_Y 256


#include "../GameProject/GAME/CObjectBase/CObjectBase.h"
#include "../GameProject/stdafx.h"

//此処ではエネミー全体（ボスを除く）に共通するものを書く

class CEnemyBase : public CObjectBase
{
protected:
	
public:
	CEnemyBase();
	void DropItem();
};

#endif // !ENEMYBASEGUARD

