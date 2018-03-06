//ヘッダファイルのインクルード
#include "CMain.h"
#include "glut.h"
#include "test.h"
test tes;
//初めに1回だけ実行する処理の定義
void CMain::Init() {
	tes.Init();
}

//繰り返し実行する処理の定義
void CMain::Update() {
	tes.Update();
	tes.Render();
}
