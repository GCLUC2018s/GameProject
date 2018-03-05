#include "CEffect.h"

//”š”­
CEffectBomb::CEffectBomb(CVector2D pos) : CBase(eTagBomb) {
	m_img = CAnimImage(g_image[eImageEffectBomb], Effect_Bomb_AnimData, 96, 96);
	m_img.SetSize(96, 96);
	m_pos = pos;
	m_rect = CRect(0, 0, 96, 96);
}
CEffectBomb::~CEffectBomb() {

}
 void CEffectBomb::Update() {
	 m_img.ChangeAnimation(0, false);
	 m_img.UpdateAnimation();
	 if (m_img.CheckAnimationEnd()) {
		 m_active = false;
	 }
}

 //ŽaŒ‚
 CEffectSlash::CEffectSlash(CVector2D pos, bool flipH) : CBase(eTagSlash) {
	 m_flipH = flipH;
	 m_img = CAnimImage(g_image[eImageEffectSlash], Effect_Slash_AnimData, 128, 128);
	 m_img.SetSize(128, 128);
	 m_pos = pos;
	 m_rect = CRect(0, 0, 128, 128);
	 m_mask = MASK_ENEMY;
}
 CEffectSlash::~CEffectSlash() {

}
 void CEffectSlash::Update() {
	 m_img.ChangeAnimation(0, false);
	 m_img.UpdateAnimation();
	 if (m_img.CheckAnimationEnd()) {
		 m_active = false;
	 }
 }
 void CEffectSlash::HitCallback(CBase* b) {

 }

 CEffectBlood::CEffectBlood(CVector2D pos) : CBase(eTagBlood) {
	 m_img = CAnimImage(g_image[eImageEffectBlood], Effect_Blood_AnimData, 96, 96);
	 m_img.SetSize(96, 96);
	 m_pos = pos;
	 m_rect = CRect(0, 0, 96, 96);
 }
 CEffectBlood::~CEffectBlood() {

 }
 void CEffectBlood::Update() {
	 m_img.ChangeAnimation(0, false);
	 m_img.UpdateAnimation();
	 if (m_img.CheckAnimationEnd()) {
		 m_active = false;
	 }
 }

 CEffectShotHit::CEffectShotHit(CVector2D pos) : CBase(eTagShotHit) {
	 m_img = CAnimImage(g_image[eImageEffectShotHit], Effect_ShotHit_AnimData, 32, 32);
	 m_img.SetSize(32, 32);
	 m_pos = pos;
	 m_rect = CRect(0, 0, 32, 32);
 }
 CEffectShotHit::~CEffectShotHit() {

 }
 void CEffectShotHit::Update() {
	 m_img.ChangeAnimation(0, false);
	 m_img.UpdateAnimation();
	 if (m_img.CheckAnimationEnd()) {
		 m_active = false;
	 }
 }

 CEffectSmoke::CEffectSmoke(CVector2D pos) : CBase(eTagSmoke) {
	 m_img = CAnimImage(g_image[eImageEffectSmoke], Effect_Smoke_AnimData, 128, 128);
	 m_img.SetSize(128, 128);
	 m_pos = pos;
	 m_rect = CRect(0, 0, 128, 128);
 }
 CEffectSmoke::~CEffectSmoke() {

 }
 void CEffectSmoke::Update() {
	 m_img.ChangeAnimation(0, false);
	 m_img.UpdateAnimation();
	 if (m_img.CheckAnimationEnd()) {
		 m_active = false;
	 }
 }