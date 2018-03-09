#include "Source/Include.hpp"
#include "Source/Utility/Timer.hpp"
#include "Source/Utility/Font.hpp"

#include "Source/Scene/SceneManager.hpp"
#include "Source/Utility/InputManager.hpp"
#include "Source/Task/CTaskManager.h"
#include "Source/Game/Enemy/EnemyManager.hpp"
#include "Source/Game/Bullet/BulletManager.hpp"

// ����������
bool Init()
{
	// �����V�[�h�ݒ�
	srand((unsigned int)time(NULL));

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(1);
	// �A�v�����ݒ�
	SetWindowText(APP_NAME);
	// �E�B���h�E�T�C�Y�ݒ�
	SetGraphMode(WINDOW_WIDTH,WINDOW_HEIGHT,32);
	// �E�B���h�E���A�N�e�B�u�����������s
	SetAlwaysRunFlag(true);
#ifndef	_DEBUG
	// Release���[�h�Ȃ�΁A���O�o�͂��Ȃ�
	SetOutApplicationLogValidFlag(false);
#endif

	// DX���C�u����������
	int ans(DxLib_Init());
	// �������G���[
	if(ans == -1) return false;

	// �f�o�b�O�t�H���g�ǂݍ���
	nsGameBoard::g_debug_font = new clFont;
	nsGameBoard::g_debug_font->Init();
	nsGameBoard::g_debug_font->SetShadow(true);

	// �V�[���Ǘ��N���X������
	clSceneManager::GetInstance()->Init();

	// ���͊Ǘ��N���X������
	clInputManager::GetInstance()->Init();

	return true;
}

// �I������
void Exit()
{
	SN_SAFE_DELETE(nsGameBoard::g_debug_font);

	clInputManager::GetInstance()->ClearInstance();
	clSceneManager::GetInstance()->ClearInstance();
	CTaskManager::GetInstance()->ClearInstance();
	clEnemyManager::GetInstance()->ClearInstance();
	clBulletManager::GetInstance()->ClearInstance();

	// DX���C�u�����I������
	DxLib_End();
}

// ���C������
void Main()
{
	CTaskManager::GetInstance()->KillAppoint();

	// ���͔���X�V
	clInputManager::GetInstance()->Update();

	// �X�V����
	{
		// �G�l�~�[�}�l�[�W���[�X�V
		clEnemyManager::GetInstance()->Update();
		// ���e�}�l�[�W���[�X�V
		clBulletManager::GetInstance()->Update();

		// �V�[���}�l�[�W���[�X�V
		clSceneManager::GetInstance()->Update();
		// �^�X�N�}�l�[�W���[�X�V
		CTaskManager::GetInstance()->UpdateAll();

		// �f�o�b�O�t�H���g�X�V
		nsGameBoard::g_debug_font->Update();
	}
	// �`�揈��
	{
		// �^�X�N�}�l�[�W���[�`��
		CTaskManager::GetInstance()->DrawAll();
		// �f�o�b�O�t�H���g�`��
		nsGameBoard::g_debug_font->Draw();
	}
}

int main()
{
	// ������
	if(!Init())
	{
		// �G���[�Ȃ�΁A�I��
		return -1;
	}

	clTimer loopTimer;	// ���C�����[�v�p�^�C�}�[

	// ����ʂɕ`�悷��ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	// ���C�����[�v
	while(1)
	{
		// 1�t���[���̎��Ԍv���J�n
		loopTimer.StartTimer();

		// ��ʃN���A
		ClearDrawScreen();
		// ��ʂ����F�ɖ��߂�
		DrawBox(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,GetColor(0,0,0),true);

		// ���C������
		Main();

		// ��ʂ̗��\�؂�ւ�
		ScreenFlip();

		// �҂�����
		do{
		}while(loopTimer.GetTimeMCS() < (1.0/(double)FRAME_RATE));
		// ���Ԍv����~
		loopTimer.StopTimer();

		// �I������
		{
			// Windows�̃��b�Z�[�W����
			if(ProcessMessage() == -1) break;
			// �uEsc�v�L�[�ŏI��
			if(clInputManager::GetInstance()->IsPushKey(IK_ESCAPE)) break;
		}
	}

	// �I��
	Exit();

	return 0;
}
