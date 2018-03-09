/*!
	@brief	グローバルで使用するもの等 hpp
	@author	s.namizashi
**/

#ifndef __GAME_BOARD_HPP__
#define __GAME_BOARD_HPP__

class clFont;
class clInput;

namespace nsGameBoard
{
	extern	clFont*			g_debug_font;		// デバッグ文字列描画用
	extern	clInput*		g_input;			// 入力判定用
}

#endif	// #ifndef __GAME_BOARD_HPP__