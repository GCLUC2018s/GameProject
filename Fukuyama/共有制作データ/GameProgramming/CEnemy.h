#ifndef CENEMY_H
#define CENEMY_H
#include "../object/C_Object.h"
#include"chara\C_Player.h"
#include"object\CVector3.h"
#define ENEMY_UD_SPEED 5
#define ENEMY_LR_SPEED 9
#define RUN_ANIME 90    //アニメーション用変数を回す上限

class CEnemy :public C_Object{
public:
	CEnemy()
		:C_Object(E_ENEMY, eUDP_Enemy, eDWP_Enemy, 0, 0, 0)
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(0, 90, 0, 135);
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);
	}
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