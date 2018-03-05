#include "CClear.h"
#include "../Global.h"

CClear::CClear():CBase(eTagUI) {
	m_img = g_image[eImageClear];

}
CClear::~CClear() {

}
void CClear::Update() {

}
void CClear::Draw() {
//	if(m_fa = false)
	m_img.Draw();
	m_img.SetPos(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3);
	m_img.SetRect(0, 0, 430, 64);
	m_img.SetSize(430, 64);
}