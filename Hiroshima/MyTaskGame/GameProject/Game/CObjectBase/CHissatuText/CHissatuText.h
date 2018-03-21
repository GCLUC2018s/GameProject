#ifndef HISSATU_TEXT_GUARD
#define HISSATU_TEXT_GUARD

#include "../CObjectBase.h"
#define MAX_SIZ 197

/*

制作者　宮﨑

*/
class CHissatuText : public CObjectBase
{
public:
	//「必殺！」
	CHissatuText();
	~CHissatuText();
	void Update();
	void Draw();
private:
	CAnimImage m_img2;
	int m_time;
	int m_size;
	bool	m_end_flag;	//終わりますよフラグ
};
#endif // !HISSATU_TEXT_GUARD
