#ifndef CENEMY_H
#define CENEMY_H
#include "../object/C_Object.h"
#include"chara\C_Player.h"
#include"object\CVector3.h"
#define ENEMY_UD_SPEED 3
#define ENEMY_LR_SPEED 3
#define ACTION_INTERVAL 120
#define TARGETINTERVAL 300
class CEnemy :public C_Object{
public:
	CEnemy()
		:C_Object(E_ENEMY, eUDP_Enemy, eDWP_Enemy, 700, 0, 35)
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(0, 90, 0, 135);
		i_Shadow.SetVertex(0, 60, 0, 135);
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);
		i_Enemy_Run.Load("image/chara/chara_enemy_16bit.tga");
	}
	enum ENEMY_MODE{
		E_NORMAL,
		E_ACTION,
		E_DEAD
	};
	float m_Long;
	static CEnemy *m_EnemyPoint;
	CTexture mTexture;
	CTexture i_Enemy_Run;
	int m_EnemySet;//敵の配置
	int m_EnemyKind;//敵の種類
	int m_EnemyMode;
	int m_ActionInterval;
	int m_TargetInterval;
	bool Collision(CTask*, CTask*);
	void Init();
	void Update();
	void Draw();
	C_Vector3 m_TargetR;
	C_Vector3 m_TargetL;
};
enum ENEMY_TYPE{
	E_ESCAPE,
	E_KIN
};
#endif