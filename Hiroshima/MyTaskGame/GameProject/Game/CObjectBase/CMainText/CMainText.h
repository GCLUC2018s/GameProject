#ifndef MAIN_TEXT_GUARD
#define MAIN_TEXT_GUARD

#define MAIN_TEXT_X 1171
#define MAIN_TEXT_Y 151

#define MAIN_TEXT_TIME 85
#define MAIN_TEXT_UP 0.05

#include "../CObjectBase.h"

/*

����ҁ@�{��

*/
class CMainText : public CObjectBase
{
public:
	//�u�G��|���I�v
	CMainText();
	~CMainText();
	void Update();
private:
	bool	m_end_flag;	//�I���܂���t���O
};
#endif // !MAIN_TEXT_GUARD
