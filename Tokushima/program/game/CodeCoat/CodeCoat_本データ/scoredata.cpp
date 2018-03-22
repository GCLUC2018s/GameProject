#include "scoredata.h"

ScoreData::ScoreData() :
CTask(0, eUDP_Rank,eDWP_Rank),
linedelimiter(0),
m_updateNum(-2)
{
	for (int i = 0; i < SCORE_NUM; i++){
		m_rankingData[i].m_score_pos = CVector3D(-100, 250 + (i * 40),0);
		m_rankingData[i].score = 0;
		m_rankingData[i].livingflag = false;
		m_rankingData[i].Aflag = true;
		m_rankingData[i].Acount1 = 255;
		m_rankingData[i].Acount2 = 0;
		m_rankingData[i].angle = 90;
	}
	LoadDivGraph("media\\img\\score_number2.png", 12, 10, 2, 40, 40, m_scorenum_img);
	roadFile();
}

ScoreData::~ScoreData(){

}

void ScoreData::roadFile(){

	//入力ストリームの作成
	const string input = "scoredata.txt";
	ifstream ifs(input, ios::in);

	string buf;

	linedelimiter = ',';
	int i = 0;
	//一行づつ読み込む
	while (ifs && getline(ifs, buf))
	{
		string fn;

		istringstream iss(buf);
		getline(iss, fn, linedelimiter);

		int num1;
		iss >> num1;
		m_rankingData[i].score = num1;

		i++;
	}
	ifs.close();

}

void ScoreData::Update(){
	int tempC1;
	int tempC2 = 0;//m_total.score;
	if (m_rankingData[m_updateNum + 1].Aflag == true){
		m_rankingData[m_updateNum + 1].Acount2 += 6;
	}
	else{
		m_rankingData[m_updateNum + 1].Acount2 -= 6;
	}
	if (m_rankingData[m_updateNum + 1].Acount2 >= 255){
		m_rankingData[m_updateNum + 1].Aflag = false;
	}
	else if (m_rankingData[m_updateNum + 1].Acount2 <= 0){
		m_rankingData[m_updateNum + 1].Aflag = true;
	}
	for (int i = 0; i < SCORE_NUM; i++){
		if (m_rankingData[i].score < tempC2){
			tempC1 = m_rankingData[i].score;
			m_rankingData[i].score = tempC2;
			tempC2 = tempC1;
		}
		else{
			if (i == 4){
				m_updateNum = -2;
			}
			else
			{
				m_updateNum = i;
			}
		}
	}
	updatefile();
}

void ScoreData::updatefile(){

	int i = 0;
	//入力ストリーム
	const string input = "scoredata.txt";
	ifstream ifs(input, ios::in);

	//入出力ストリーム
	fstream fs(input, ios::in | ios::out);
	string buf;

	while (i < SCORE_NUM && ifs && getline(ifs, buf))
	{
		string fn;
		istringstream iss(buf);
		getline(iss, fn, linedelimiter);		//一つ目の","を飛ばす

		int num = m_rankingData[i].score;

		//ファイルに書き込み
		//書式設定(下記)を参照のこと
		fs << fn << linedelimiter << num << endl;
		i++;
	}
	ifs.close();
	fs.close();
}

void ScoreData::Draw(){
	int num;
	char buf[100];
	for (int i = 0; i < SCORE_NUM; i++){
		num = sprintf_s(buf, 100, "%d", m_rankingData[i].score);
		for (int j = 0; j < num; j++){
			if (i == m_updateNum + 1){
				//自分のスコア
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - m_rankingData[i].Acount1);
				DrawRotaGraph(390 + m_rankingData[i].m_score_pos.getX() + j * 25,
					m_rankingData[i].m_score_pos.getY(), 0.7, 0,
					m_scorenum_img[(buf[j] - '0')], TRUE, FALSE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_rankingData[i].Acount2);
				DrawRotaGraph(390 + m_rankingData[i].m_score_pos.getX() + j * 25,
					m_rankingData[i].m_score_pos.getY(), 0.7, 0,
					m_scorenum_img[(buf[j] - '&')], TRUE, FALSE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else{
				//スコア
				//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - m_rankingData[i].Acount1);
				DrawRotaGraph(390 + m_rankingData[i].m_score_pos.getX() + j * 25,
					m_rankingData[i].m_score_pos.getY(), 0.7, 0,
					m_scorenum_img[(buf[j] - '0')], TRUE, FALSE);
				//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
		//順位の数字
		if (i < SCORE_NUM){
			DrawRotaGraph(240 + m_rankingData[i].m_score_pos.getX(),
				m_rankingData[i].m_score_pos.getY(), 0.7, 0,
				m_scorenum_img[i + 1], TRUE, FALSE);
		}
		else{
			DrawRotaGraph(230 + m_rankingData[i].m_score_pos.getX(),
				m_rankingData[i].m_score_pos.getY(), 0.7, 0,
				m_scorenum_img[1], TRUE, FALSE);
			DrawRotaGraph(250 + m_rankingData[i].m_score_pos.getX(),
				m_rankingData[i].m_score_pos.getY(), 0.7, 0,
				m_scorenum_img[i - 9], TRUE, FALSE);
		}
	}
}