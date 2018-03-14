#include "myLib.h"
#include "game.h"

CGame*	g_pMain = NULL;
const bool WINDOW_SCREEN = true;   //true:�E�B���h�E

void win_main_init();
void win_main_loop();
void win_main_dest();

/*const int SCREEN_W = 800;
const int SCREEN_H = 600;
int handle, x, add;
int Screen;
int DesktopW, DesktopH;
int OldWindowW, OldWindowH;
int WindowW, WindowH;*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	win_main_init();

	while (true){
		win_main_loop();
#if defined(_DEBUG) |defined(DEBUG)
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) exit(-1);
#endif
	}

	win_main_dest();

}

//���C������������
void win_main_init()
{
	//DerectX�֌W
	ChangeWindowMode(WINDOW_SCREEN);
	SetGraphMode(1280,720, 32);
	SetWindowText(_T("Code:Coat"));
	if (WINDOW_SCREEN)
	{
	}
	if (DxLib_Init() == -1) //���C�u�����̏���������
		return;
	SetDrawScreen(DX_SCREEN_BACK);
	//GAME�֌W
	g_pMain = new CGame();
	g_pMain->Init();
}


//���C�����[�v�̏���
void win_main_loop(){
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