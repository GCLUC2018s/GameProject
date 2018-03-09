/*!
	@brief	入力判定に使用するテーブル cpp
	@author	s.namizashi
**/

#include "InputTable.hpp"
#include "Source/Include.hpp"

// キー番号テーブル
const int KEY_TABLE[] =
{
	KEY_INPUT_BACK,			// Backspace
	KEY_INPUT_TAB,			// Tab
	KEY_INPUT_RETURN,		// Enter

	KEY_INPUT_LSHIFT,		// 左Shift
	KEY_INPUT_RSHIFT,		// 右Shift
	KEY_INPUT_LCONTROL,		// 左Ctrl
	KEY_INPUT_RCONTROL,		// 右Ctrl
	KEY_INPUT_ESCAPE,		// Esc
	KEY_INPUT_SPACE,		// Space
	KEY_INPUT_PGUP,			// PageUp
	KEY_INPUT_PGDN,			// PageDown
	KEY_INPUT_END,			// End
	KEY_INPUT_HOME,			// Home
	KEY_INPUT_LEFT,			// 左
	KEY_INPUT_UP,			// 上
	KEY_INPUT_RIGHT,		// 右
	KEY_INPUT_DOWN,			// 下
	KEY_INPUT_INSERT,		// Insert
	KEY_INPUT_DELETE,		// Delete

	KEY_INPUT_MINUS,		// -
	KEY_INPUT_YEN,			// \ 
	KEY_INPUT_PREVTRACK,	// ^
	KEY_INPUT_PERIOD,		// .
	KEY_INPUT_SLASH,		// /
	KEY_INPUT_LALT,			// 左Alt
	KEY_INPUT_RALT,			// 右Alt
	KEY_INPUT_SCROLL,		// ScrollLock
	KEY_INPUT_SEMICOLON,	// ;
	KEY_INPUT_COLON,		// :
	KEY_INPUT_LBRACKET,		// [
	KEY_INPUT_RBRACKET,		// ]
	KEY_INPUT_AT,			// @
	KEY_INPUT_BACKSLASH,	// \(バックスラッシュ)
	KEY_INPUT_COMMA,		// ,
	KEY_INPUT_KANJI,		// 漢字
	KEY_INPUT_CONVERT,		// 変換
	KEY_INPUT_NOCONVERT,	// 無変換
	KEY_INPUT_KANA,			// カナ
	KEY_INPUT_APPS,			// アプリケーションメニュー
	KEY_INPUT_CAPSLOCK,		// CapsLock
	KEY_INPUT_SYSRQ,		// PrintScreen
	KEY_INPUT_PAUSE,		// Pause
	KEY_INPUT_LWIN,			// 左Windows
	KEY_INPUT_RWIN,			// 右Windows

	KEY_INPUT_NUMLOCK,		// NumLock
	KEY_INPUT_NUMPAD0,		// テンキー 0
	KEY_INPUT_NUMPAD1,		// テンキー 1
	KEY_INPUT_NUMPAD2,		// テンキー 2
	KEY_INPUT_NUMPAD3,		// テンキー 3
	KEY_INPUT_NUMPAD4,		// テンキー 4
	KEY_INPUT_NUMPAD5,		// テンキー 5
	KEY_INPUT_NUMPAD6,		// テンキー 6
	KEY_INPUT_NUMPAD7,		// テンキー 7
	KEY_INPUT_NUMPAD8,		// テンキー 8
	KEY_INPUT_NUMPAD9,		// テンキー 9
	KEY_INPUT_MULTIPLY,		// テンキー *
	KEY_INPUT_ADD,			// テンキー +
	KEY_INPUT_SUBTRACT,		// テンキー -
	KEY_INPUT_DECIMAL,		// テンキー .
	KEY_INPUT_DIVIDE,		// テンキー /
	KEY_INPUT_NUMPADENTER,	// テンキー Enter

	KEY_INPUT_F1,			// F1
	KEY_INPUT_F2,			// F2
	KEY_INPUT_F3,			// F3
	KEY_INPUT_F4,			// F4
	KEY_INPUT_F5,			// F5
	KEY_INPUT_F6,			// F6
	KEY_INPUT_F7,			// F7
	KEY_INPUT_F8,			// F8
	KEY_INPUT_F9,			// F9
	KEY_INPUT_F10,			// F10
	KEY_INPUT_F11,			// F11
	KEY_INPUT_F12,			// F12

	KEY_INPUT_A,			// A
	KEY_INPUT_B,			// B
	KEY_INPUT_C,			// C
	KEY_INPUT_D,			// D
	KEY_INPUT_E,			// E
	KEY_INPUT_F,			// F
	KEY_INPUT_G,			// G
	KEY_INPUT_H,			// H
	KEY_INPUT_I,			// I
	KEY_INPUT_J,			// J
	KEY_INPUT_K,			// K
	KEY_INPUT_L,			// L
	KEY_INPUT_M,			// M
	KEY_INPUT_N,			// N
	KEY_INPUT_O,			// O
	KEY_INPUT_P,			// P
	KEY_INPUT_Q,			// Q
	KEY_INPUT_R,			// R
	KEY_INPUT_S,			// S
	KEY_INPUT_T,			// T
	KEY_INPUT_U,			// U
	KEY_INPUT_V,			// V
	KEY_INPUT_W,			// W
	KEY_INPUT_X,			// X
	KEY_INPUT_Y,			// Y
	KEY_INPUT_Z,			// Z

	KEY_INPUT_0,			// 0
	KEY_INPUT_1,			// 1
	KEY_INPUT_2,			// 2
	KEY_INPUT_3,			// 3
	KEY_INPUT_4,			// 4
	KEY_INPUT_5,			// 5
	KEY_INPUT_6,			// 6
	KEY_INPUT_7,			// 7
	KEY_INPUT_8,			// 8
	KEY_INPUT_9,			// 9
};
SN_STATIC_ASSERT(SN_ELEMENTSOF(KEY_TABLE) == IK_COUNT);
