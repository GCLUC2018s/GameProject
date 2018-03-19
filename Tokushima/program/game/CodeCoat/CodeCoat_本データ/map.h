//-------------------------
//Map.h 6/14
//-------------------------
#ifndef __MAP_H__
#define __MAP_H__
#include <DxLib.h>
#include "myLib.h"
#include <list>
#include "Task\CTask.h"

using namespace std;


const int IMAGECOUNT = 3;
const int GOAL_POINT = 8000;		//ÉSÅ[Éãínì_


class CMapControl : public CTask{
private:
	CVector3D m_posAsrc;
	CVector3D m_posBsrc;
	CVector3D m_goalpos;
	int m_clearpos;
	int m_img[IMAGECOUNT];
	bool m_goalflag;
	float m_totalmovement;
	float m_goalscrollstartpos;
public:
	CMapControl();
	~CMapControl();
	void Update();
	void Draw();
	bool getGoalFlag(){ return m_goalflag; }
	CVector3D getGoalPos(){ return m_goalpos; }
	float getTotalmovement()const{ return m_totalmovement; }
};

#endif __MAP_H__