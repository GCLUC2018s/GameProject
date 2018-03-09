/*!
	@brief	�Q�[�����Ŏg�p����萔��񋓌^
**/

#ifndef __GAME_DEF_HPP__
#define __GAME_DEF_HPP__

#define	APP_NAME			"Sample Game"
#define	FRAME_RATE			60		// �t���[�����[�g
#define WINDOW_WIDTH		800		// �E�B���h�E��
#define WINDOW_HEIGHT		600		// �E�B���h�E����

// 3�����x�N�g���f�[�^�^
struct VECTOR3F
{
	float	x, y, z;
	VECTOR3F() { x = y = z = 0.0f; }
	VECTOR3F( float ix, float iy, float iz ) { x = ix; y = iy; z = iz; }
};
// 2�����x�N�g���f�[�^�^(float�^)
struct VECTOR2F
{
	float	x,	y;
	VECTOR2F() { x = y = 0.0f; }
	VECTOR2F( float ix, float iy ) { x = ix; y = iy; }
	void normalize()
	{
		float length = std::sqrt(x * x + y * y);
		x /= length;
		y /= length;
	}

};
// 2�����x�N�g���f�[�^�^(int�^)
struct VECTOR2I
{
	int		x,	y;
	VECTOR2I() { x = y = 0; }
	VECTOR2I( int ix, int iy ) { x = ix; y = iy; }
};

// UV���f�[�^�^(int�^)
struct UVI
{
	int		sx,	sy,	ex,	ey;
	UVI() { sx = sy = ex = ey = 0; }
	UVI( int isx, int isy, int iex, int iey ) { sx = isx; sy = isy; ex = iex; ey = iey; }
};
// UV���f�[�^�^(float�^)
struct UVF
{
	float	sx,	sy,	ex,	ey;
	UVF() { sx = sy = ex = ey = 0.0f; }
	UVF( float isx, float isy, float iex, float iey ) { sx = isx; sy = isy; ex = iex; ey = iey; }
};

// �J���[���f�[�^�^(float�^)
struct COLOR4F
{
	float	r,	g,	b,	a;
	COLOR4F() { r = g = b = a = 1.0f; }
	COLOR4F( float ir, float ig, float ib, float ia ) { r = ir; g = ig; b = ib; a = ia; }
};
// �J���[���f�[�^�^(int�^)
struct COLOR4I
{
	int	r,	g,	b,	a;
	COLOR4I() { r = g = b = a = 255; }
	COLOR4I( int ir, int ig, int ib, int ia ) { r = ir; g = ig; b = ib; a = ia; }
};

// �V�[���^�C�v
enum enSceneType
{
	STYPE_NONE = -1,

	STYPE_GAME,		// �Q�[��

	STYPE_COUNT
};

// ����
enum enDirection
{
	DIR_NONE = -1,

	DIR_CENTER,		// ����
	DIR_UP,			// ��
	DIR_UP_RIGHT,	// �E��
	DIR_RIGHT,		// �E
	DIR_DOWN_RIGHT,	// �E��
	DIR_DOWN,		// ��
	DIR_DOWN_LEFT,	// ����
	DIR_LEFT,		// ��
	DIR_UP_LEFT,	// ����

	DIR_COUNT,
};

// �摜�`����\����
struct stImageInfo
{
	VECTOR2F	pos;		// �`��ʒu
	UVI			uv;			// UV�l
	enDirection	ctr_type;	// ���S�_�^�C�v
	VECTOR2F	center;		// ���S�_�ʒu
	VECTOR2F	scale;		// �X�P�[���l
	COLOR4I		color;		// �J���[
	float		angle;		// ��]�l
	bool		is_turn;	// ���E���]���邩�ǂ���
	stImageInfo()
	{
		pos = VECTOR2F(0.0f,0.0f);
		uv = UVI(0,0,0,0);
		ctr_type = DIR_NONE;
		center = VECTOR2F(0,0);
		scale = VECTOR2F(1.0f,1.0f);
		color = COLOR4I(255,255,255,255);
		angle = 0.0f;
		is_turn = false;
	}
};

// �L�[�^�C�v
enum enKeyType
{
	IK_NONE = -1,

