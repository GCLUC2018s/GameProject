#include "DxLib.h"
#include "math.h"
#include <list>

#include "player.h"
#include "task.h"
#include "taskmanager.h"

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
	
	int color_white = GetColor(255, 255, 255);//�F�擾
	int time = 1;
	
	//�l����.TaskManager����Task��update()���Ăяo���Ă��܂�
	TaskManager *tm = new TaskManager();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();

		for (int i = 0; i < 10; i++){
			tm->BTask = new Player();
			
		}
		tm->update();
		//�����܂�

		ScreenFlip();
	}
	delete tm->BTask;

	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}
