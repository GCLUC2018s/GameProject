#include "ui.h"
#include "player_manager.h"
#include "map_manager.h"
#include "enemy_manager.h"
#include "npc_manager.h"
#include "ui_manager.h"

Ui::Ui() :
m_timer_pos(0, 0, 0),
m_arrow_pos(0,0,0),
m_maparrow_pos(0,0,0),
m_totalscore(0),
m_timelimit(0),
m_score_magnification(0)
{
}

Ui::Ui(CVector3D p_pos) :CTask(0,eUDP_Ui,eDWP_Ui),
m_score_img(LoadGraph("media\\img\\score2.png" ,TRUE)),
m_map_img(LoadGraph("media\\img\\map.png", TRUE)),
m_scorearrow_img(LoadGraph("media\\img\\power-arrow1.png", TRUE)),
m_combotxt_img(LoadGraph("media\\img\\combo.png",TRUE)),
m_timer_pos(p_pos),
m_arrow_pos(p_pos),
m_maparrow_pos(MAP_P_INIT_X,MAP_P_INIT_Y,0),
m_totalscore(0),
m_timelimit(99.9f),
m_score_magnification(1),
m_comb_flag(false),
m_c_angle(COMB_MOVE_X),
m_past_comb(0),
m_ndm_magnification(0)
{
	LoadDivGraph("media\\img\\time-number.png",12,6,2,70,70,m_timer_img);
	LoadDivGraph("media\\img\\score_number2.png",12,10,2,40,40,m_scorenum_img);
	LoadDivGraph("media\\img\\item-frame.png", 4, 2, 2, 100, 100, m_item_img);
	m_scoregage_img[0] = LoadGraph("media\\img\\power-gage0.png");
	m_scoregage_img[1] = LoadGraph("media\\img\\power-gage1.png");
	m_totalrun_txt_img[0] = LoadGraph("media\\img\\bonus.png");
	m_totalrun_txt_img[1] = LoadGraph("media\\img\\fold.png");
	CUiManager::GetInstance()->Init(this);
}

Ui::~Ui()
{
}

void Ui::Update(){
	CNpc *_npc = CNpcManager::GetInstance()->GetNpcAdress();
	if (!_npc->getShopFlag()){
		const float offset = 50;
		CVector3D p_pos = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos();
		float _totalmove = CMapManager::GetInstance()->GetMapAdress()->getTotalmovement();
		float _move = 0;
		//弾数		追加
		for (int i = 0; i < 2; i++){
			m_ammo[i] = CPlayerManager::GetInstance()->GetPlayerAdress()->getEquipment(i)->m_useful;
			if (CPlayerManager::GetInstance()->GetPlayerAdress()->getEquipment(i)->m_name == 0)
				m_ammo[i] = 0;
		}

		//タイマーをプレイヤーに追従させる処理
		if (p_pos.getX() < 100){	//タイマーが見切れるなら
			m_timer_pos = CVector3D(TIMER_BORDER_X, p_pos.getY(), p_pos.getZ());
		}
		else{
			m_timer_pos = CVector3D(p_pos.getX() + offset, p_pos.getY(), p_pos.getZ());
		}

		m_timelimit -= 0.0166666f;

		//カウントダウン処理
		if (m_timelimit < 0){	//0以下なら
			m_timelimit = 0;
		}

		//矢印をプレイヤーに追従させる処理
		m_arrow_pos = CVector3D(p_pos.getX() + P_CENTER_X, SCORE_INIT_MAG_Y, 0);

		//スコア倍率の処理
		scoreMagnification(&p_pos);

		//ミニマップの走行距離の処理
		_move = _totalmove / MAP_DISTANCE;			//変更
		if (_move < 405)
			m_maparrow_pos = CVector3D(_move + MAP_P_INIT_X, MAP_P_INIT_Y, 0);

		scoreAddition();
	}
}

