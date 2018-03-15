#include "Nagao.h"

//コンストラクタ処理
Nagao::Nagao()
{
	Manhole = new C_Manhole();
}

void Nagao::Update(){
	Manhole->Update();
}

//描画処理
void Nagao::Draw(){
	Manhole->Draw();
}
