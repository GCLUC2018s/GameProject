#ifndef TITLE_BG_GUARD
#define TITLE_BG_GUARD

#include "../CObjectBase.h"

/*

§ìÒ@{ú±

*/
class CTitleBG : public CObjectBase
{
public:
	//^Cgæ
	CTitleBG();
	~CTitleBG();
	void Update();
	void Draw();
private:
	bool m_end_flag;	//G^[³ê½ÌÅIíèÜ·ætO
	CAnimImage m_img_pika;
	bool m_pika_flag;	//falseÈçÒ©ªÁ¦éBtrueÈçÒ©ªoé
};

#endif // !TITLE_BG_GUARD
