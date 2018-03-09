#include "DxLib.h"
#include "math.h"

//#include "player.h"
#include "task.h"
#include "taskmanager.h"
#include "player.h"
#include "enemy.h"

using namespace std;

//�E�B���h�E��ʂ̃��C��
int WINAPI WinMain(HINSTANCE hl, HINSTANCE hP, LPSTR IpC,
	int nC)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 32);
	SetMainWindowText("�T���v���v���O����");

	//DX���C�u����������
	if (DxLib_Init() == -1)return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	int time = 1;
	int color_white = GetColor(255, 255, 255);//�F�擾
	/*for (int i = 0; i < 10; i++){
		new CTask(i, i, i);
	}*/

	new CPlayer();
	new CEnemy();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();
		clsDx();
		CTaskManager::GetInstance()->UpdateAll();
		CTaskManager::GetInstance()->DrawAll();
		CTaskManager::GetInstance()->KillAppoint();
		ScreenFlip();
	}
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}
