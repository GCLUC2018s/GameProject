#ifndef ENEMYBASEGUARD
#define ENEMYBASEGUARD

//�G�̃T�C�Y
#define ENEMY_SIZ_X 213
#define ENEMY_SIZ_Y 256


#include "../GameProject/GAME/CObjectBase/CObjectBase.h"
#include "../GameProject/stdafx.h"

//�����ł̓G�l�~�[�S�́i�{�X�������j�ɋ��ʂ�����̂�����

class CEnemyBase : public CObjectBase
{
protected:
	
public:
	CEnemyBase();
	void DropItem();
};

#endif // !ENEMYBASEGUARD

