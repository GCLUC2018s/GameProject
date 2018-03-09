/*!
	@brief	�摜�`��N���X cpp
	@author	s.namizashi
**/

#include "Source/Include.hpp"
#include "Image.hpp"

namespace
{
	// �萔
	const int	IHUNDLE_INVALID	= -1;				// �����摜�n���h��
	const char*	IMAGE_DIR_PATH	= "Data/Image/";	// �ǂݍ��݃f�B���N�g���p�X
}

// �R���X�g���N�^
clImage::clImage()
	: m_Pos(0.0f,0.0f)
	, m_UV(0,0,0,0)
	, m_Center(0.0f,0.0f)
	, m_Scale(1.0f,1.0f)
	, m_Color(255,255,255,255)
	, m_iHundle(IHUNDLE_INVALID)
	, m_Angle(0.0f)
	, m_IsTurn(false)
{
}

// �f�X�g���N�^
clImage::~clImage()
{
	Release();
}

// �`���񏉊���
void clImage::InitDrawInfo()
{
	// �`��ʒu
	SetPos(0.0f,0.0f);

	// UV
	int w, h;
	w = h = 0;
	// �摜���ǂݍ��܂�Ă���΁A
	if(m_iHundle != IHUNDLE_INVALID) GetGraphSize(m_iHundle,&w,&h);
	SetUV(0,0,w,h);

	// ���S�_�ʒu
	SetCenter(DIR_CENTER);

	// �X�P�[���l
	SetScale(1.0f);

	// ��]�l
	SetRotate(0.0f);
}

// ����������
void clImage::Init()
{
}

// �摜�ǂݍ���
void clImage::Load( const char* name )
{
	// �ǂݍ���ł���摜���
	Release();

	// �f�B���N�g���p�X�ƍ���
	char str[128];
	ZeroMemory(str,sizeof(str));
	sprintf_s(str,128,"%s%s",IMAGE_DIR_PATH,name);
	// �摜�ǂݍ���
	m_iHundle = LoadGraph(str);

	// �`���񏉊���
	InitDrawInfo();
}

// �`��ʒu�ݒ�
void clImage::SetPos( float x, float y )
{
	// �摜���ǂݍ��܂�Ă��邩�ǂ���
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;

	// �摜�T�C�Y�擾
	int w, h;
	GetGraphSize(m_iHundle,&w,&h);

	m_Pos.x = x + ((float)w*0.5f);
	m_Pos.y = y + ((float)h*0.5f);
}

// UV�ݒ�(�s�N�Z���w��)
void clImage::SetUV( int sx, int sy, int ex, int ey )
{
	// �摜���ǂݍ��܂�Ă��邩�ǂ���
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;

	// �摜�T�C�Y�擾
	int w, h;
	GetGraphSize(m_iHundle,&w,&h);

	// 0 <= �J�nX���W < �I��X���W <= �摜��
	SN_ASSERT(0 <= sx && sx < ex && ex <= w);
	if(!(0 <= sx && sx < ex && ex <= w)) return;
	// 0 <= �J�nY���W < �I��Y���W <= �摜����
	SN_ASSERT(0 <= sy && sy < ey && ey <= h);
	if(!(0 <= sy && sy < ey && ey <= h)) return;

	m_UV.sx = sx;
	m_UV.sy = sy;
	m_UV.ex = ex;
	m_UV.ey = ey;
}

// UV�ݒ�(�����w��)
void clImage::SetUV( float sx, float sy, float ex, float ey )
{
	// �摜���ǂݍ��܂�Ă��邩�ǂ���
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;
	// 0.0f <= �J�nX���W���� < �I��X���W���� <= 1.0f
	SN_ASSERT(0.0f <= sx && sx < ex && ex <= 1.0f);
	if(!(0.0f <= sx && sx < ex && ex <= 1.0f)) return;
	// 0.0f <= �J�nY���W���� < �J�nY���W���� <= 1,0f
	SN_ASSERT(0.0f <= sy && sy < ey && ey <= 1.0f);
	if(!(0.0f <= sy && sy < ey && ey <= 1.0f)) return;

	// �摜�T�C�Y�擾
	int w, h;
	GetGraphSize(m_iHundle,&w,&h);

	// �摜�T�C�Y�̊������擾���A���̒l��UV�ݒ�
	int isx((int)(w*sx));
	int isy((int)(h*sy));
	int iex((int)(w*ex));
	int iey((int)(h*ey));
	SetUV(isx,isy,iex,iey);
}

