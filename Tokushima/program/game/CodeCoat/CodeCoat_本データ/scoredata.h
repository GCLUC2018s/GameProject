#ifndef SCOREDATA_H
#define SCOREDATA_H

#include "myLib.h"
#include "Task\CTask.h"
#include <string>
#include <iostream>  //std::right, std::out, std::endl
#include <iomanip>	 //std::setw(int w)
#include <fstream>   // ifstream, ofstream
#include <sstream>   // istringstream, ostringstream

using namespace std;

const int SCORE_NUM = 5;

class SData{
public:
	CVector3D m_score_pos;
	int score;
	float Acount1;		//透過カウント１
	float Acount2;		//透過カウント２
	double angle;
	bool livingflag;
	bool Aflag;			//透過しているかどうか
};

class ScoreData :public CTask{	//ランキングで使用
private:
	char linedelimiter;
	int m_updateNum;
	int m_scorenum_img[12];
	SData m_rankingData[5];
public:
	ScoreData();
	~ScoreData();
	void Update();
	void Draw();
	void roadFile();
	void updatefile();
};


#endif SCOREDATA_H