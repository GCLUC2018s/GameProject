#ifndef PANCH_EFFECT_GUARD
#define PANCH_EFFECT_GUARD

#include "../CObjectBase.h"

/*

êßçÏÅ@ã{˙±

*/

class CPlayer;

class CPanchEF :public CObjectBase {
public:
	CPanchEF(bool frip,CPlayer *pl,int anim_num);
	void Update();
	void Draw();
	//1à»è„Ç»ÇÁîªíËÇ≈Ç´ÇÈ
	float GetHit() {
		return m_color.w;
	};
	bool GetFrip() {
		return !m_flipH;
	};
private:
	CPlayer *PL;
};

#endif // !PANCH_EFFECT_GUARD
