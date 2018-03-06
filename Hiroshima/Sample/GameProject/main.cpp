#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#define FULL_SCREEN 0
#define GAME_MODE	1

#include "stdafx.h"
#include "Global.h"
#include "GID.h"
#include "Gamesource.h"

/*

��ȕҏW�@�{��

*/

CBase* PL;
CBase* ENE;
CBase* GM1;
CBase* GM2;
CBase* GM3;
CBase* TITLE;


void MainLoop(void) {
	//UpDate
	TITLE->Update();
	PL->Update();
	ENE->Update();
	GM1->Update();
	GM2->Update();
	GM3->Update();
	//Draw
	TITLE->Draw();
	PL->Draw();
	ENE->Draw();
	GM1->Draw();
	GM2->Draw();
	GM3->Draw();


}
void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//�u�����h�̗L����
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	glEnable(GL_ALPHA_TEST);

	CFPS::SetFPS(60);
	//�t���[�����䏉����
	CFPS::Init();
	//�{�^���̐ݒ�
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'R');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton7, 'Q');
	CInput::SetButton(0, CInput::eButton8, 'E');
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);


	//CInput::SetMouseInside(true); 
	CInput::UpDate();
	CInput::UpDate();



	SetCurrentDirectory("data");

	CSound::GetInstance();
//������
	ADD_RESOURCE("Player", CAnimImage::LoadImage("player1.png", player_AnimData, 80, 96));
	ADD_RESOURCE("Enemy", CAnimImage::LoadImage("enemy.png", enemy_AnimData, 96, 96));
	ADD_RESOURCE("Fire", CAnimImage::LoadImage("fire.png", fire_Animdata, 30, 200));
	ADD_RESOURCE("Title", CAnimImage::LoadImage("title.png"));

	PL = new CPlayer();
	ENE = new CEnemy(CVector2D(500,500));
	GM1 = new CGimmick(CVector2D(500, 500));
	GM2 = new CGimmick(CVector2D(250, 500));
	GM3 = new CGimmick(CVector2D(500, 250));
	TITLE = new CTitle();



}


void release()
{
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}
static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);


	GL::UpdateWindosRect(GL::window_x, GL::window_y, w, h);

}
static void WheelCallback(GLFWwindow *_window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow *_window, int x, int y) {
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);

}
static void FocusCallback(GLFWwindow *_window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

int __main(int* argcp, char** argv) {
	// ���������[�N���o
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	glutInit(argcp,argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);


	GLint tex_size[2];
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, tex_size);
	printf("MaxTextureSize %d %d\n", tex_size[0], tex_size[1]);

	Init();



	while (!glfwWindowShouldClose(GL::window)) {
		static LARGE_INTEGER time;
		static LARGE_INTEGER time_buf;
		static long t_buf = 0;

		QueryPerformanceCounter(&time_buf);

		CInput::UpDate();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		MainLoop();
		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "sample fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}


