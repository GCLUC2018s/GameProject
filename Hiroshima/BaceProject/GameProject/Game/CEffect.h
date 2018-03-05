#pragma once
#include "CBase.h"

class CEffectBomb : public CBase {
public:
	CEffectBomb(CVector2D pos);
	~CEffectBomb();
	void Update();
};

class CEffectSlash : public CBase {
public:
	CEffectSlash(CVector2D pos, bool flipH);
	~CEffectSlash();
	void Update();
	void HitCallback(CBase* b);
};

class CEffectBlood : public CBase {
public:
	CEffectBlood(CVector2D pos);
	~CEffectBlood();
	void Update();
};

class CEffectShotHit : public CBase {
public:
	CEffectShotHit(CVector2D pos);
	~CEffectShotHit();
	void Update();
};

class CEffectSmoke : public CBase {
public:
	CEffectSmoke(CVector2D pos);
	~CEffectSmoke();
	void Update();
};