UVI clImage::GetUV() const
{
	return m_UV;
}

// ���S�_�ݒ�(�^�C�v�w��p)
void clImage::SetCenter( enDirection type )
{
	// �摜���ǂݍ��܂�Ă��邩�ǂ���
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;
	// �摜�T�C�Y�擾
	int iw, ih;
	GetGraphSize(m_iHundle,&iw,&ih);
	// ��ʃT�C�Y�̔����̒l���擾
	float	w,	h,	hw,	hh;
	w = (float)iw;
	h = (float)ih;
	hw = (float)w*0.5f;
	hh = (float)h*0.5f;

	switch(type)
	{
		case DIR_CENTER:		m_Center = VECTOR2F(hw,		hh);	break;	// ����
		case DIR_UP:			m_Center = VECTOR2F(hw,		0.0f);	break;	// ��
		case DIR_UP_RIGHT:		m_Center = VECTOR2F(w,		0.0f);	break;	// �E��
		case DIR_RIGHT:			m_Center = VECTOR2F(w,		hh);	break;	// �E
		case DIR_DOWN_RIGHT:	m_Center = VECTOR2F(w,		h);		break;	// �E��
		case DIR_DOWN:			m_Center = VECTOR2F(hw,		h);		break;	// ��
		case DIR_DOWN_LEFT:		m_Center = VECTOR2F(0.0f,	h);		break;	// ����
		case DIR_LEFT:			m_Center = VECTOR2F(0.0f,	hh);	break;	// ��
		case DIR_UP_LEFT:		m_Center = VECTOR2F(0.0f,	0.0f);	break;	// ����
	}
}

// ���S�_�ݒ�(�ʒu�w��p)
void clImage::SetCenter( int x, int y )
{
	m_Center.x = (float)x;
	m_Center.y = (float)y;
}

// �X�P�[���l�ݒ�(�ʎw��p)
void clImage::SetScale( float x, float y )
{
	m_Scale.x = x;
	m_Scale.y = y;
}

// �X�P�[���l�ݒ�(���ʎw��p)
void clImage::SetScale( float scl )
{
	m_Scale.x = scl;
	m_Scale.y = scl;
}

// �X�P�[���l�擾
VECTOR2F clImage::GetScale() const
{
	return m_Scale;
}

// �J���[�ݒ�(COLOR4I�^�p)
void clImage::SetColor( COLOR4I color )
{
	m_Color = color;
}

// ��]�l�ݒ�(���W�A���w��p)
void clImage::SetRotate( float rot )
{
	m_Angle = rot;
}

// ��]�l�ݒ�(�f�B�O���[�w��p)
void clImage::SetRotate( int rot )
{
	// ���W�A���ɕύX���Đݒ�
	SetRotate(SN_DIGTORAD(rot));
}

// ���E���]���邩�ǂ�����ݒ�
void clImage::SetTurn( bool is_turn )
{
	m_IsTurn = is_turn;
}

// �ǂݍ���ł���摜���
void clImage::Release()
{
	if(m_iHundle != IHUNDLE_INVALID)
	{
		DeleteGraph(m_iHundle);
		m_iHundle = IHUNDLE_INVALID;
	}
}

// �X�V����
void clImage::Update()
{
}

// �`�揈��
void clImage::Draw()
{
	// �摜���ǂݍ��܂�Ă���΁A
	if(m_iHundle != IHUNDLE_INVALID)
	{
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		// �F�ݒ�
		SetDrawBright(m_Color.r,m_Color.g,m_Color.b);
		// �A���t�@�l�ݒ�
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,m_Color.a);

		// �`��
		DrawRectRotaGraph3F
		(
			m_Pos.x,	m_Pos.y,	// �`��ʒu
			m_UV.sx,	m_UV.sy,	m_UV.ex,	m_UV.ey,	// UV
			m_Center.x,	m_Center.y,	// ���S�ʒu
			m_Scale.x,	m_Scale.y,	// �X�P�[���l
			m_Angle,		// ��]�l
			m_iHundle,		// �摜�n���h��
			true,			// ���߂̗L��
			m_IsTurn		// �摜���E���]�̗L��
		);

		// �F������
		SetDrawBright(255,255,255);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}
}
