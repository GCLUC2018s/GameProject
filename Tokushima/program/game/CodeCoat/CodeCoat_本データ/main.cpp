#include "main.h"
#include "game.h"

CMain::CMain(){
	m_pGame = new CGame;
}

CMain::~CMain()
{
	delete m_pGame;
	m_pGame = 0;
}

void CMain::Dest()
{
	m_pGame->Dest();
}

void CMain::Update()
{
	m_pGame->Update();
}

void CMain::Draw()
{
	m_pGame->Draw();
}
