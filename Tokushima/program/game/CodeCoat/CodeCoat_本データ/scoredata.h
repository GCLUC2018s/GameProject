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
	float Acount1;		//���߃J�E���g�P
	float Acount2;		//���߃J�E���g�Q
	double angle;
	bool livingflag;
	bool Aflag;			//���߂��Ă��邩�ǂ���
};

class ScoreData :public CTask{	//�����L���O�Ŏg�p
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