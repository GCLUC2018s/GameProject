//-----------------------------
//map.cpp 6/14
//-----------------------------

#include "map.h"
#include "map_manager.h"
#include "player_manager.h"
#include "npc_manager.h"

CMapControl::CMapControl()
:CTask(0, eUDP_Map, eDWP_Map)
, m_posAsrc(0.0f, -250.0f,0.0f)
, m_posBsrc(0.0f, -250.0f,0.0f)
, m_clearpos(GOAL_POINT)
, m_goalpos(1280.0f,0.0f,0.0f)
, m_goalflag(false)
, m_goalscrollstartpos(0)
{
	m_totalmovement = 0;
	char *item[] = { "bg_front.png", "bg_back.png", "goal.png" };
	char buf[256];
	for (int i = 0; i < IMAGECOUNT; i++){
		sprintf_s(buf, "media\\img\\%s", item[i]);
		m_img[i] = LoadGraph(buf);
	}
	CMapManager::GetInstance()->Init(this);
}

CMapControl::~CMapControl(){
}

void CMapControl::Update(){
	float _Amount = CPlayerManager::GetInstance()->GetPlayerAdress()->getMoveAmount();
	if (!CNpcManager::GetInstance()->GetNpcAdress()->getDashFlag())
		m_totalmovement += _Amount;

	if ((m_totalmovement > m_clearpos) && m_goalflag == false){
		m_goalflag = true;
	}
	if (m_goalflag  == false){
	m_posAsrc.setX(m_posAsrc.getX() - _Amount);
	if (m_posAsrc.getX() <= -3840)
		m_posAsrc.setX(0);
	m_posBsrc.setX(m_posBsrc.getX() - (_Amount / 3));
	if (m_posBsrc.getX() <= -1280)
		m_posBsrc.setX(0);
	}
	else
	{
	}
}

//ゴールはポジションを超えたら残りの2560のところまで走り切り、その続きにゴールの座標を置くようにする
//ゴールのポジションを超えて尚且つ残りの2560のところに
void CMapControl::Draw(){
	//裏から描画するために分けている
	float _yscr = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	if (_yscr > 250.0f)
		_yscr > 250.0f;
	float _yscr2 = CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos().getY();
	if (_yscr2 > 50.0f)
		_yscr2 > 50.0f;
	DrawGraph((int)m_posBsrc.getX(), (int)m_posBsrc.getY() - (_yscr2/2), m_img[1], TRUE);
	DrawGraph((int)m_posBsrc.getX() + 1280, (int)m_posBsrc.getY() - (_yscr2/2), m_img[1], TRUE);
	DrawGraph((int)m_posAsrc.getX(), (int)m_posAsrc.getY() - _yscr, m_img[0], TRUE);
	DrawGraph((int)m_posAsrc.getX() + 3840, (int)m_posAsrc.getY() - _yscr, m_img[0], TRUE);
	DrawGraph((int)m_goalpos.getX(), (int)m_goalpos.getY(), m_img[2], TRUE);

}

