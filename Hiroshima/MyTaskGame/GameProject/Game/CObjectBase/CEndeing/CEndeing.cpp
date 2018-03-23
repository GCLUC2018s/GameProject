#include "CEndeing.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

static std::string end[] = {
	"　　　　　かつて　「ひと」の村と「あやかし」の村があった　　　　",
	"　　　　 　　 　　干渉しあうことはなかったが　　　　　　　　　　　\n　　 　 　　　　　　馬の合わない村たちだった 　　　　　　　　　　",
	"　　　 　　 　　　ふたつの村の仲を取り持つのは 　　　　　　　　　　\n　　　 　　　　　　「けもの」の村であった　　　　　　　　　　　　",
	"　　　しかし　「あやかし」たちが「ひと」を襲うようになった　　　",
	"　　　　　「けもの」は「ひと」の村と「あやかし」の村を　　　　　 \n　　　　　　　　　　かつての状態に戻すため　　　　　　　　　　　　",
	"　　　　「けもの」の村の長は　村の巫女である「葉月」に　　　　　",
	"　　　 　『「あやかし」の長にお灸をすえなさい』と命じ 　　　　　",
	"　　　葉月は　「あやかし」の長に会いに行ったのであった・・・　",
	"　　　　　　　　　 「あやかし」の村の長は　　　　 　　　　　　　",
	"　 『まさか我の村の者がそんな悪さをしていたとは　知らなかった』 　",
	"　　　　　　　　『村の者にはきつく言っておく』　　　　　　　　　",
	"　　『「ひと」の村にも迷惑をかけたと　後日詫びを入れよう』　　　",
	"　こうして　「ひと」の村と「あやかし」の村と「けもの」の村は　　\n　　　　　昔のような　平和な関係に戻ったのであった・・・　　　　",
};
CEnding::CEnding() :CObjectBase(0, eU_Back, eD_UI), font("HG行書体", 40)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("EndStaff"));
	m_img.SetSize(ENDEING_SIZ_X / 2, ENDEING_SIZ_Y / 2);
	m_img.SetCenter(ENDEING_SIZ_X / 4, 0);
	m_pos3D = CVector3D(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 1.2, 0);
	m_color.w = 0;
	SOUND("BGM_Ending")->Play(false);
	m_time = 0;
	m_taxt = 0;
	m_ac = true;
}

CEnding::~CEnding()
{
	SOUND("BGM_Ending")->Stop();
	NEW_SCENE(eGameStart)
}

void CEnding::Update()
{
	m_time++;
	if (m_taxt <= 12) {
		if (m_color.w == -1.0) {
			m_taxt++;
		}
		if (m_ac) {
			m_color.w += 0.05;
			if (m_color.w > 4.0)
				m_ac = false;
		}
		else {
			m_color.w -= 0.05;
			if (m_color.w < -1.0) {
				m_color.w = -1.0;
				m_ac = true;
			}
		}
	}else {
		if (m_pos3D.y - SCREEN_HEIGHT / 1.2 + ENDEING_SIZ_Y / 2 > 0){
			m_pos3D.y--;
			m_color.w = 2.0;
		}
		else
			m_color.w -= 0.01;

		if (m_color.w < -1.0) {
			SetKill();
		}
	}
}

void CEnding::Draw()
{
	font.Draw(0, m_pos3D.y - SCREEN_HEIGHT /1.5 , m_color.w, m_color.w, m_color.w, end[m_taxt].c_str());
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
	font.Draw(SCREEN_WIDTH / 2 - 250, m_pos3D.y - SCREEN_HEIGHT / 1.2 + ENDEING_SIZ_Y / 2 + 600, m_color.w, m_color.w, m_color.w, "あなたの得点は…　%5d点", m_score);
}