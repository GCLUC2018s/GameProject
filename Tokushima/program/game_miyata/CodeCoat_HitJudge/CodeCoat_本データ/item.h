#ifndef __ITEM_H__
#define __ITEM_H__

//ヘッダーファイル
#include <DxLib.h>
#include <list>
#include "myLib.h"
#include "Task\CTask.h"

using namespace std;

//定数
const int ITEMCOUNT = 8;		//アイテムの画像数
const int ITEM_CHIPSIZE = 200;	//アイテムの画像サイズ
const float ITEM_CENTER = 100.0f;//アイテムの中心割り出し
const float ITEM_COLLISION =100;//アイテムの当たり判定半径

//作成前に必要要素のまとめ
/*
クラスに持たせる要素
装備の種類
耐久度もしくは時間を入れるもの
画像
座標

アイテムの画像を使うところ
１．UI
→主人公に持たせている装備欄の情報を持って行ってもらう
２．フィールド
→敵撃破時に一定確率で出現
enemyの関数の方でアイテムを出現させる関数が欲しい

player
→番号、変数一つ、画像←UIに渡すために必要
enemy
→なし
NPC
→番号、画像、変数一つ
UI
→画像

------------------------------------------------------------------------------------------------------
必要な関数
CItemData pickupItem(CVector2D pos);	//引数に座標が入ると座標部分にあるアイテムを返し値にする
CItemData BuyBuild(ItemName name);	//引数に番号が入るとその番号のアイテムの情報を返す
void makeBuild(CVector2D pos, ItemName name);　　//引数の番号と座標をリストに追加する  敵が死んだときに使う　座標に指定したアイテムを配置する
------------------------------------------------------------------------------------------------------
*/

//アイテムの種類
enum ItemType{WEAPON = 0,ARMOR,ITEM};	

//アイテムの名前
enum ItemName{NONE = -1, KNIFE = 0, PISTOL, SHOTTOGAN, RIFLE, STABARMOR, BULLETARMOR, SCOREBOOST, SPEEDUP };	

//主人公にデータを渡す用のクラス(仮)
class CItemData{
public:
	CItemData();
	ItemType m_type;
	int m_img;
	ItemName m_name;
	int m_useful;			//防具の場合は耐久値、アイテムの場合は残り時間を入れる
	int m_attack_rate;
};

class CIdata : public CTask{
private:
	CVector3D m_pos;					//座標
	ItemType m_type;					//アイテムの種類		
	ItemName m_name;					//アイテムの名前
//	bool m_IsKill;						いらない可能性：高
//	bool m_live;						いらない可能性：高
	int m_useful;						//色々な要素として使う変数(例　銃：残弾数　防具：耐久値　アイテム：効果時間)
public:
	void Update();
	void Draw();
	CIdata(CVector3D* pos, int num);
	~CIdata();
	CVector3D GetPos()const{ return m_pos; }
	ItemName GetName()const{ return m_name; }
	ItemType GetType()const{ return m_type; }
};

#endif __ITEM_H__