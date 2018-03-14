#include "timer.h"

void CTimeData::load(){
	LoadDivGraph("media\\img\\number_2.png", 22, 5, 5, 55, 55, Tnumimg);
};

void CTimeData::init(){
	m_timer.time = 50.00;
};

void CTimeData::move(CVector3D pos){
	
	//カウントダウン
	m_timer.time -= 0.0166666;

	//プレイヤーが左端に行くとタイマーが埋もれてしまうのを防ぐための処理
	//なお、現在moveposを使う意味がないので消してもよい
	if (pos.getX() < 160){
		m_timer.movepos = CVector3D(160, pos.getY(),pos.getZ());
		m_timer.pos = m_timer.movepos;
	}
	else{
		m_timer.pos = pos;
	}

	//タイマーが0以下になってしまった場合は0にする
	if (m_timer.time < 0){
		m_timer.time = 0;
	}
}

void CTimeData::draw(){
	int offset1 = 0;
	char buf[100];
	float num;

	//描画にあたって「10.00」のような数字の場合、小数点も入るので
	//１２３４５
	//↑↑↑↑↑
	//１０．００となり
	//numの数値が5となる
	//こうなると3は数値ではないので除外する処理を行う

	num = sprintf_s(buf, 100, "%0.2f", m_timer.time);
	for (int i = 0; i < num; i++){
		if (i != 2 - offset1){	//10秒以下の場合、桁が減るのでoffsetでマイナスさせる
			if (num == 4.0 && i == 0){

				//10秒以下の表記、例えば「09.00秒」の場合、最初の「0」が
				//表記されないのでここで描画させる

				DrawGraph(m_timer.pos.getX() + (-160 + i * TIMER_SPACE),
					m_timer.pos.getY() - 60, Tnumimg[('0' - '&')], TRUE);
				offset1 = 1;
			}

			//「.」（小数点）は除外するので処理上その間が空いてしまう
			//そのため下のように小数点以下の数字は詰めるように処理を分けさせてもらった

			if (i > 2 - offset1){
				DrawGraph(m_timer.pos.getX() + (-175 + (i + offset1) * TIMER_SPACE),
					m_timer.pos.getY() - 60, Tnumimg[(buf[i] - '&')], TRUE);
			}
			else{
				DrawGraph(m_timer.pos.getX() + (-160 + (i + offset1) * TIMER_SPACE),
					m_timer.pos.getY() - 60, Tnumimg[(buf[i] - '&')], TRUE);
			}
		}
	}
}