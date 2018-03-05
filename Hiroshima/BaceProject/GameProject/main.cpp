#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#define FULL_SCREEN 0


#include "stdafx.h"
#include "Global.h"
#include "GID.h"
//--------------------------------------------
//グローバル変数領域
//--------------------------------------------




void display(void) {
	//各バッファーをクリア
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//カメラ行列を反映
	glLoadMatrixf(CCamera::GetCamera()->GetMatrix().f);
	
//--------------------------------------------------------------
//ゲーム中の動きはここに書く
//ゲーム中はこの関数を1秒間に60回呼び出している
//--------------------------------------------------------------













//---------------------------------------------------------------
	glutSwapBuffers();

}
void init(void)
{
	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);


//	CInput::SetMouseInside(true); 
	CInput::UpDate();
	CInput::UpDate();


	//ライト設定
	CLight::SetType(0, CLight::eLight_Direction);
	CLight::SetPos(0, CVector3D(0, 200, 200));
	CLight::SetDir(0, CVector3D(-2, -2, 1).GetNormalize());
	CLight::SetColor(0, CVector3D(0.8f, 0.8f, 0.8f), CVector3D(0.8f, 0.8f, 0.8f));

//	CLight::SetType(1, CLight::eLight_Point);
	CLight::SetColor(1, CVector3D(0.0f, 0.0f, 0.0f), CVector3D(1.0f, 1.0f, 1.0f));
	CLight::SetAttenuation(1,0.10f);
//	CLight::SetRadiationAngle(1, Utility::DgreeToRadian(5.0f));

	CLight::SetFogParam(CVector4D(1, 1, 1, 1), 300, 400);
	//カメラ初期化
	CCamera::GetCamera()->LookAt(	CVector3D(0,100,-150),
									CVector3D(0,10,0),
									CVector3D(0.0, 1.0, 0.0));
	
//-----------------------------------------------------
//初期化の命令を書く
//ゲーム起動時に一度だけ呼ばれる
//-----------------------------------------------------

}


void release()
{
//--------------------------------------------------------------
//画像の破棄などを書く
//ゲーム終了時に一度だけ呼ばれる
//--------------------------------------------------------------


	CResourceManager::ClearInstance();
}
void resize(int w, int h)
{

	glViewport(0, 0, w, h);
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	CCamera::GetCamera()->SetScreenRect(CRect(0, 0, (float)w, (float)h));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	CMatrix mProj;
	mProj.Perspective(Utility::DgreeToRadian(45.0), (float)w / (float)h, 1.0, 10000.0);
	CCamera::GetCurrent()->SetProjectionMatrix(mProj);
	glLoadMatrixf(mProj.f);



}



void idle(void)
{
	static LARGE_INTEGER time;
	static LARGE_INTEGER time_buf;
	static long t_buf=0;
	//現在のシステムのカウント数を取得
	QueryPerformanceCounter(&time_buf);

	CInput::UpDate();
	display();
	//現在のシステムのカウント数を取得
	QueryPerformanceCounter(&time);
	//現在のシステムのカウント数を取得
	if (t_buf == 0) {
		t_buf = time.QuadPart - time_buf.QuadPart;
	}
	else {
		t_buf = (t_buf + (time.QuadPart - time_buf.QuadPart)) / 2;
	}

	CFPS::Wait();

	char title[32];
	sprintf_s(title, "sample fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
	glutSetWindowTitle(title);

}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '\033':  // '\033' は ESC の ASCII コード
		glutLeaveMainLoop();
	default:
		break;
	}
}
void wheel(int wheel_number, int direction, int x, int y)
{
	CInput::AddMouseWheel(direction);
}



int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	glutInit(argcp, argv);



	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("sample");
#if (FULL_SCREEN)
	int nMode = 0;
	DEVMODE devMode;
	while (EnumDisplaySettings(NULL, nMode++, &devMode)) {
		if (devMode.dmPelsWidth != SCREEN_WIDTH || devMode.dmPelsHeight != SCREEN_HEIGHT)continue;
		if (devMode.dmBitsPerPel != 32)continue;
		if (ChangeDisplaySettings(&devMode, CDS_TEST) == DISP_CHANGE_SUCCESSFUL)break;
	}
	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
	glutFullScreen();
#else
#endif

	glewInit();

	SetCurrentDirectory(L"data");


	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glEnable(GL_ALPHA_TEST);





	init();


	HDC glDc = wglGetCurrentDC();



	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutReshapeFunc(resize);
	glutMouseWheelFunc(wheel);

	
	//ウィンドウハンドル取得
	HWND hWnd = WindowFromDC(glDc);

	SetWindowLong(hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE); //ウィンドウスタイルの設定
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop();

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


void DrawLine(CVector3D &s, CVector3D &e, CVector4D color) {
	glDisable(GL_LIGHTING);

	glColor4fv(color.v);
	glBegin(GL_LINES);
	glVertex3fv(s.v);
	glVertex3fv(e.v);
	glEnd();
	glEnable(GL_LIGHTING);
}
void DrawSphere(CVector3D pos, float rad, CVector4D color) {
	glEnable(GL_LIGHTING);

	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glColor4fv(color.v);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color.v);

	glutSolidSphere(rad, 16, 16);

	glPopMatrix();

}

void ControlCamera(CVector3D at) {
	//カメラ操作
	static CVector3D camRot(M_2_PI, M_PI, 0);
	static float camLength = 10.0f;
	CVector2D mouseVec = CInput::GetMouseVec();
	camRot.y += mouseVec.x * -0.003f;
	camRot.x += mouseVec.y * 0.003f;
	camLength += CInput::GetMouseWheel()*0.2f;
	if (camLength < 0) camLength = 0;
	CCamera::GetCurrent()->LookAt(at + CMatrix::MRotation(camRot).GetFront()*-camLength, at, CVector3D(0, 1, 0));

}

void RenderSkybox() {
	glDisable(GL_DEPTH_TEST);
	static CModel* skybox = nullptr;
	if (!skybox) {
		CResourceManager::GetInstance()->Add("Sky", CModel::CreateModel("Sky.obj"));
		skybox = dynamic_cast<CModel*>(CResourceManager::GetInstance()->Get("Sky"));
	}
	CMatrix matrix;
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix.f);
	matrix.m03 = 0; matrix.m13 = 0; matrix.m23 = 0;
	glPushMatrix();
	glLoadMatrixf(matrix.f);
	CLight::SetLighting(false);
	skybox->Render();
	CLight::SetLighting(true);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
}