	IK_BACK,		// Backspace
	IK_TAB,			// Tab
	IK_RETURN,		// Enter

	IK_LSHIFT,		// ��Shift
	IK_RSHIFT,		// �EShift
	IK_LCONTROL,	// ��Ctrl
	IK_RCONTROL,	// �ECtrl
	IK_ESCAPE,		// Esc
	IK_SPACE,		// Space
	IK_PGUP,		// PageUp
	IK_PGDN,		// PageDown
	IK_END,			// End
	IK_HOME,		// Home
	IK_LEFT,		// ��
	IK_UP,			// ��
	IK_RIGHT,		// �E
	IK_DOWN,		// ��
	IK_INSERT,		// Insert
	IK_DELETE,		// Delete

	IK_MINUS,		// -
	IK_YEN,			// \ 
	IK_PREVTRACK,	// ^
	IK_PERIOD,		// .
	IK_SLASH,		// /
	IK_LALT,		// ��Alt
	IK_RALT,		// �EAlt
	IK_SCROLL,		// ScrollLock
	IK_SEMICOLON,	// ;
	IK_COLON,		// :
	IK_LBRACKET,	// [
	IK_RBRACKET,	// ]
	IK_AT,			// @
	IK_BACKSLASH,	// \(�o�b�N�X���b�V��)
	IK_COMMA,		// ,
	IK_KANJI,		// ����
	IK_CONVERT,		// �ϊ�
	IK_NOCONVERT,	// ���ϊ�
	IK_KANA,		// �J�i
	IK_APPS,		// �A�v���P�[�V�������j���[
	IK_CAPSLOCK,	// CapsLock
	IK_SYSRQ,		// PrintScreen
	IK_PAUSE,		// Pause
	IK_LWIN,		// ��Windows
	IK_RWIN,		// �EWindows

	IK_NUMLOCK,		// NumLock
	IK_NUMPAD0,		// �e���L�[ 0
	IK_NUMPAD1,		// �e���L�[ 1
	IK_NUMPAD2,		// �e���L�[ 2
	IK_NUMPAD3,		// �e���L�[ 3
	IK_NUMPAD4,		// �e���L�[ 4
	IK_NUMPAD5,		// �e���L�[ 5
	IK_NUMPAD6,		// �e���L�[ 6
	IK_NUMPAD7,		// �e���L�[ 7
	IK_NUMPAD8,		// �e���L�[ 8
	IK_NUMPAD9,		// �e���L�[ 9
	IK_MULTIPLY,	// �e���L�[ *
	IK_ADD,			// �e���L�[ +
	IK_SUBTRACT,	// �e���L�[ -
	IK_DECIMAL,		// �e���L�[ .
	IK_DIVIDE,		// �e���L�[ /
	IK_NUMPADENTER,	// �e���L�[ Enter

	IK_F1,			// F1
	IK_F2,			// F2
	IK_F3,			// F3
	IK_F4,			// F4
	IK_F5,			// F5
	IK_F6,			// F6
	IK_F7,			// F7
	IK_F8,			// F8
	IK_F9,			// F9
	IK_F10,			// F10
	IK_F11,			// F11
	IK_F12,			// F12

	IK_A,			// A
	IK_B,			// B
	IK_C,			// C
	IK_D,			// D
	IK_E,			// E
	IK_F,			// F
	IK_G,			// G
	IK_H,			// H
	IK_I,			// I
	IK_J,			// J
	IK_K,			// K
	IK_L,			// L
	IK_M,			// M
	IK_N,			// N
	IK_O,			// O
	IK_P,			// P
	IK_Q,			// Q
	IK_R,			// R
	IK_S,			// S
	IK_T,			// T
	IK_U,			// U
	IK_V,			// V
	IK_W,			// W
	IK_X,			// X
	IK_Y,			// Y
	IK_Z,			// Z

	IK_0,			// 0
	IK_1,			// 1
	IK_2,			// 2
	IK_3,			// 3
	IK_4,			// 4
	IK_5,			// 5
	IK_6,			// 6
	IK_7,			// 7
	IK_8,			// 8
	IK_9,			// 9

	IK_COUNT
};

#define IK_DEFINE_KEY_DECIDE (IK_RETURN)

#endif	// #ifndef __GAME_DEF_HPP__
