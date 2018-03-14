#ifndef GAME_START_GUARD
#define GAME_START_GUARD

#define GAME_START_X 711
#define GAME_START_Y 76

#define GAME_START_TIME 120

#include "../CObjectBase.h"

/*

制作者　宮﨑

*/
class CGameStart : public CObjectBase
{
public:
	//プレゼンツ
	CGameStart();
	~CGameStart();
	void Update();
private:
	float	m_siz;	//サイズ用
	float	m_up_siz;	//増やす量
	bool	m_end_flag;	//終わりますよフラグ
	int		m_cnt;	//フェードアウト開始。
};
#endif // !GAME_START_GUARD
