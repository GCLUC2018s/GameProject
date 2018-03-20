#ifndef EFFECT_GUARD
#define EFFECT_GUARD

#include "../CObjectBase.h"

/*

§ì@‹{ú±

*/

class CEffectBase :public CObjectBase {
public:
	CEffectBase();
	virtual void Update();
	virtual void Draw();
	//1ˆÈã‚È‚ç”»’è‚Å‚«‚é
	float GetHit() {
		return m_color.w;
	};
	bool GetFrip() {
		return !m_flipH;
	};
};

#endif // !EFFECT_GUARD
