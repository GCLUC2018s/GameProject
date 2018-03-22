#ifndef EFFECT_GUARD
#define EFFECT_GUARD

#include "../CObjectBase.h"

/*

����@�{��

*/

enum {
	eFire,
	ePanch,
	eBress,
};

class CEffectBase :public CObjectBase {
public:
	CEffectBase();
	virtual void Update();
	virtual void Draw();
	//1�ȏ�Ȃ画��ł���
	float GetHit() {
		return m_color.w;
	};
	int GetEFtype() {
		return m_effect_type;
	};
protected:
	int m_effect_type;	//�G�t�F�N�g�̎��
};

#endif // !EFFECT_GUARD
