#include "ui.h"
#include "player_manager.h"
#include "map_manager.h"

Ui::Ui() :
m_timer_pos(0, 0),
m_arrow_pos(0,0),
m_maparrow_pos(0,0),
m_totalscore(0),
m_timelimit(0),
m_score_magnification(0)
{
}

Ui::Ui(CVector2D p_pos) :CTask(0,eUDP_Ui,eDWP_Ui),
m_score_img(LoadGraph("media\\img\\score.png" ,TRUE)),
m_map_img(LoadGraph("media\\img\\map.png", TRUE)),
m_scorearrow_img(LoadGraph("media\\img\\power-arrow1.png", TRUE)),
m_timer_pos(p_pos),
m_arrow_pos(p_pos),
m_maparrow_pos(MAP_P_INIT_X,MAP_P_INIT_Y),
m_totalscore(100),
m_timelimit(99.9f),
m_score_magnification(1)
{
	LoadDivGraph("media\\img\\time-number.png",12,6,2,70,70,m_timer_img);
	LoadDivGraph("media\\img\\score_number.png",12,10,2,40,40,m_scorenum_img);
	LoadDivGraph("media\\img\\item-frame.png", 4, 2, 2, 100, 100, m_item_img);
	m_scoregage_img[0] = LoadGraph("media\\img\\power-gage0.png");
	m_scoregage_img[1] = LoadGraph("media\\img\\power-gage1.png");
}

Ui::~Ui()
{
}

void Ui::Update(){
	const float offset = 50;
	CVector2D p_pos = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos();
	float totalmove = CMapManager::GetInstance()->GetPlayerAdress()->getTotalmovement();

	//タイマーをプレイヤーに追従させる処理
	if (p_pos.getX() < 100){	//タイマーが見切れるなら
		m_timer_pos = CVector2D(TIMER_BORDER_X, p_pos.getY());
	}
	else{
		m_timer_pos = CVector2D(p_pos.getX() + offset, p_pos.getY());
	}

	m_timelimit -= 0.0166666;
	
	//カウントダウン処理
	if (m_timelimit < 0){	//0以下なら
		m_timelimit = 0;
	}

	//矢印をプレイヤーに追従させる処理
	m_arrow_pos = CVector2D(p_pos.getX() + P_CENTER_X, MAP_P_INIT_Y);

	scoreMagnification(&p_pos);
}

void Ui::Draw(){
	int offset1 = 0;	//タイマーで使用
	int offset2 = 1;	//スコア倍率で使用
	char buf[100];
	float num;

	//描画にあたって「10.00」のような数字の場合、小数点も入るので
	//１２３４５
	//↑↑↑↑↑
	//１０．００となり
	//numの数値が5となる
	//こうなると3は数値ではないので除外する処理を行う

	num = sprintf_s(buf, 100, "%0.2f", m_timelimit);
	for (int i = 0; i < num; i++){

		//10秒以下の場合、桁が減るのでoffsetでマイナスさせる
		if (num == 4.0 && i == 0){

			//10秒以下の表記、例えば「09.00秒」の場合、最初の「0」が
			//表記されないのでここで描画させる

			DrawGraph(m_timer_pos.getX() + (-TIMER_BORDER_X + i * TIMER_SPACE),
				m_timer_pos.getY() - 60, m_timer_img[0/* - '&'*/], TRUE);
			offset1 = 1;
		}

		//上二桁の描画
		if (i > 2 - offset1){
			DrawGraph(m_timer_pos.getX() + (-TIMER_SKIP_X + (i + offset1) * TIMER_SPACE),
				m_timer_pos.getY() - 60, m_timer_img[(buf[i] - '0')], TRUE);
		}
		//小数点の描画
		else if (i == 2 - offset1){
			DrawGraph(m_timer_pos.getX() + (-TIMER_SKIP_X + (i + offset1) * 40),
				m_timer_pos.getY() - 60, m_timer_img[10], TRUE);
		}
		//下二桁の描画
		else{
			DrawGraph(m_timer_pos.getX() + (-TIMER_BORDER_X + (i + offset1) * TIMER_SPACE),
				m_timer_pos.getY() - 60, m_timer_img[(buf[i] - '0')], TRUE);
		}
	}

	//スコア文字の描画
	DrawGraph(SCORE_INIT_X, SCORE_INIT_Y, m_score_img, TRUE);
	
	//スコアの描画
	num = sprintf_s(buf, 100, "%d", m_totalscore);
	for (int i = 0; i < num; i++){
		DrawGraph(SCORENUM_INIT_X + i * 25,
			SCORENUM_INIT_Y, m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
	}

	//アイテムの描画
	for (int i = 0; i < 3; i++){
		DrawGraph(ITEM_FRAME_X + ITEM_IMGSIZE_X*i, ITEM_FRAME_Y, m_item_img[i], TRUE);
	}

	//マップの描画
	DrawGraph(MAP_INIT_X, MAP_INIT_Y, m_map_img, TRUE);
	
	//スコア倍率のメーターの描画
	DrawRectGraph(SCOREGAGE_INIT_X, SCOREGAGE_INIT_Y, 0, 0
		,1280, 20, m_scoregage_img[1], TRUE, FALSE);

	//スコア倍率の矢印の描画
	DrawGraph(m_arrow_pos.getX(), m_arrow_pos.getY(), m_scorearrow_img, TRUE);
	
	//スコア倍率の表記の描画
	num = sprintf_s(buf, 100, "%0.1f", m_score_magnification);
	for (int i = 0; i < num; i++){
		if (i == 0){
			DrawGraph(m_arrow_pos.getX() + (i +offset2) * 25,
				m_arrow_pos.getY(), m_scorenum_img[10], TRUE);
		}
		DrawGraph(m_arrow_pos.getX() + (i + offset2) * 25,
			m_arrow_pos.getY(), m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
	}
}

void Ui::scoreMagnification(CVector2D *pos){
	m_score_magnification = (pos->getX() / 320) + 1;
}

void Ui::scoreAddition(int points){
	m_totalscore += points;
}