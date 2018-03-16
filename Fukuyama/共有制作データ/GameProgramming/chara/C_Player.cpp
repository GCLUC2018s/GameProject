#include "C_Player.h"

C_Player *C_Player::m_Playerpoint = 0;

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

	if (m_Anime_Jump < 60){
		m_Anime_Jump++;
	}

	//C�L�[�ł���{�[���𓊂��܂�
	if (CKey::Once('C')){
		C_ColorBall* ColorBall = new C_ColorBall();
	}

	//�������n���[�V�������Ȃ瑀�삪�ł��Ȃ�
	if (m_Anime_Jump > JUMP_ANIME){
		//S�L�[�ŃW�����v���܂�
		if (CKey::Once('S') && m_Jump == E_NJUMP){
			//�W�����v���Ă��邩�ǂ����^�O�����܂�
			m_Jump = E_JUMP;
			//�W�����v�������s�����Ԃ��v�Z���܂��B
			m_JumpTime = -2 * (JUMP_FIRST_SPEED / m_Gravity.y);
		}
		//�E�ړ�
		if (CKey::Push(VK_RIGHT)){
			m_Turn = E_RIGHT;
			m_Scroll += PLAYER_LR_SPEED;
			m_Position.x += PLAYER_LR_SPEED;
			i_JumpPoint.x += PLAYER_LR_SPEED;
		}
		//���ړ�
		if (CKey::Push(VK_LEFT) && m_Position.x >= (-W_H) / 2){
			m_Turn = E_LEFT;
			m_Scroll -= PLAYER_LR_SPEED;
			m_Position.x -= PLAYER_LR_SPEED;
			i_JumpPoint.x -= PLAYER_LR_SPEED;
		}
		//��ړ�
		if (CKey::Push(VK_UP) && i_JumpPoint.z <= DISPLAY_TOP - 390){
			m_Position.z += PLAYER_UD_SPEED;
			i_JumpPoint.z += PLAYER_UD_SPEED;
		}
		//���ړ�
		if (CKey::Push(VK_DOWN) && i_JumpPoint.z >= DISPLAY_BOTTOM + 120 ){
			m_Position.z -= PLAYER_UD_SPEED;
			i_JumpPoint.z -= PLAYER_UD_SPEED;
		}
	}

		//�W�����v������
	if (m_Jump==E_JUMP){
		//�W�����v���̋O���v�Z
		Jump(m_Position, m_Speed, m_Gravity, 2.0f / FPS);
			m_Position.z += m_Speed.y;
		m_JumpTime -= 2.0 / FPS;
		//���n������
		if (m_JumpTime <= 0){
			//�؋󎞊Ԃ̏�����
			m_JumpTime = 0;
			//�W�����v�^�O�𖳌���
			m_Jump = E_NJUMP;
			//�ʒu�v�Z�p�ϐ��̏�����
			m_Position.y = 0;
			//�W�����v�̏������Đݒ�
			m_Speed.y = JUMP_FIRST_SPEED;
			//�e�̈ʒu�ƃv���C���[�̈ʒu�𓯊�
			i_JumpPoint=m_Position;
			//���n���̃A�j���p�ϐ��̏�����
			m_Anime_Jump = 0;
			//���n���덷����
			m_Position.z += 18;
			i_JumpPoint.z += 18;
		}
	}

	//�X�N���[����_
	m_Scroll = m_Position.x + SCROLL_POINT;

	//�X�N���[�������i�L�����Ɖe�j
	C_Object::Scroll(&m_Position, m_Scroll);
	C_Object::Scroll(&i_JumpPoint, m_Scroll);

	//�L�����̕`��ʒu���|�W�V�����Ɠ���
	C_Object::Rect(&m_image,&m_Position);
	//�e�̕`��ʒu���|�W�V�����Ɠ���
	C_Object::Rect(&i_Shadow, &i_JumpPoint);
}

//�v���C���[�̕`��
void C_Player::Draw(){

	//�e�̕`��
	i_Chara_Motion_2.DrawImage(i_Shadow.m_Left, i_Shadow.m_Right, i_Shadow.m_Bottom-3, i_Shadow.m_Top-3, 630, 720, 275, 140);

	//�W�����v���Ă��Ȃ��B���A�������[�V�������łȂ��B���A���n���[�V�������łȂ�
	if (m_Jump == E_NJUMP&&m_Throw == E_NTHROW){
		m_Anime_Throw = 0;
		//�W�����v�A�j���̃J�E���^���񂵂܂�
		if (m_Anime_Jump <= JUMP_ANIME){
			if (m_Turn==E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 275, 140);
			else if (m_Turn==E_LEFT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 275, 140);
		}
		else if(m_Anime_Jump>JUMP_ANIME){

			//�ҋ@�p�A�j���[�V�����J�E���^��1�b����
			if (m_Anime_Taiki <= 60)
				m_Anime_Taiki++;

			//�ҋ@�p�A�j���[�V�����J�E���^�����Z�b�g��
			else if (m_Anime_Taiki > 60){
				m_Anime_Taiki = 0;
			}

			//����p�̃L�[���삪�Ȃ���Αҋ@�G��`��
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
				//�����j���O�A�j���[�V�����J�E���^��1�b����
				if (m_Anime < RUN_ANIME){
					m_Anime++;
				}
				//�����j���O�A�j���[�V�����J�E���^�����Z�b�g���܂��B
				if (m_Anime >= RUN_ANIME){
					m_Anime = 0;
				}
			}
			else{
				m_Anime = -1;       //�A�j���[�V������0�`�͈̔͂ōs���̂ŁA�g�p���Ȃ����́[�P�Ƃ��܂��B
			}

			//�ړ����[�V������
			if (CKey::Push(VK_LEFT)){
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
					else if (m_Anime < RUN_ANIME_INTERVAL * 4){
						i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
					}
					else if (m_Anime < RUN_ANIME_INTERVAL * 5){
						i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
					}
					else if (m_Anime < RUN_ANIME_INTERVAL * 6){
						i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
					}
					else if (m_Anime == RUN_ANIME - 1){
						m_Anime = 0;
					}
				}
			}
			//�ړ����[�V�����̕`��(�E����)
			if (CKey::Push(VK_UP) || CKey::Push(VK_DOWN)){
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
					else if (m_Anime < RUN_ANIME_INTERVAL * 4){
						i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
					}
					else if (m_Anime < RUN_ANIME_INTERVAL * 5){
						i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
					}
					else if (m_Anime < RUN_ANIME_INTERVAL * 6){
						i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
					}
					else if (m_Anime == RUN_ANIME - 1){
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

			//�E�ƍ��𓯎��ɓ��͂����ꍇ�͑ҋ@�G��`��
			if (CKey::Push(VK_RIGHT) && CKey::Push(VK_LEFT)){
				if (m_Turn == E_RIGHT)
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
				else if (m_Turn == E_LEFT)
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
			}
		}
	}

	//�W�����v���̃A�j���[�V����
	if (m_Jump == E_JUMP){
		//�E����
		if (m_Turn == E_RIGHT){
			if (m_Speed.y > 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 275, 140);
			}
			else if (m_Speed.y < 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 275, 140);
			}
		}
		//������
		else if (m_Turn == E_LEFT){
			if (m_Speed.y > 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 275, 140);
			}
			else if (m_Speed.y < 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 275, 140);
			}
		}
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