#pragma once
#include "CBase.h"

class CPlayer :public CBase{
	/*
	bool	m_ground;	//着地フラグ
	int		m_state;	//状態
	bool	m_slash;	//斬撃エフェクト発生フラグ
	int		m_jump_cnt;	//ジャンプ回数
	*/
public:
	CPlayer();
	~CPlayer();
	void Draw();
	void Update();
};