void Ui::Draw(){
	int offset1 = 0;	//タイマーで使用
	int offset2 = 1;	//スコア倍率で使用
	int offset3 = 0;	//走行倍率で使用	追加
	int offset4 = 0;	//追加

	char buf[100];
	float num;
	//タイマーの描画　小数点第二位まで
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
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[0/* - '&'*/], TRUE);
			offset1 = 1;
		}

		//上二桁の描画
		if (i > 2 - offset1){
			DrawGraph(m_timer_pos.getX() + (-TIMER_SKIP_X + (i + offset1) * TIMER_SPACE),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[(buf[i] - '0')], TRUE);
		}
		//小数点の描画
		else if (i == 2 - offset1){
			DrawGraph(m_timer_pos.getX() + (-TIMER_SKIP_X + (i + offset1) * 40),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[10], TRUE);
		}
		//下二桁の描画
		else{
			DrawGraph(m_timer_pos.getX() + (-TIMER_BORDER_X + (i + offset1) * TIMER_SPACE),
				m_timer_pos.getY() + m_timer_pos.getZ() - 60, m_timer_img[(buf[i] - '0')], TRUE);
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
	
	//マップの自機の描画
	DrawGraph(m_maparrow_pos.getX(),m_maparrow_pos.getY(),m_scorearrow_img,TRUE);

	//スコア倍率のメーターの描画
	DrawRectGraph(SCOREGAGE_INIT_X, SCOREGAGE_INIT_Y, 0, 0
		,1280, 20, m_scoregage_img[1], TRUE, FALSE);

	//スコア倍率の矢印の描画
	DrawGraph(m_arrow_pos.getX(), m_arrow_pos.getY(), m_scorearrow_img, TRUE);
	
	//スコア倍率の表記の描画　小数点第一位まで
	num = sprintf_s(buf, 100, "%0.1f", m_score_magnification);
	for (int i = 0; i < num; i++){
		//×を描画
		if (i == 0){
			DrawGraph(m_arrow_pos.getX() + 30,
				m_arrow_pos.getY() - 10, m_scorenum_img[10], TRUE);
		}
		//小数点の描画
		if (i == 1){
			DrawGraph(m_arrow_pos.getX() + SCORE_MAGNIFICATION_X + (i * 32),
				m_arrow_pos.getY() + 3 - SCORE_MAGNIFICATION_Y, m_scorenum_img[11], TRUE);
		}
		//数字の描画
		else
		{
		DrawGraph(m_arrow_pos.getX() + SCORE_MAGNIFICATION_X+(i * 20),
			m_arrow_pos.getY()-SCORE_MAGNIFICATION_Y, m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
		}
	}
	
	//アイテムUIの描画	30度角度をつけてます
	for (int i = 0; i < 3; i++){
		CItemData* itemdata = CPlayerManager::GetInstance()->GetPlayerAdress()->getEquipment(i);
		if (itemdata->m_img != 0){
			DrawRotaGraph(ITEM_INIT_X + i*ITEM_SPACE_X, ITEM_INIT_Y, 0.5, 3.141592/180*-30, itemdata->m_img, TRUE, FALSE);
		}
	}

	//弾薬や装備の使用回数		追加
	for (int j = 0; j < 2; j++){
		num = sprintf_s(buf, 100, "%d", m_ammo[j]);
		for (int i = 0; i < num; i++){
			DrawRotaGraph(((ITEM_FRAME_X + 70 + (j * 100))) + i * 17,
				ITEM_FRAME_Y + 80, 0.7, 0, m_scorenum_img[(buf[i] - '0')], TRUE, FALSE);		//'0'
		}
	}

	//コンボ数		追加
	if (m_comb_flag == true){
		float temp = 0;
		//移動量
		if (m_c_angle < 90){
			m_c_angle++;
		}
		temp = sin(m_c_angle * PI/180);
	//コンボの文字描画	追加
		DrawRotaGraph(COMB_X * temp, COMB_Y - 20, 0.5, 0,
			 m_combotxt_img, TRUE, FALSE);
		//コンボ数描画
		num = sprintf_s(buf, 100, "%d", CEnemyManager::getInstance()->GetComb());
		for (int i = 0; i < num; i++){
			DrawGraph((COMB_X * temp) + i * 25,
				COMB_Y, m_scorenum_img[(buf[i] - '0')], TRUE);		//'0'
		}
	}

	//走行距離の倍率文字描画
	if (CPlayerManager::GetInstance()->getNoDamageMovement()>2500){
		float temp = 0;
		if (m_c_angle < 90){
			m_c_angle++;
		}
		temp = sin(m_c_angle * PI / 180);
		for (int i = 0; i < 2; i++){
			DrawRotaGraph(COMB_X * temp, BONUS_Y - 20 + (35 * i), 0.4, 0,
				m_totalrun_txt_img[i], TRUE, FALSE);
		}
		//走行距離の倍率描画
		num = sprintf_s(buf, 100, "%0.1f", m_ndm_magnification);
		for (int i = 0; i < num; i++){
			if (i == 0){
				DrawGraph((BONUS_X * temp) + 30,
					COMB_Y, m_scorenum_img[10], TRUE);
			}
			if (i - offset3 == 1){
				DrawGraph((BONUS_X * temp) + (SCORE_MAGNIFICATION_X - offset4) + (i * 32),
					COMB_Y, m_scorenum_img[11], TRUE);		//.
			}
			else{
				DrawGraph((BONUS_X * temp) + SCORE_MAGNIFICATION_X + (i * 20),
					COMB_Y, m_scorenum_img[(buf[i] - '0')], TRUE);
			}
		}
	}
}

void Ui::scoreMagnification(CVector3D *pos){	
	m_score_magnification = (pos->getX() / 320) + 1;
	if (m_score_magnification < 1){
		m_score_magnification = 1;
	}
}

void Ui::scoreAddition(){		//追加
	int _s = 0;		//スコア計算結果
	float _comb = (float)CEnemyManager::getInstance()->GetComb();	//コンボ倍率
	float _nodamagemove = CPlayerManager::GetInstance()->getNoDamageMovement();		//走行距離に応じたスコア倍率
	float _item_score = CPlayerManager::GetInstance()->GetPlayerAdress()->getBuff()->m_score_ratio;

	//最初にコンボ数を代入
	if (m_past_comb == 0){
		m_past_comb = _comb;
	}
	else if(m_past_comb != _comb){
		m_c_angle = COMB_MOVE_X;
		m_past_comb = _comb;
	}

	//出現判定
	if (_comb < 1)
		m_comb_flag = false;
	else{
		m_comb_flag = true;
		CPlayerManager::GetInstance()->setNoDamageMovement(0);
	}

	//倍率の初期値が1.0
	//_comb = (_comb / 10) + 1;

	//エネミーを倒したら
	if (CEnemyManager::getInstance()->GetDel() == true){
		_s = (m_score_magnification+_comb + _item_score) * 100;		//画面内の倍率＋コンボ
		m_totalscore += _s;
		CEnemyManager::getInstance()->SetDel(false);

	}

	//攻撃せず一定距離まで走れば
	if (_nodamagemove > 2500){
		m_ndm_magnification = _nodamagemove / 2500;
		if (CPlayerManager::GetInstance()->getNdmFalg() == true){
			m_totalscore += (m_score_magnification + m_ndm_magnification + _item_score) * 50;	//画面内の倍率＋走行距離倍率
			CPlayerManager::GetInstance()->setNdmFalg(false);
		}
	}
}

void Ui::scoreFluctuation(int points){
	m_totalscore += points;
}