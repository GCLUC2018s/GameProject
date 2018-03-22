#include "CDrum.h"
#include "../CCollider.h"
#include "../task/CTaskManager.h"
//テクスチャクラスをインスタンス化
CTexture mTexture;

void C_Drum::Dmain(){
	//シードで乱数を初期化
	srand((unsigned)time(NULL));
}

//アニメーションカウント
int m_DrumAnimationCount = 30;
//ドラム缶の移動処理
#define Drum_Move 4
//コンストラクタで初期化
C_Drum::C_Drum()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_DrumPos_Random(rand() % 3)
{
	mTexture.Load("object/Drum.tga");
	//0の場合、真ん中に配置
	if (m_DrumPos_Random == 0){
		m_Position.z += Zpos_SetPos_Center;
	}
	//1の場合、上に配置
	else if (m_DrumPos_Random == 1){
		m_Position.z += Zpos_SetPos_Up;
	}
	//2の場合、下に配置
	else if (m_DrumPos_Random == 2){
		m_Position.z += Zpos_SetPos_Down;
	}
}

//更新処理
void C_Drum::Update(){
	m_image.SetVertex(-64, 64, -64, 64);
	//スクロールする
	Scroll(&m_Position, m_Scroll);
	//画面左端に行った時
	if (m_Position.x < DISPLAY_LEFT){
		SetKill();
		new C_Drum();
	}
	m_DrumAnimationCount--;
	m_Position.x -= Drum_Move;
	//アニメーション処理
	if (m_DrumAnimationCount >= 24){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	}
	else if (m_DrumAnimationCount <= 24 && m_DrumAnimationCount >= 18){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 128, 256, 128, 0);
	}
	else if (m_DrumAnimationCount <= 18 && m_DrumAnimationCount >= 12){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 256, 384, 128, 0);
	}
	else if (m_DrumAnimationCount <= 12 && m_DrumAnimationCount >= 6){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 384, 512, 128, 0);
	}
	else if (m_DrumAnimationCount <= 6 && m_DrumAnimationCount >= 0){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 512, 640, 128, 0);
	}
	else{
		m_DrumAnimationCount = 30;
	}
	//衝突判定
	m_Colimage = m_image;

	CTaskManager::GetInstance()->ChangeDrawPrio(this, -m_Position.z);
}

bool C_Drum::Collision(CTask* p, CTask* q){
	C_Object* ip_My = (C_Object*)p;
	C_Object* ip_You = (C_Object*)q;
	ip_My->m_Collision_Wide = 50;
	if (ip_You->m_id == E_PLAYER&&
		C_Collider::Collision(ip_My, ip_You, &ip_My->m_Position, &ip_You->m_Position)){
		ip_You->m_Position.x += ip_You->m_Colimage.m_AdjustX;
		ip_You->m_Position.z += ip_You->m_Colimage.m_AdjustZ;
		ip_You->m_Position.x += ip_You->m_Colimage.m_AdjustX;
		ip_You->m_Position.z += ip_You->m_Colimage.m_AdjustZ;
	}
	return true;
}
void C_Drum::Drum_Rect(C_Rectangle *image, const C_Vector3* pos){
	image->m_wide = (image->m_Right - image->m_Left) / 2;  //ポジションからC_Rectangleの左右までの距離
	image->m_high = (image->m_Top - image->m_Bottom) / 2;  //高さ
	image->m_Right = pos->x + image->m_wide;
	image->m_Left = pos->x - image->m_wide;
	image->m_Bottom = pos->z - image->m_high;
	image->m_Top = pos->z + image->m_high;
	return;
}
//描画処理
void C_Drum::Draw(){
	Drum_Rect(&m_image, &m_Position);
}

