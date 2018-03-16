#include "bullet.h"
#include "bullet_manager.h"
#include "player_manager.h"

//出現座標とアイテムの番号が引数

CBullet::CBullet(CVector3D* pos,CVector3D* vec, float ftime,int whose)
:CTask(0, eUDP_Item, eDWP_Item)
, m_pos(*pos)
, m_vec(*vec)
, m_flying_time(ftime)
, m_create_time(GetNowCount())
, m_whose(whose)
, m_living(true)
{
}

CBullet::~CBullet(){
}

void CBullet::Update(){
	// 移動
	m_pos += m_vec;
	m_pos.setX(m_pos.getX() - CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount());
	//プレイヤーのZ座標
	float _p_pos_z = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getZ()+PLAYER_LOWER_SIZE;
	//ジャンプに合わせないようにする
	float _yscr = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	if (_yscr > 250.0f)
		_yscr = 250.0f;
	m_pos.setY(-1 * _yscr);

	if (GetNowCount() - m_create_time > m_flying_time){
		m_destroyFlg = true;
		CBulletManager::GetInstance()->Remove(this);
	}

	if (m_living == false){
		if (!m_destroyFlg){
			CBulletManager::GetInstance()->Remove(this);
			//タスクキル
			SetKill();
		}
	}
	else
	{
		//画面外判定
		if (m_pos.getX() < 0 || m_pos.getX() > 1280)
		{
			Kill();
		}
	}
	if (_p_pos_z < m_pos.getZ()){
		CBullet::ChangeDrawPriority(eDWP_Bullet);
	}
	else{
		CBullet::ChangeDrawPriority(eDWP_BBullet);
	}
}

void CBullet::Draw(){
	//アイテムの名前によって画像が変化
	int _img = CBulletManager::GetInstance()->getImg();
	DrawGraph(m_pos.getX(), m_pos.getY() + m_pos.getZ(),_img, TRUE);
}