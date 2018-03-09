#include "enemy.h"
#include "taskmanager.h"
#include "DxLib.h"
#include <stdio.h>

CEnemy::CEnemy(){
	m_img = LoadGraph("media\\img\\enemy.png", TRUE);
	x = 400;
	y = -200;
	CTaskManager::GetInstance()->Add(this);
}

CEnemy::~CEnemy()
{

}
void CEnemy::Update()
{
	clsDx();
	printfDx("Enemy");
	y+=5;
	if (y > 600)
		m_destroyFlg = true;
}
void CEnemy::Draw()
{
	DrawGraph(x, y, m_img, TRUE);
}