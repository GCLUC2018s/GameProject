#include "C_Spray.h"




void C_Spray::Update(){
	//Initを1度だけ呼びます（コンストラクタではm_PlayerpointがエラーになるためInitで処理します）
	if (init == false){
		Init();
		init = true;
	}
}