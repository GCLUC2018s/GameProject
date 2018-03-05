#include "CScore.h"
#include "../Global.h"

CScore::CScore() : CBase(eTagUI) {
	m_img = g_image[eImageNumber];
}
CScore::~CScore() {

}
void CScore::Draw() {
	int score = g_game_data.score;
	int i = 0;
	while (score >= 1) {
	int x = score % 10;
	int y = 0;
		m_img.Draw();
		m_img.SetPos(200 - i * 48, 0);
		m_img.SetSize(48, 48);
		m_img.SetRect(x * 48, y * 48, x * 48 + 48, y * 48 + 48);
		score /= 10;
		i++;
	}
}