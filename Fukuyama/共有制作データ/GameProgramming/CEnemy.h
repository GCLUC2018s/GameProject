#ifndef CENEMY_H
#define CENEMY_H
#include "../object/C_Object.h"
#include"chara\C_Player.h"
#include"object\CVector3.h"
#define ENEMY_UD_SPEED 5
#define ENEMY_LR_SPEED 9
class CEnemy :public C_Object{
public:
	CTexture mTexture;
	int m_EnemyCount; //フィールド上の敵の数
	int m_EnemySet;//敵の配置
	int m_EnemyKind;//敵の種類
	void Init();
	void Update();
	void Draw();
	C_Player *m_Target;
};
#endif