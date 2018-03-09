/*!
	@brief	������`��N���X cpp
	@author	s.namizashi
**/

#include "Source/Include.hpp"
#include "Font.hpp"

namespace
{
	// �萔
	const int	FHUNDLE_INVALID	= -1;	// �����t�H���g�n���h��
	const int	FSIZE_DEFAULT	= -1;	// �t�H���g�T�C�Y�̃f�t�H���g�l
	const int	FTHICK_DEFAULT	= -1;	// �t�H���g�̑����̃f�t�H���g�l
	const int	FTHICK_MIN		= 0;	// �t�H���g�̑����̍ŏ��l
	const int	FTHICK_MAX		= 9;	// �t�H���g�̑����̍ő�l
	const DWORD	FCOLOR_DEFAULT	= 0xffffffff;		// �t�H���g�J���[�̃f�t�H���g�l(���F)
	const char*	FNAME_DEFALUT	= "�l�r �S�V�b�N";	// �g�p�f�t�H���g�t�H���g��

	// �t�H���g�^�C�v�e�[�u��
	const int FONT_TYPE_TABLE[] =
	{
		DX_FONTTYPE_NORMAL,		// �f�t�H���g
		DX_FONTTYPE_NORMAL,
		DX_FONTTYPE_EDGE,
		DX_FONTTYPE_ANTIALIASING,
		DX_FONTTYPE_ANTIALIASING_4X4,
		DX_FONTTYPE_ANTIALIASING_8X8,
		DX_FONTTYPE_ANTIALIASING_EDGE,
		DX_FONTTYPE_ANTIALIASING_EDGE_4X4,
		DX_FONTTYPE_ANTIALIASING_EDGE_8X8
	};
}

// �R���X�g���N�^
clFont::clFont()
	: m_fName(FNAME_DEFALUT)
	, m_fHundle(FHUNDLE_INVALID)
	, m_fSize(FSIZE_DEFAULT)
	, m_fThick(FTHICK_DEFAULT)
	, m_fType(FONT_TYPE_TABLE[FTYPE_DEFAULT])
	, m_fColor(FCOLOR_DEFAULT)
	, m_IsShadow(false)
	, m_IsChange(false)
	, m_IsCenter(false)
{
}

// �f�X�g���N�^
clFont::~clFont()
{
}

// �ǂݍ���ł���t�H���g���
void clFont::Release()
{
	// ���Ƀt�H���g���ǂݍ��܂�Ă���΁A
	if(m_fHundle != FHUNDLE_INVALID)
	{
		// �t�H���g�f�[�^�폜
		DeleteFontToHandle(m_fHundle);
		m_fHundle = FHUNDLE_INVALID;
	}
}

// �t�H���g�쐬
void clFont::Create()
{
	// ���݂̃t�H���g�폜
	Release();
	// �V�����t�H���g�쐬
	m_fHundle = CreateFontToHandle(m_fName.c_str(),m_fSize,m_fThick,m_fType);
}

// ����������
void clFont::Init()
{
	// �t�H���g���쐬
	Create();
}

// �t�H���g���ݒ�
void clFont::SetName( const char* fName )
{
	SN_ASSERT(fName);
	if(!fName) return;

	m_fName.clear();
	m_fName.append(fName);
	m_IsChange = true;
}

// �t�H���g�T�C�Y�ݒ�
void clFont::SetSize( int size )
{
	SN_ASSERT((size == FSIZE_DEFAULT) || (size > 0));
	if(!((size == FSIZE_DEFAULT) || (size > 0))) return;

	m_fSize = size;
	m_IsChange = true;
}

// �t�H���g�̑����ݒ�
void clFont::SetThick( int thick )
{
	SN_ASSERT(FTHICK_DEFAULT <= thick && thick <= FTHICK_MAX);
	if(!(FTHICK_DEFAULT <= thick && thick <= FTHICK_MAX)) return;

	m_fThick = thick;
	m_IsChange = true;
}

// �t�H���g�^�C�v�ݒ�
void clFont::SetType( enFontType type )
{
	SN_ASSERT(FTYPE_NONE < type && type < FTYPE_COUNT);
	if(!(FTYPE_NONE < type && type < FTYPE_COUNT)) return;

	m_fType = FONT_TYPE_TABLE[type];
	m_IsChange = true;
}

// �t�H���g�J���[�ݒ�
void clFont::SetColor( DWORD color )
{
	m_fColor = color;
}

// �e�̗L���ݒ�
void clFont::SetShadow( bool flag )
{
	m_IsShadow = flag;
}

// �`�敶����ݒ�
void clFont::Print( VECTOR2I pos, const char* format, ... )
{
	// �������X�g�쐬
	va_list arg;
	// ���X�g������
	va_start(arg, format);

	// �`����
	stDrawInfo info;
	info.pos = pos;
	info.color = m_fColor;

	// �����񏑂�����
	vsprintf_s(info.str,format,arg);

	m_DrawList.push_back(info);

	va_end(arg);
}

// �f�o�b�O������`��p
void clFont::DebugPrint( VECTOR2I pos, const char* format, ... )
{
	// �f�o�b�O�t�H���g�`��N���X���ǂݍ��܂�ĂȂ���΁A���^�[��
	if(!nsGameBoard::g_debug_font) return;

	// �������X�g�쐬
	va_list arg;
	// ���X�g������
	va_start(arg, format);

	// �����񏑂�����
	char tStr[FONT_BUFFER_SIZE];
	ZeroMemory(tStr,sizeof(tStr));
	vsprintf_s(tStr,format,arg);

	// �f�o�b�O�t�H���g�`��N���X�ɏ�������
	nsGameBoard::g_debug_font->Print(pos,tStr);

	va_end(arg);
}

// �X�V����
void clFont::Update()
{
	// �t�H���g�؂�ւ�
	if(m_IsChange)
	{
		// �V�����t�H���g�쐬
		Create();
		m_IsChange = false;
	}
}

// �`�揈��
void clFont::Draw()
{
	// �t�H���g�ǂݍ��ݍς�
	if(m_fHundle != FHUNDLE_INVALID)
	{
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		// ���X�g���̕`��������ɑS�ĕ`��
		DRAWLIST::iterator it = m_DrawList.begin();
		while(it != m_DrawList.end())
		{
			// �`��
			const stDrawInfo* info(&(*it));
			VECTOR2I pos(info->pos);
			if(m_IsCenter)
			{
				int width(GetDrawStringWidth(info->str,strlen(info->str)-1));
				pos.x -= width/2;
			}
			// �e���L���Ȃ�΁A
			if(m_IsShadow)
			{
				// �e�`��(�J���[���])
				DrawStringToHandle(pos.x+1,pos.y+1,info->str,info->color^0x00ffffff,m_fHundle);
			}
			// �{��
			DrawStringToHandle(pos.x,pos.y,info->str,info->color,m_fHundle);
			++it;
		}
		// �`�悪�I���΁A�`���񃊃X�g���
		m_DrawList.clear();
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}
