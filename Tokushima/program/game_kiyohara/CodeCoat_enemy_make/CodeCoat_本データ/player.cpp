#include "player.h"
#include "player_manager.h"
#include "item_manager.h"
#include "DxLib.h"
#include <stdio.h>

CPlayerControl::CPlayerControl()
:CTask(0, eUDP_Player, eDWP_Player)
, m_gear(0)
, m_BodyPos(START_POSX, START_POSY)
, m_ShadowPos(START_POSX, START_POSY + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS)
{
	m_heroUpperimg = LoadGraph("media\\img\\knife_run_top.png", TRUE);
	m_heroLowerimg = LoadGraph("media\\img\\knife_run_under.png", TRUE);
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CPlayerManagerにCPlayerControlのアドレスを渡すための関数
	CPlayerManager::GetInstance()->Init(this);
}

CPlayerControl::~CPlayerControl(){
}

void CPlayerControl::Update(/*CMapControl *Map,CItemControl *Item*/){

	

	//if (Map->getGoalFlag() != true){
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		float hx = m_BodyPos.getX();
		float hy = m_BodyPos.getY();
		float mv = P_SPEED * FRAMETIME;		//200
		if (key & PAD_INPUT_LEFT){
			hx -= mv;
			m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));		//現状if分の削減のためだけに等間隔でgearの数値が変わるようにしている、変更が必要なら話してくれ
			/*if (m_playerstate != Jump)
				m_playerstate = Move;*/
		}
		else if (key & PAD_INPUT_RIGHT){
			hx += mv;
			m_gear = (m_BodyPos.getX() / (ONE_GEAR_SPACE));
			/*if (m_playerstate != Jump)
				m_playerstate = Move;*/
	}
		if (key & PAD_INPUT_UP){
			hy -= mv;
			/*if (m_playerstate != Jump)
				m_playerstate = Move;*/
	}
		else if (key & PAD_INPUT_DOWN){
			hy += mv;
			/*if (m_playerstate != Jump)
			m_playerstate = Move;*/
		}
		
		if ((int)m_gear == 5){
			m_gear = m_gear + m_BodyPos.getX() / (ONE_GEAR_SPACE) / 3;
		}
		if ((int)m_gear == 0){
			m_gear = 0.0f;
		}

	
		//移動範囲外だと座標の移動を無効化
		if (hx < MOVEING_RANGE_LEFT)hx = m_BodyPos.getX();
		if (hx > MOVEING_RANGE_RIGHT) hx = m_BodyPos.getX();
		if (hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS > MOVEING_RANGE_DOWN) hy = m_BodyPos.getY();
		if (hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS < MOVEING_RANGE_UP)hy = m_BodyPos.getY();
		
		//-------------------------------
		//ここからアイテムとの当たり判定
		//-------------------------------
		float ax1 = hx + 5;
		float ay1 = hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS + 5;
		float ax2 = hx + PLAYER_WIDE_SIZE - 5;
		float ay2 = hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS + PLAYER_HEIGHT_SIZE - 5;
		float bx1, bx2, by1, by2;
		
		//アイテムのリストを取得する
		auto Idata = CItemManager::GetInstance()->GetItemList();
		
		for (auto it = Idata.begin(); it != Idata.end(); it++){
			//アイテムの当たり判定の範囲、確認用に大きめ
			bx1 = (*it)->GetPos().getX();
			by1 = (*it)->GetPos().getY();
			bx2 = (*it)->GetPos().getX() + 200;
			by2 = (*it)->GetPos().getY() + 200;

			if ((ax1 < bx2) && (bx1 < ax2) && (ay1 < by2) && (by1 < ay2)){
				//アイテムと重なるとアイテムは消失する
				(*it)->SetKill();
				CItemManager::GetInstance()->Remove((*it));
				/*ItemData = Item->pickupItem(it->m_pos);
				m_Equipment[ItemData.m_type].m_img = ItemData.m_img;
				m_Equipment[ItemData.m_type].m_name = ItemData.m_name;
				m_Equipment[ItemData.m_type].m_type = ItemData.m_type;
				m_Equipment[ItemData.m_type].m_useful = ItemData.m_useful;*/
			}
		}
		//試運転
			
		/*TP++;
		TP %= 60;
		if (TP == 0){
			Item->makeItem(CVector2D(600, 250), KNIFE);
			
		}*/
		//影と体の場所を更新
		m_BodyPos = CVector2D(hx, hy);
		m_ShadowPos = CVector2D(hx, hy + PLAYER_LOWER_SIZE + PLAYER_SHADOW_POS);


	//}
	//else{
		//goalposが0になるまでに定位置についておく
		//goalposが0になるとアニメーション開始　animconterで動きを管理する
		//主人公が車と重なると姿を消し、クリア
		//もしくはkeyに特定の情報を入力し、動きをつける
	//}


}

void CPlayerControl::Draw(){
	//見た目の関係で影、下半身、上半身の順番で描画
	DrawGraph((int)m_ShadowPos.getX(), (int)m_ShadowPos.getY(), m_shadowimg, TRUE);
	DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY() /*+ PLAYER_LOWER_SIZE*/, m_heroLowerimg, TRUE);
	DrawGraph((int)m_BodyPos.getX(), (int)m_BodyPos.getY(), m_heroUpperimg, TRUE);
}

float CPlayerControl::getMoveAmount(){
	//仮：移動量 = (ギア*基本速度-装備重量)*バフ効果
	return (m_gear * BASE_SCR_SPEED*1.5f) * FRAMETIME;
}