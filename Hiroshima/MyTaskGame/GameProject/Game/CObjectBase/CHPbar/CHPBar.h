#ifndef HP_BAR_GUARD
#define HP_BAR_GUARD

#include "../CObjectBase.h"

class CPlayer;
class CBoss;
/*

制作　宮﨑

*/

class CHPBar : public CObjectBase
{
public:
	//trueなら、ボス用HPバー
	CHPBar(const bool &boss_flag);
	void Update();
	void Draw();
private:
	CAnimImage m_img_Bossbase;
	CAnimImage m_img_Bossbar;
	CAnimImage m_img_PLbase;
	CAnimImage m_img_PLbar;
	CPlayer *pl;
	CBoss *boss;
	bool m_boss_flag;			//trueなら、ボス用HPバー
	void PL_Hp_Update();		//PLのUpdate
	void Boss_Hp_Update();		//BossのUpdate
	void PL_Hp_Draw();			//PLのDraw
	void Boss_Hp_Draw();		//BossのDraw
};
#endif // !HP_BAR_GUARD
