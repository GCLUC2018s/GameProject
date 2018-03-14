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
	CVector2D m_pos;					//座標
	CVector2D m_vec;
	float m_flying_time;				//銃弾が飛ぶ距離
	int m_create_time;
	int m_whose;
public:
	void Update();
	void Draw();
	CBullet(CVector2D* pos,CVector2D* vec,float fdist,int whose);
	~CBullet();
	CVector2D GetPos()const{ return m_pos; }
};

#endif __BULLET_H__