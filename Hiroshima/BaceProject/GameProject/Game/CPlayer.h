#pragma once
#include "CBase.h"

class CPlayer :public CBase{
	/*
	bool	m_ground;	//���n�t���O
	int		m_state;	//���
	bool	m_slash;	//�a���G�t�F�N�g�����t���O
	int		m_jump_cnt;	//�W�����v��
	*/
public:
	CPlayer();
	~CPlayer();
	void Draw();
	void Update();
};