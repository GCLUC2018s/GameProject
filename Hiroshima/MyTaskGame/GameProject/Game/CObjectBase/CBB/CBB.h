#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

§ìÒ@{ú±

*/
class CBB : public CObjectBase
{
public:
	//ÄÑoµ½çAæÊªÃ­ÈÁÄAG^[L[ðµ½çÁ¦éNX
	//\¦bi»ÌÔAvC[Íìs\j,	trueÈçuGð|¹Iv\¦
	CBB(const int time,const bool flag);
	~CBB();
	void Update();
private:
	int m_cnt;	//50JEg
	int m_time;	//50Ò@ÔiøÅwèj
//	bool m_flag; //trueÈçAuGð|¹Iv\¦
};
#endif // !BB_GUARD
