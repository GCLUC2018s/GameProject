#include "player.h"
#include "taskmanager.h"
#include "DxLib.h"
#include <stdio.h>

//void Player::update(){
//printfDx("player");
//}

//’eŠÛ‚ÌƒNƒ‰ƒX
CBullet::CBullet(int x,int y){
	m_img = LoadGraph("media\\img\\tama.png", TRUE);
	m_x = x;
	m_y = y;
	CTaskManager::GetInstance()->Add(this);
}


CBullet::~CBullet(){
	
}

void CBullet::Update(){
	m_y -= 5;
	if (m_y < 0)
		m_destroyFlg = true;
}

void CBullet::Draw(){
	DrawGraph(m_x, m_y, m_img, TRUE);
}


CPlayer::CPlayer(){
	m_img = LoadGraph("media\\img\\player.png",TRUE);
	x = 400;
	y = 500;
	printfDx("Player");
	CTaskManager::GetInstance()->Add(this);
}

CPlayer::~CPlayer()
{

}
void CPlayer::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	float hx = x;
	float hy = y;
	float mv = P_SPEED * FRAMETIME;		//200

	if (key & PAD_INPUT_LEFT){
		hx -= mv;
	}
	else if (key & PAD_INPUT_RIGHT){
		hx += mv;
	}
	if (key & PAD_INPUT_UP){
		hy -= mv;
	}
	else if (key & PAD_INPUT_DOWN){
		hy += mv;
	}

	if (hx < 0 || hx > 700)
		hx = x;
	if (hy < 0 || hy > 500)
		hy = y;
	x = hx;
	y = hy;
	if (key & PAD_INPUT_1){
		new CBullet(x, y);
	}



	/*clsDx();
	printfDx("%d", x);
	x++;*/
	

}
void CPlayer::Draw()
{
	DrawGraph(x, y, m_img, TRUE);
}