#ifndef CENEMY_H
#define CENEMY_H
#include "../object/C_Object.h"
#include"object\CVector3.h"
#define ENEMY_UD_SPEED
#define ENEMY_LR_SPEED
class CEnemy :public C_Object{
public:
	CTexture mTexture;
	int EnemyCount;
	
	void Init();
	void Update();
	void Draw();
	C_Player *m_Target;
};
#endif