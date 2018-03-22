#include "CBackGround.h"

#define TextureimageWide_BG 600

//�w�i�p�e�N�X�`�����C���X�^���X��
CTexture BG1;
CTexture BG2;
//�w�i�N���X�̃R���X�g���N�^
C_BackGround::C_BackGround()
:C_Object(E_BG, eUDP_Map, eDWP_Map, 0, 0, -450)
{
	BG1.Load("Asphalt&Sky.tga");
	m_image.SetVertex(-600, 600, -450, 450);
	BG2.Load("Asphalt&Sky.tga");
}

//�w�i�N���X�̍X�V����
void C_BackGround::Update(){
	Scroll(&m_Position, m_Scroll);
	BG1.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top //���W
		, 0, 1200, 900, 0 /*�e�N�X�`�����W*/);
	BG2.DrawImage(m_image.m_Left + TextureimageWide_BG * 2, m_image.m_Right + TextureimageWide_BG * 2, m_image.m_Bottom, m_image.m_Top,
		0, 1200, 900, 0);
	if (m_image.m_Right <= -TextureimageWide_BG){
		m_Position.x += TextureimageWide_BG * 2;
	}
}

//�e�N�X�`���N���X���_�p��Instance��
CTexture i_CloudTexture;

//�_�N���X�̃R���X�g���N�^
C_Cloud::C_Cloud()
:C_Object(E_BG, eUDP_Map, eDWP_Map, 0, 0, 0)
{
	//�傫����ݒ肵�܂�
	m_image.SetVertex(-64, 64, -64, 64);
}

//�_�N���X�̍X�V����
void C_Cloud::Update(){
	//�X�N���[��
	Scroll(&m_Position, m_Scroll);
}

//�w�i�N���X�̕`�揈��
void C_BackGround::Draw(){
	Rect(&m_image, &m_Position);
}

//�_�N���X�̕`�揈��
void C_Cloud::Draw(){
	Rect(&m_image, &m_Position);
}