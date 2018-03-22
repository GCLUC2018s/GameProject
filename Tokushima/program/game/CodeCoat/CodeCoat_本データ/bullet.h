#ifndef __BULLET_H__
#define __BULLET_H__

//ヘッダーファイル
#include <DxLib.h>
#include <list>
#include "myLib.h"
#include "Task\CTask.h"

using namespace std;

//定数
const int BULLET_SIZE = 20;
const float BULLET_CENTER = 10.0f;
const float BULLET_COLLISION = 15;

//列挙体
enum whose_number{ PLAYER = 0, ENEMY };

//主人公にデータを渡す用のクラス(仮)
/*class CItemData{
public:
	ItemType m_type;
	int m_img;
	ItemName m_name;
	int m_useful;			//防具の場合は耐久値、アイテムの場合は残り時間を入れる
};*/

class CBullet : public CTask{
private:
	CVector3D m_pos;					//座標
	CVector3D m_vec;					//移動方向
	float m_flying_time;				//銃弾が飛ぶ距離
	int m_create_time;					//作られた際の時間
	int m_whose;						//誰の弾か Player or Enemy
	bool m_living;						//生きているか
public:
	void Update();
	void Draw();
	CBullet(CVector3D* pos,CVector3D* vec,float fdist,int whose);
	~CBullet();
	CVector3D getPos()const{ return m_pos; }
	int getWhoseBullet()const{ return m_whose; }
	void Kill(){ m_living = false; }
	bool GetLive()const{ return m_living; }
};

#endif __BULLET_H__