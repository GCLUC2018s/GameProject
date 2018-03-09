/*!
	@brief	ゲーム内で使用する定数や列挙型
**/

#ifndef __GAME_DEF_HPP__
#define __GAME_DEF_HPP__

#define	APP_NAME			"Sample Game"
#define	FRAME_RATE			60		// フレームレート
#define WINDOW_WIDTH		800		// ウィンドウ幅
#define WINDOW_HEIGHT		600		// ウィンドウ高さ

// 3次元ベクトルデータ型
struct VECTOR3F
{
	float	x, y, z;
	VECTOR3F() { x = y = z = 0.0f; }
	VECTOR3F( float ix, float iy, float iz ) { x = ix; y = iy; z = iz; }
};
// 2次元ベクトルデータ型(float型)
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
// 2次元ベクトルデータ型(int型)
struct VECTOR2I
{
	int		x,	y;
	VECTOR2I() { x = y = 0; }
	VECTOR2I( int ix, int iy ) { x = ix; y = iy; }
};

// UV情報データ型(int型)
struct UVI
{
	int		sx,	sy,	ex,	ey;
	UVI() { sx = sy = ex = ey = 0; }
	UVI( int isx, int isy, int iex, int iey ) { sx = isx; sy = isy; ex = iex; ey = iey; }
};
// UV情報データ型(float型)
struct UVF
{
	float	sx,	sy,	ex,	ey;
	UVF() { sx = sy = ex = ey = 0.0f; }
	UVF( float isx, float isy, float iex, float iey ) { sx = isx; sy = isy; ex = iex; ey = iey; }
};

// カラー情報データ型(float型)
struct COLOR4F
{
	float	r,	g,	b,	a;
	COLOR4F() { r = g = b = a = 1.0f; }
	COLOR4F( float ir, float ig, float ib, float ia ) { r = ir; g = ig; b = ib; a = ia; }
};
// カラー情報データ型(int型)
struct COLOR4I
{
	int	r,	g,	b,	a;
	COLOR4I() { r = g = b = a = 255; }
	COLOR4I( int ir, int ig, int ib, int ia ) { r = ir; g = ig; b = ib; a = ia; }
};

// シーンタイプ
enum enSceneType
{
	STYPE_NONE = -1,

	STYPE_GAME,		// ゲーム

	STYPE_COUNT
};

// 方向
enum enDirection
{
	DIR_NONE = -1,

	DIR_CENTER,		// 中央
	DIR_UP,			// 上
	DIR_UP_RIGHT,	// 右上
	DIR_RIGHT,		// 右
	DIR_DOWN_RIGHT,	// 右下
	DIR_DOWN,		// 下
	DIR_DOWN_LEFT,	// 左下
	DIR_LEFT,		// 左
	DIR_UP_LEFT,	// 左上

	DIR_COUNT,
};

// 画像描画情報構造体
struct stImageInfo
{
	VECTOR2F	pos;		// 描画位置
	UVI			uv;			// UV値
	enDirection	ctr_type;	// 中心点タイプ
	VECTOR2F	center;		// 中心点位置
	VECTOR2F	scale;		// スケール値
	COLOR4I		color;		// カラー
	float		angle;		// 回転値
	bool		is_turn;	// 左右反転するかどうか
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

// キータイプ
enum enKeyType
{
	IK_NONE = -1,

	IK_BACK,		// Backspace
	IK_TAB,			// Tab
	IK_RETURN,		// Enter

	IK_LSHIFT,		// 左Shift
	IK_RSHIFT,		// 右Shift
	IK_LCONTROL,	// 左Ctrl
	IK_RCONTROL,	// 右Ctrl
	IK_ESCAPE,		// Esc
	IK_SPACE,		// Space
	IK_PGUP,		// PageUp
	IK_PGDN,		// PageDown
	IK_END,			// End
	IK_HOME,		// Home
	IK_LEFT,		// 左
	IK_UP,			// 上
	IK_RIGHT,		// 右
	IK_DOWN,		// 下
	IK_INSERT,		// Insert
	IK_DELETE,		// Delete

	IK_MINUS,		// -
	IK_YEN,			// \ 
	IK_PREVTRACK,	// ^
	IK_PERIOD,		// .
	IK_SLASH,		// /
	IK_LALT,		// 左Alt
	IK_RALT,		// 右Alt
	IK_SCROLL,		// ScrollLock
	IK_SEMICOLON,	// ;
	IK_COLON,		// :
	IK_LBRACKET,	// [
	IK_RBRACKET,	// ]
	IK_AT,			// @
	IK_BACKSLASH,	// \(バックスラッシュ)
	IK_COMMA,		// ,
	IK_KANJI,		// 漢字
	IK_CONVERT,		// 変換
	IK_NOCONVERT,	// 無変換
	IK_KANA,		// カナ
	IK_APPS,		// アプリケーションメニュー
	IK_CAPSLOCK,	// CapsLock
	IK_SYSRQ,		// PrintScreen
	IK_PAUSE,		// Pause
	IK_LWIN,		// 左Windows
	IK_RWIN,		// 右Windows

	IK_NUMLOCK,		// NumLock
	IK_NUMPAD0,		// テンキー 0
	IK_NUMPAD1,		// テンキー 1
	IK_NUMPAD2,		// テンキー 2
	IK_NUMPAD3,		// テンキー 3
	IK_NUMPAD4,		// テンキー 4
	IK_NUMPAD5,		// テンキー 5
	IK_NUMPAD6,		// テンキー 6
	IK_NUMPAD7,		// テンキー 7
	IK_NUMPAD8,		// テンキー 8
	IK_NUMPAD9,		// テンキー 9
	IK_MULTIPLY,	// テンキー *
	IK_ADD,			// テンキー +
	IK_SUBTRACT,	// テンキー -
	IK_DECIMAL,		// テンキー .
	IK_DIVIDE,		// テンキー /
	IK_NUMPADENTER,	// テンキー Enter

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
