#include "C_Player.h"

void C_Player::Jump(C_Vector3& pos, C_Vector3& speed, const C_Vector3& gravity, float deltatime)
{
	speed.x += gravity.x*deltatime;
	speed.y += gravity.y*deltatime;
	speed.z += gravity.z*deltatime;

	pos.x += speed.x*deltatime;
	pos.y += speed.y*deltatime;
	pos.z += speed.z*deltatime;
	printf("�ŏI���ʁi%f,%f,%f)    ", pos.x, pos.y, pos.z);
	printf("�f���^�^�C��    %f\n", deltatime);
	//return pos;
}

void C_Player::Update(){

	//S�L�[�ŃW�����v���܂�
	if (CKey::Once('S')&&m_Jump==E_NJUMP){
		//�W�����v���Ă��邩�ǂ����^�O�����܂�
		m_Jump = E_JUMP;
		//�W�����v�������s�����Ԃ��v�Z���܂��B
		m_JumpTime = -2 * (JUMP_FIRST_SPEED / m_Gravity.y);


	}

		//�E�ړ�
		if (CKey::Push(VK_RIGHT)){
			m_Scroll += PLAYER_LR_SPEED;
			m_Position.x += PLAYER_LR_SPEED;
		}
		//���ړ�
		if (CKey::Push(VK_LEFT) && m_Position.x >= (-W_H) / 2){
			m_Scroll -= PLAYER_LR_SPEED;
			m_Position.x -= PLAYER_LR_SPEED;
		}
		//��ړ�
		if (CKey::Push(VK_UP) && i_JumpPoint.z <= DISPLAY_TOP - 390){
			m_Position.z += PLAYER_UD_SPEED;
			i_JumpPoint.z += PLAYER_UD_SPEED;
		}
		//���ړ�
		if (CKey::Push(VK_DOWN) && i_JumpPoint.z >= DISPLAY_BOTTOM){
			m_Position.z -= PLAYER_UD_SPEED;
			i_JumpPoint.z -= PLAYER_UD_SPEED;
		}

		//�W�����v������
	if (m_Jump==E_JUMP){
		Jump(m_Position, m_Speed, m_Gravity, 2.0f / FPS);
			m_Position.z += m_Speed.y;
		m_JumpTime -= 2.0 / FPS;
		if (m_JumpTime <= 0){
			m_JumpTime = 0;
			m_Jump = E_NJUMP;
			m_Speed.y = JUMP_FIRST_SPEED;
			i_JumpPoint=m_Position;
		}
	}

	//�X�N���[����_
	m_Scroll = m_Position.x + SCROLL_POINT;
	C_Object::Rect(&m_image,&m_Position);
	C_Object::Scroll(&m_Position,m_Scroll);
}

//�v���C���[�̕`��
void C_Player::Draw(){

	//�A�j���[�V�����J�E���^��1�b����
	if (m_Anime_Taiki <= 60)
		m_Anime_Taiki++;

	//�A�j���[�V�����J�E���^�����Z�b�g��
	else if (m_Anime_Taiki > 60){
		m_Anime_Taiki = 0;
	}

	if (!(CKey::Push(VK_LEFT) || CKey::Push(VK_RIGHT) || CKey::Push(VK_UP) || CKey::Push(VK_DOWN))){
		if (m_Anime_Taiki <= 60){
			if (m_Turn == E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
			else if (m_Turn == E_LEFT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
		}
	}

	//�����j���O�A�j���̃A�j���[�V�����J�E���^����
	if (CKey::Push(VK_LEFT) || CKey::Push(VK_RIGHT) || CKey::Push(VK_UP) || CKey::Push(VK_DOWN)){
		//�A�j���[�V�����J�E���^��1�b����
		if (m_Anime < RUN_ANIME){
			m_Anime++;
		}
		//�A�j���[�V�����J�E���^�����Z�b�g���A�o�ߎ���(�b)��ǉ�����
		if (m_Anime >= RUN_ANIME){
			m_Anime = 0;
		}
	}
	else{
		m_Anime = -1;       //�A�j���[�V������0�`�͈̔͂ōs���̂ŁA�g�p���Ȃ����́[�P�Ƃ��܂��B
	}

	//�ړ����[�V������
	if (CKey::Push(VK_LEFT)){
		m_Turn = E_LEFT;
		if (!CKey::Push(VK_RIGHT)){
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 4){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 5){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 6){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}
	}

	//�ړ����[�V�����E
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		if (!CKey::Push(VK_LEFT)){
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
			}
			else if (m_Anime <RUN_ANIME_INTERVAL * 4){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
			}
			else if (m_Anime <RUN_ANIME_INTERVAL * 5){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
			}
			else if (m_Anime <RUN_ANIME_INTERVAL * 6){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}
	}
	    //�ړ����[�V�����̕`��(�E����)
		if (CKey::Push(VK_UP)||CKey::Push(VK_DOWN)){
			if (m_Turn == E_RIGHT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
				}
				else if (m_Anime <RUN_ANIME_INTERVAL * 4){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
				}
				else if (m_Anime <RUN_ANIME_INTERVAL * 5){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
				}
				else if (m_Anime <RUN_ANIME_INTERVAL * 6){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
				}
				else if (m_Anime == RUN_ANIME-1){
					m_Anime = 0;
				}
			}
			if (m_Turn == E_LEFT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
		}

		if (CKey::Push(VK_RIGHT) && CKey::Push(VK_LEFT)){
			if (m_Turn == E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
			else if (m_Turn == E_LEFT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
		}
}


//�e�X�g�N���X

void C_Test::Update(){
	C_Object::Rect(&m_image, &m_Position);
	C_Object::Scroll(&m_Position, m_Scroll);
}

void C_Test::Draw(){
	glBegin(GL_TRIANGLES);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Left, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Top);
	glEnd();
}