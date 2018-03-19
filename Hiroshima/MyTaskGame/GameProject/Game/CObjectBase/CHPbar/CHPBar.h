#ifndef HP_BAR_GUARD
#define HP_BAR_GUARD

#include "../CObjectBase.h"

class CPlayer;
class CBoss;
/*

����@�{��

*/

class CHPBar : public CObjectBase
{
public:
	//true�Ȃ�A�{�X�pHP�o�[
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
	bool m_boss_flag;			//true�Ȃ�A�{�X�pHP�o�[
	void PL_Hp_Update();		//PL��Update
	void Boss_Hp_Update();		//Boss��Update
	void PL_Hp_Draw();			//PL��Draw
	void Boss_Hp_Draw();		//Boss��Draw
};
#endif // !HP_BAR_GUARD
