#ifndef SCREEN_H
#define SCREEN_H

//�Q�[���X�N���[���̎��
enum SCREEN{
	TITLE_SCREEN,
	OPTION_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN,
};

class CScreen
{
public:
	virtual SCREEN GetNextScreen() = 0;		//���̃X�N���[��������
	virtual void Init(){}
	virtual void Load(){}
	virtual void Release(){}
	virtual void Update(){}
	virtual void Draw(){}
	virtual void Dest(){}
};

#endif SCREEN_H