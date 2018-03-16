#ifndef UI_H
#define UI_H

#include "Task\CTask.h"
#include "myLib.h"

const float SCORE_INIT_X = 0;				//スコアX
const float SCORE_INIT_Y = 650;				//スコアY
const float SCOREGAGE_INIT_X = 0;			//スコアゲージX
const float SCOREGAGE_INIT_Y = 600;			//スコアゲージY
const float SCORENUM_INIT_X = 380;			//スコアナンバーX
const float SCORENUM_INIT_Y = 650;			//スコアナンバーY
const float MAP_INIT_X = 810;				//ミニマップX
const float MAP_INIT_Y = 620;				//ミニマップY
const float MAP_P_INIT_X = 812;				//ミニマップのプレイヤーX
const float MAP_P_INIT_Y = 665;				//ミニマップのプレイヤーY
const float SCORE_INIT_MAG_X = 0;			//スコア倍率のX
const float SCORE_INIT_MAG_Y = 575;			//スコア倍率のY
const float ITEM_INIT_X = 540;				//アイテムのX
const float ITEM_INIT_Y = 670;				//アイテムのY
const float ITEM_SPACE_X = 100;				//アイテムのX

const float P_CENTER_X = 83;				//プレイヤーの真ん中の座標X
const float ITEM_FRAME_X = 490;				//アイテムのフレームX
const float ITEM_FRAME_Y = 620;				//アイテムのフレームY
const float ITEM_IMGSIZE_X = 100;			//アイテムの画像サイズ
const float SCORE_MAGNIFICATION_X = 57;		//スコア倍率のX座標
const float SCORE_MAGNIFICATION_Y = 15;		//スコア倍率のY座標
const float TIMER_BORDER_X = 150.0f;		//見切れた場合の制限時間のX座標
const float TIMER_OVER_X = 100.0f;			//制限時間が見切れるXの限界値
const float TIMER_SKIP_X = 170.0f;			//コロンを飛ばしたときのX座標
const int TIMER_SPACE = 35;					//タイマーの文字幅
const int TIMER_COLON_CONT_X = 40;			//タイマーのコロンのX座標

class Ui :public CTask{
private:
	int m_timer_img[12];		//制限時間の画像
	int m_scorenum_img[12];		//スコアの数字画像
	int m_item_img[4];			//アイテムの画像
	int m_score_img;			//「スコア」の画像
	int m_scoregage_img[2];		//スコアゲージの画像
	int m_map_img;				//ミニマップの画像
	int m_scorearrow_img;		//スコアゲージの矢印の画像
	int m_item_bg_img;			//アイテムのバックグラウンド画像
	CVector3D m_timer_pos;		//制限時間の座標
	CVector3D m_arrow_pos;		//スコア倍率の矢印の座標	スコア倍率でも使用
	CVector3D m_maparrow_pos;	//ミニマップの自機の座標
	int m_totalscore;				//スコア量
	float m_timelimit;				//タイムリミット
	float m_score_magnification;	//スコア倍率
public:
	Ui();
	Ui(CVector3D p_pos);
	~Ui();
	void Update();
	void Draw();
	void scoreMagnification(CVector3D *pos);	//
	void scoreAddition(int points);		//
};

#endif UI_H