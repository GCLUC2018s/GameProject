#ifndef ENDEING_GUARD
#define ENDEING_GUARD

#include "../CObjectBase.h"

#define ENDEING_SIZ_X 1000
#define ENDEING_SIZ_Y 6394

/*

§ìÒ@{ú±

*/
class CEnding : public CObjectBase
{
public:
	//^Cgæ
	CEnding();
	~CEnding();
	void Update();
	void Draw();
private:
	bool m_end_flag;	//IíèÜ·ætO
	CFont font;
	int m_time;			//oßÔ
	int m_taxt;			//\¦ê
	bool m_ac;			//tF[h^C~O@trueÈçvX
};

#endif // !ENDEING_GUARD
