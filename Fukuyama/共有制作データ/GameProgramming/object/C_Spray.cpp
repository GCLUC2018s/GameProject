#include "C_Spray.h"




void C_Spray::Update(){
	//Init��1�x�����Ăт܂��i�R���X�g���N�^�ł�m_Playerpoint���G���[�ɂȂ邽��Init�ŏ������܂��j
	if (init == false){
		Init();
		init = true;
	}
}