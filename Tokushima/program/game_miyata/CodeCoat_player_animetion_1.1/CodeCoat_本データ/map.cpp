//-----------------------------
//map.cpp 6/14
//-----------------------------

#include "map.h"
#include "map_manager.h"
#include "player_manager.h"

CMapControl::CMapControl()
:CTask(0, eUDP_Map, eDWP_Map)
, m_posAsrc(0.0f, 0.0f,0.0f)
, m_posBsrc(0.0f, 0.0f,0.0f)
, m_clearpos(4000)
, m_goalpos(1280.0f,0.0f,0.0f)
, m_goalflag(false)
, m_goalscrollstartpos(0)
{
	m_totalmovement = 0;
	char *item[] = { "kari_haikei5.png", "kari_oku_bg2.png", "goal.png" };
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
	m_totalmovement += _Amount;
	
	if ((m_totalmovement > m_clearpos) && m_goalflag == false){
		m_goalflag = true;
		float splint = 2560 + m_posAsrc.getX();
		int flag = splint / 1280;

		if (flag){
			m_goalpos.setX(m_goalpos.getX() + 1280 - splint); //1280 - splint; ←次の端までの値　splintの中身は-なので減算している
		}
		else{
			m_goalpos.setX(m_goalpos.getX() + splint + 1280);// splint + 1280; ←次の端までの値
		}
	}
	m_posAsrc.setX(m_posAsrc.getX() - _Amount);
		if (m_posAsrc.getX() <= -2560)
			m_posAsrc.setX(0);
		m_posBsrc.setX(m_posBsrc.getX() - (_Amount / 5));
		if (m_posBsrc.getX() <= -1280)
			m_posBsrc.setX(0);
		if (m_goalflag){

			if (m_goalpos.getX() > 0){
				m_goalpos.setX(m_goalpos.getX() - _Amount);
			if (m_goalpos.getX() < 0)
				m_goalpos.setX(0.0f);
		}
		}
	
}
//ゴールはポジションを超えたら残りの2560のところまで走り切り、その続きにゴールの座標を置くようにする
//ゴールのポジションを超えて尚且つ残りの2560のところに
void CMapControl::Draw(){
	//裏から描画するために分けている
	
	DrawGraph((int)m_posBsrc.getX(), (int)m_posBsrc.getY(), m_img[1], TRUE);
	DrawGraph((int)m_posBsrc.getX() + 1280, (int)m_posBsrc.getY(), m_img[1], TRUE);
	DrawGraph((int)m_posAsrc.getX(), (int)m_posAsrc.getY(), m_img[0], TRUE);
	DrawGraph((int)m_posAsrc.getX() + 2560 , (int)m_posAsrc.getY(), m_img[0], TRUE);
	DrawGraph((int)m_goalpos.getX(), (int)m_goalpos.getY(), m_img[2], TRUE);

}

