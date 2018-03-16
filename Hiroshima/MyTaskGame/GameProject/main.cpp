#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#define FULL_SCREEN 0
#define GAME_MODE	1


#include "stdafx.h"
#include "Global.h"
#include "GID.h"
#include "../GameProject/Source/Gamesource.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

void MainLoop(void) {
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->HitChackAll();
	CTaskManager::GetInstance()->DrawAll();
	CTaskManager::GetInstance()->KillAppoint();
}
void Init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	glEnable(GL_ALPHA_TEST);

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
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
	//Debug用
	CInput::SetButton(0, CInput::eNum0, '0');
	CInput::SetButton(0, CInput::eNum1, '1');
	CInput::SetButton(0, CInput::eNum2, '2');
	CInput::SetButton(0, CInput::eNum3, '3');
	CInput::SetButton(0, CInput::eNum4, '4');


	//CInput::SetMouseInside(true); 
	CInput::UpDate();
	CInput::UpDate();



	SetCurrentDirectory("data");

	CSound::GetInstance();
	//初期化
	//キャラ関係
	ADD_RESOURCE("Player", CAnimImage::LoadImage("motion_player.png", player_AnimData, 512, 512));
	ADD_RESOURCE("Enemy", CAnimImage::LoadImage("zako_daruma_motion.png", enemy_AnimData, 512, 512));
	ADD_RESOURCE("Enemy2", CAnimImage::LoadImage("zako_chochin_motion.png", enemy_AnimData, 512, 512));
	ADD_RESOURCE("Enemy3", CAnimImage::LoadImage("zako_hi_motion.png", enemy_AnimData, 512, 512));
	ADD_RESOURCE("Enemy4", CAnimImage::LoadImage("zako_kamaitachi_motion.png", kamaitachi_AnimData, 512, 512));
	ADD_RESOURCE("Enemy5", CAnimImage::LoadImage("zako_niku_motion.png", enemy_AnimData, 512, 512));
	ADD_RESOURCE("Boss", CAnimImage::LoadImage("moton_jaryu.png", boss_AnimData, 768, 768));

	//ギミック関係
	ADD_RESOURCE("Fire", CAnimImage::LoadImage("fire_blue.png", fire_Animdata, 204, 245));

	//タイトル関係
	ADD_RESOURCE("Title_mihon", CAnimImage::LoadImage("タイトルイメージ.png"));
	ADD_RESOURCE("Title", CAnimImage::LoadImage("title.png"));
	ADD_RESOURCE("Title_pika", CAnimImage::LoadImage("title_pika.png"));

	//フィールド関係
	ADD_RESOURCE("Sky", CAnimImage::LoadImage("bg_sky_01.png"));
	ADD_RESOURCE("Cloud", CAnimImage::LoadImage("bg_cloud.png"));
	ADD_RESOURCE("Bamboo", CAnimImage::LoadImage("bg_bamboo.png"));
	ADD_RESOURCE("Ground", CAnimImage::LoadImage("bg_ground.png"));

	//テキスト関係
	ADD_RESOURCE("GameStartText", CAnimImage::LoadImage("text00.png"));
	ADD_RESOURCE("MainText", CAnimImage::LoadImage("text01.png"));
	ADD_RESOURCE("EndStaff", CAnimImage::LoadImage("ending.png"));

	//アイテム関係
	ADD_RESOURCE("Ohuda", CAnimImage::LoadImage("item_matome_1.png"));
	ADD_RESOURCE("Koban", CAnimImage::LoadImage("item_matome_1.png"));
	ADD_RESOURCE("Oage", CAnimImage::LoadImage("item_matome_1.png"));
	ADD_RESOURCE("Sake", CAnimImage::LoadImage("item_matome_1.png"));
	ADD_RESOURCE("Kakera", CAnimImage::LoadImage("item_kakera.png"));
	ADD_RESOURCE("ItemBox", CAnimImage::LoadImage("itembox_motion_object.png", itembox_Animdata, 512, 512));

	//UI関係
	ADD_RESOURCE("Tip", CAnimImage::LoadImage("tip.png"));
	ADD_RESOURCE("Magatama", CAnimImage::LoadImage("item_matome_1.png"));
	ADD_RESOURCE("GO", CAnimImage::LoadImage("go_sign.png"));

	//BGM
	SOUND("BGM_Title")->Load("Sound/BGM/Enishi.wav");
	SOUND("BGM_Main")->Load("Sound/BGM/n82.wav");
	SOUND("BGM_Main")->Volume(0.90f);
	SOUND("BGM_Ending")->Load("Sound/BGM/n32.wav");

	//SE
	SOUND("SE_PUNCH_KARA")->Load("Sound/SE/punch-swing1.wav", 10);
	SOUND("SE_DASH1")->Load("Sound/SE/dash1.wav", 50);
	SOUND("SE_DASH1")->Volume(0.90f);
	SOUND("SE_DASH2")->Load("Sound/SE/dash2.wav", 50);
	SOUND("SE_DASH2")->Volume(0.90f);
	SOUND("SE_DASH3")->Load("Sound/SE/dash3.wav", 50);
	SOUND("SE_DASH3")->Volume(0.90f);
	SOUND("SE_JUMP")->Load("Sound/SE/highspeed-movement1.wav", 50);
	SOUND("SE_JUMP")->Volume(0.90f);
	SOUND("SE_LANDING")->Load("Sound/SE/landing.wav", 50);
	SOUND("SE_LANDING")->Volume(0.90f);
	SOUND("SE_Title_Enter")->Load("Sound/SE/se_027.wav");
	SOUND("SE_GameStart")->Load("Sound/SE/bell01.wav");
	SOUND("SE_DDN")->Load("Sound/SE/se_011.wav");

	NEW_SCENE(eDebug);
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
	// メモリリーク検出
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


