#ifndef HISSATU_TEXT_GUARD
#define HISSATU_TEXT_GUARD

#include "../CObjectBase.h"
#define MAX_SIZ 197

/*

����ҁ@�{��

*/
class CHissatuText : public CObjectBase
{
public:
	//�u�K�E�I�v
	CHissatuText();
	~CHissatuText();
	void Update();
	void Draw();
private:
	CAnimImage m_img2;
	int m_time;
	int m_size;
	bool	m_end_flag;	//�I���܂���t���O
};
#endif // !HISSATU_TEXT_GUARD
