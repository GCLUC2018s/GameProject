#include "C_Object.h"

float C_Object::m_Scroll = SCROLL_POINT;

void C_Object::Rect(C_Rectangle *image,const C_Vector3* pos){
	image->m_wide = (image->m_Right - image->m_Left) / 2;  //�|�W�V��������C_Rectangle�̍��E�܂ł̋���
	image->m_high = (image->m_Top - image->m_Bottom);  //����
	image->m_Right = pos->x + image->m_wide;
	image->m_Left = pos->x - image->m_wide;
	image->m_Bottom = pos->z;
	image->m_Top = image->m_Bottom +image->m_high;
	return;
}

void C_Object::Scroll(C_Vector3 *m_pos,float m_Scroll){
	if (CKey::Push(VK_RIGHT) && m_Scroll >= DISPLAY_RIGHT){
		m_pos->x -= SCROLL_SPEED;
		if (m_id == E_PLAYER){
			m_Scroll -= SCROLL_SPEED;
		}
	}
	return;
}


/*
�����j���O�A�j���̕`��
image�E�E�E�g�p����摜
id�E�E�E�L�����N�^�[�̎��ʁim_id���g�p���Ă��������j
*/
void C_Object::RunAnime(CTexture *image, int id){

	//�����j���O�A�j���[�V�����J�E���^��1�b����
	if (m_Anime < RUN_ANIME){
		m_Anime++;
	}
	//�����j���O�A�j���[�V�����J�E���^�����Z�b�g���܂��B
	if (m_Anime >= RUN_ANIME){
		m_Anime = 0;
	}

	//id���v���C���[�̎��̕`����s���܂�
	if (id == E_PLAYER){
		//�ړ����[�V������
		if (CKey::Push(VK_LEFT)){
			if (!CKey::Push(VK_RIGHT)){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
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
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
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
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
			if (m_Turn == E_LEFT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
		}

		//�E�ƍ��𓯎��ɓ��͂����ꍇ�͑ҋ@�G��`��
		if (CKey::Push(VK_RIGHT) && CKey::Push(VK_LEFT)){
			if (m_Turn == E_RIGHT)
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
			else if (m_Turn == E_LEFT)
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
		}
	}

	//�v���C���[�ȊO�̃L�����N�^�[�̃����j���O�A�j���[�V����
	else{
		//������
		if (m_Turn == E_LEFT){
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 4){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 5){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 6){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}
		//�E����
		else{
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 4){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 5){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 6){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}

	}
}



/*
�ҋ@�A�j���̕`��
image�E�E�E�g�p����摜
id�E�E�E�L�����N�^�[�̎��ʁim_id���g�p���Ă��������j
*/
void C_Object::TaikiAnime(CTexture *image, int id){

	//�ҋ@�p�A�j���[�V�����J�E���^��1�b����
	if (m_Anime_Taiki <= 60)
		m_Anime_Taiki++;

	//�ҋ@�p�A�j���[�V�����J�E���^�����Z�b�g
	else if (m_Anime_Taiki > 60)
		m_Anime_Taiki = 0;


	//�ړ��p�̃L�[���͂��Ȃ���Αҋ@�G��`��
	if (m_Anime_Taiki <= 60){
		if (m_Turn == E_RIGHT)
			image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
		else if (m_Turn == E_LEFT)
			image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
	}
}
void C_Object::EnemyTaiki(CTexture *image, int id){
	if (m_Turn == E_RIGHT)
		image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 714, 804, 140, 5);
	else if (m_Turn == E_LEFT)
		image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 804, 714, 140, 5);
}