#include "myLib.h"
#include "main.h"

//���[�J���ϐ�
CMain*		g_pMain = NULL;
const bool	WINDOW_SCREEN = true;

//���[�J���֐�
void win_main_init();
void win_main_loop();
void win_main_dest();

//�E�B���h�E��ʂ̃��C��
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance, LPSTR IpCmdLine,
	int nShowCmd)
{
	win_main_init();

	while (true){
		win_main_loop();
#if defined( _DEBUG ) | defined( DEBUG )
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) exit(-1);
#endif
	}
	win_main_dest();
}

//���C���̏���������

void win_main_init()
{
	//DirectX�֌W

	ChangeWindowMode(WINDOW_SCREEN);
	if (WINDOW_SCREEN)
	{
		SetGraphMode(800, 600, 32);
		SetMainWindowText(_T("�e�X�g�v���O����"));
	}
	if (DxLib_Init() == -1)		//���C�u�����̏���������
		return;

	//GAME�֌W
	g_pMain = new CMain();
	g_pMain->Init();
}

//���C�����[�v����
void win_main_loop()
{
	//���C������
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//���C���I������
void win_main_dest()
{
	g_pMain->Dest();
	delete g_pMain;
	g_pMain = NULL;
}