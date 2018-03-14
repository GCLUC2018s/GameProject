#ifndef MAIN_TEXT_GUARD
#define MAIN_TEXT_GUARD

#define MAIN_TEXT_X 1171
#define MAIN_TEXT_Y 151

#define MAIN_TEXT_TIME 85
#define MAIN_TEXT_UP 0.05

#include "../CObjectBase.h"

/*

制作者　宮﨑

*/
class CMainText : public CObjectBase
{
public:
	//「敵を倒せ！」
	CMainText();
	~CMainText();
	void Update();
private:
	bool	m_end_flag;	//終わりますよフラグ
};
#endif // !MAIN_TEXT_GUARD
