#include "C_Player.h"

void C_Player::Init(){
	//�A�j���[�V�����J�E���^�̏�����
	m_Anime = 0;
	m_Anime_s = 0;
}

void C_Player::Update(){
	//�A�j���[�V�����J�E���^��1�b����
	if (m_Anime < 60)++m_Anime;
	//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ��Ԃ�ǉ�����
	else if (m_Anime == 60){
		m_Anime = 0;
		++m_Anime_s;
	}

	
}
void C_Player::Draw(){
	if (!(CKey::Push(VK_RIGHT) 
		|| CKey::Push(VK_LEFT)
		|| CKey::Push(VK_UP)
		|| CKey::Push(VK_DOWN))){
		if (m_Anime >= 0){
			i_Chara_Motion_1.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 135, 0);
		}
	}
}