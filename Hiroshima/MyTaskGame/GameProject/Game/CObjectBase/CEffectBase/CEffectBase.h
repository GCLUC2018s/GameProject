#ifndef EFFECT_GUARD
#define EFFECT_GUARD

#include "../CObjectBase.h"

/*

����@�{��

*/

class CEffectBase :public CObjectBase {
public:
	CEffectBase();
	virtual void Update();
	virtual void Draw();
	//1�ȏ�Ȃ画��ł���
	float GetHit() {
		return m_color.w;
	};
	bool GetFrip() {
		return !m_flipH;
	};
};

#endif // !EFFECT_GUARD
