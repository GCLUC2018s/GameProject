#include "npc.h"
#include "npc_manager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include <stdio.h>
#include "map_manager.h"

CNpc::CNpc()
:CTask(0, eUDP_Player, eDWP_Player)
{
	m_shadowimg = LoadGraph("media\\img\\Pshadow.png", TRUE);
	//CPlayerManager‚ÉCNpc‚ÌƒAƒhƒŒƒX‚ð“n‚·‚½‚ß‚ÌŠÖ”
	CNpcManager::GetInstance()->Init(this);
}

CNpc::~CNpc(){
}

void CNpc::Update(){
	
}

void CNpc::Draw(){

}