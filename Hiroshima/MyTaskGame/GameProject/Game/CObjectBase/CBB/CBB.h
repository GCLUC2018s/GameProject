#ifndef BB_GUARD
#define BB_GUARD

#include "../CObjectBase.h"

/*

§ìÒ@{ú±

*/
class CBB : public CObjectBase
{
public:
	//ÄÑoµ½çtF[hAEgC·é
	//\¦bi»ÌÔAvC[Íìs\j,	trueÈçuGð|¹Iv\¦,trueÈçA¾ñ¾ñ­Èé
	CBB(const int time, const int flag, const bool flagin);
	~CBB();
	void Update();
	void Draw();
private:
	int m_cnt;	//50JEg
	int m_time;	//50Ò@ÔiøÅwèj
	//1ÈçAuGð|¹Iv\¦
	//2ÈçABossÉÚ®
	int m_flag; 
	bool m_flag_In; //trueÈçA¾ñ¾ñ­Èé
};
#endif // !BB_GUARD
