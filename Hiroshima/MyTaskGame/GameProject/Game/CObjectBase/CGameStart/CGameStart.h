#ifndef GAME_START_GUARD
#define GAME_START_GUARD

#define GAME_START_X 711
#define GAME_START_Y 76

#define GAME_START_TIME 120

#include "../CObjectBase.h"

/*

����ҁ@�{��

*/
class CGameStart : public CObjectBase
{
public:
	//�v���[���c
	CGameStart();
	~CGameStart();
	void Update();
private:
	float	m_siz;	//�T�C�Y�p
	float	m_up_siz;	//���₷��
	bool	m_end_flag;	//�I���܂���t���O
	int		m_cnt;	//�t�F�[�h�A�E�g�J�n�B
};
#endif // !GAME_START_GUARD
