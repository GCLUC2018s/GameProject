#include "CDrum.h"
#include "../CCollider.h"
#include "../task/CTaskManager.h"
//�e�N�X�`���N���X���C���X�^���X��
CTexture mTexture;

void C_Drum::Dmain(){
	//�V�[�h�ŗ�����������
	srand((unsigned)time(NULL));
}

//�A�j���[�V�����J�E���g
int m_DrumAnimationCount = 30;
//�h�����ʂ̈ړ�����
#define Drum_Move 4
//�R���X�g���N�^�ŏ�����
C_Drum::C_Drum()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_DrumPos_Random(rand() % 3)
{
	mTexture.Load("object/Drum.tga");
	//0�̏ꍇ�A�^�񒆂ɔz�u
	if (m_DrumPos_Random == 0){
		m_Position.z += Zpos_SetPos_Center;
	}
	//1�̏ꍇ�A��ɔz�u
	else if (m_DrumPos_Random == 1){
		m_Position.z += Zpos_SetPos_Up;
	}
	//2�̏ꍇ�A���ɔz�u
	else if (m_DrumPos_Random == 2){
		m_Position.z += Zpos_SetPos_Down;
	}
}

//�X�V����
void C_Drum::Update(){
	m_image.SetVertex(-64, 64, -64, 64);
	//�X�N���[������
	Scroll(&m_Position, m_Scroll);
	//��ʍ��[�ɍs������
	if (m_Position.x < DISPLAY_LEFT){
		SetKill();
		new C_Drum();
	}
	m_DrumAnimationCount--;
	m_Position.x -= Drum_Move;
	//�A�j���[�V��������
	if (m_DrumAnimationCount >= 24){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	}
	else if (m_DrumAnimationCount <= 24 && m_DrumAnimationCount >= 18){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 128, 256, 128, 0);
	}
	else if (m_DrumAnimationCount <= 18 && m_DrumAnimationCount >= 12){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 256, 384, 128, 0);
	}
	else if (m_DrumAnimationCount <= 12 && m_DrumAnimationCount >= 6){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 384, 512, 128, 0);
	}
	else if (m_DrumAnimationCount <= 6 && m_DrumAnimationCount >= 0){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 512, 640, 128, 0);
	}
	else{
		m_DrumAnimationCount = 30;
	}
	//�Փ˔���
	m_Colimage = m_image;

	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
}

bool C_Drum::Collision(CTask* p, CTask* q){
	C_Object* ip_My = (C_Object*)p;
	C_Object* ip_You = (C_Object*)q;
	ip_My->m_Collision_Wide = 50;
	if (ip_You->m_id == E_PLAYER&&
		C_Collider::Collision(ip_My, ip_You, &ip_My->m_Position, &ip_You->m_Position)){
		ip_You->m_Position.x += ip_You->m_Colimage.m_AdjustX;
		ip_You->m_Position.z += ip_You->m_Colimage.m_AdjustZ;
		ip_You->m_Position.x += ip_You->m_Colimage.m_AdjustX;
		ip_You->m_Position.z += ip_You->m_Colimage.m_AdjustZ;
	}
	return true;
}
void C_Drum::Drum_Rect(C_Rectangle *image, const C_Vector3* pos){
	image->m_wide = (image->m_Right - image->m_Left) / 2;  //�|�W�V��������C_Rectangle�̍��E�܂ł̋���
	image->m_high = (image->m_Top - image->m_Bottom) / 2;  //����
	image->m_Right = pos->x + image->m_wide;
	image->m_Left = pos->x - image->m_wide;
	image->m_Bottom = pos->z - image->m_high;
	image->m_Top = pos->z + image->m_high;
	return;
}
//�`�揈��
void C_Drum::Draw(){
	Drum_Rect(&m_image, &m_Position);
}

