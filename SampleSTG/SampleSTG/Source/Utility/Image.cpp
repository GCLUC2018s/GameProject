/*!
	@brief	画像描画クラス cpp
	@author	s.namizashi
**/

#include "Source/Include.hpp"
#include "Image.hpp"

namespace
{
	// 定数
	const int	IHUNDLE_INVALID	= -1;				// 無効画像ハンドル
	const char*	IMAGE_DIR_PATH	= "Data/Image/";	// 読み込みディレクトリパス
}

// コンストラクタ
clImage::clImage()
	: m_Pos(0.0f,0.0f)
	, m_UV(0,0,0,0)
	, m_Center(0.0f,0.0f)
	, m_Scale(1.0f,1.0f)
	, m_Color(255,255,255,255)
	, m_iHundle(IHUNDLE_INVALID)
	, m_Angle(0.0f)
	, m_IsTurn(false)
{
}

// デストラクタ
clImage::~clImage()
{
	Release();
}

// 描画情報初期化
void clImage::InitDrawInfo()
{
	// 描画位置
	SetPos(0.0f,0.0f);

	// UV
	int w, h;
	w = h = 0;
	// 画像が読み込まれていれば、
	if(m_iHundle != IHUNDLE_INVALID) GetGraphSize(m_iHundle,&w,&h);
	SetUV(0,0,w,h);

	// 中心点位置
	SetCenter(DIR_CENTER);

	// スケール値
	SetScale(1.0f);

	// 回転値
	SetRotate(0.0f);
}

// 初期化処理
void clImage::Init()
{
}

// 画像読み込み
void clImage::Load( const char* name )
{
	// 読み込んでいる画像解放
	Release();

	// ディレクトリパスと合体
	char str[128];
	ZeroMemory(str,sizeof(str));
	sprintf_s(str,128,"%s%s",IMAGE_DIR_PATH,name);
	// 画像読み込み
	m_iHundle = LoadGraph(str);

	// 描画情報初期化
	InitDrawInfo();
}

// 描画位置設定
void clImage::SetPos( float x, float y )
{
	// 画像が読み込まれているかどうか
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;

	// 画像サイズ取得
	int w, h;
	GetGraphSize(m_iHundle,&w,&h);

	m_Pos.x = x + ((float)w*0.5f);
	m_Pos.y = y + ((float)h*0.5f);
}

// UV設定(ピクセル指定)
void clImage::SetUV( int sx, int sy, int ex, int ey )
{
	// 画像が読み込まれているかどうか
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;

	// 画像サイズ取得
	int w, h;
	GetGraphSize(m_iHundle,&w,&h);

	// 0 <= 開始X座標 < 終了X座標 <= 画像幅
	SN_ASSERT(0 <= sx && sx < ex && ex <= w);
	if(!(0 <= sx && sx < ex && ex <= w)) return;
	// 0 <= 開始Y座標 < 終了Y座標 <= 画像高さ
	SN_ASSERT(0 <= sy && sy < ey && ey <= h);
	if(!(0 <= sy && sy < ey && ey <= h)) return;

	m_UV.sx = sx;
	m_UV.sy = sy;
	m_UV.ex = ex;
	m_UV.ey = ey;
}

// UV設定(割合指定)
void clImage::SetUV( float sx, float sy, float ex, float ey )
{
	// 画像が読み込まれているかどうか
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;
	// 0.0f <= 開始X座標割合 < 終了X座標割合 <= 1.0f
	SN_ASSERT(0.0f <= sx && sx < ex && ex <= 1.0f);
	if(!(0.0f <= sx && sx < ex && ex <= 1.0f)) return;
	// 0.0f <= 開始Y座標割合 < 開始Y座標割合 <= 1,0f
	SN_ASSERT(0.0f <= sy && sy < ey && ey <= 1.0f);
	if(!(0.0f <= sy && sy < ey && ey <= 1.0f)) return;

	// 画像サイズ取得
	int w, h;
	GetGraphSize(m_iHundle,&w,&h);

	// 画像サイズの割合を取得し、その値でUV設定
	int isx((int)(w*sx));
	int isy((int)(h*sy));
	int iex((int)(w*ex));
	int iey((int)(h*ey));
	SetUV(isx,isy,iex,iey);
}

UVI clImage::GetUV() const
{
	return m_UV;
}

// 中心点設定(タイプ指定用)
void clImage::SetCenter( enDirection type )
{
	// 画像が読み込まれているかどうか
	SN_ASSERT(m_iHundle != IHUNDLE_INVALID);
	if(!(m_iHundle != IHUNDLE_INVALID)) return;
	// 画像サイズ取得
	int iw, ih;
	GetGraphSize(m_iHundle,&iw,&ih);
	// 画面サイズの半分の値を取得
	float	w,	h,	hw,	hh;
	w = (float)iw;
	h = (float)ih;
	hw = (float)w*0.5f;
	hh = (float)h*0.5f;

	switch(type)
	{
		case DIR_CENTER:		m_Center = VECTOR2F(hw,		hh);	break;	// 中央
		case DIR_UP:			m_Center = VECTOR2F(hw,		0.0f);	break;	// 上
		case DIR_UP_RIGHT:		m_Center = VECTOR2F(w,		0.0f);	break;	// 右上
		case DIR_RIGHT:			m_Center = VECTOR2F(w,		hh);	break;	// 右
		case DIR_DOWN_RIGHT:	m_Center = VECTOR2F(w,		h);		break;	// 右下
		case DIR_DOWN:			m_Center = VECTOR2F(hw,		h);		break;	// 下
		case DIR_DOWN_LEFT:		m_Center = VECTOR2F(0.0f,	h);		break;	// 左下
		case DIR_LEFT:			m_Center = VECTOR2F(0.0f,	hh);	break;	// 左
		case DIR_UP_LEFT:		m_Center = VECTOR2F(0.0f,	0.0f);	break;	// 左上
	}
}

// 中心点設定(位置指定用)
void clImage::SetCenter( int x, int y )
{
	m_Center.x = (float)x;
	m_Center.y = (float)y;
}

// スケール値設定(個別指定用)
void clImage::SetScale( float x, float y )
{
	m_Scale.x = x;
	m_Scale.y = y;
}

// スケール値設定(共通指定用)
void clImage::SetScale( float scl )
{
	m_Scale.x = scl;
	m_Scale.y = scl;
}

// スケール値取得
VECTOR2F clImage::GetScale() const
{
	return m_Scale;
}

// カラー設定(COLOR4I型用)
void clImage::SetColor( COLOR4I color )
{
	m_Color = color;
}

// 回転値設定(ラジアン指定用)
void clImage::SetRotate( float rot )
{
	m_Angle = rot;
}

// 回転値設定(ディグリー指定用)
void clImage::SetRotate( int rot )
{
	// ラジアンに変更して設定
	SetRotate(SN_DIGTORAD(rot));
}

// 左右反転するかどうかを設定
void clImage::SetTurn( bool is_turn )
{
	m_IsTurn = is_turn;
}

// 読み込んでいる画像解放
void clImage::Release()
{
	if(m_iHundle != IHUNDLE_INVALID)
	{
		DeleteGraph(m_iHundle);
		m_iHundle = IHUNDLE_INVALID;
	}
}

// 更新処理
void clImage::Update()
{
}

// 描画処理
void clImage::Draw()
{
	// 画像が読み込まれていれば、
	if(m_iHundle != IHUNDLE_INVALID)
	{
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		// 色設定
		SetDrawBright(m_Color.r,m_Color.g,m_Color.b);
		// アルファ値設定
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,m_Color.a);

		// 描画
		DrawRectRotaGraph3F
		(
			m_Pos.x,	m_Pos.y,	// 描画位置
			m_UV.sx,	m_UV.sy,	m_UV.ex,	m_UV.ey,	// UV
			m_Center.x,	m_Center.y,	// 中心位置
			m_Scale.x,	m_Scale.y,	// スケール値
			m_Angle,		// 回転値
			m_iHundle,		// 画像ハンドル
			true,			// 透過の有無
			m_IsTurn		// 画像左右反転の有無
		);

		// 色初期化
		SetDrawBright(255,255,255);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	}
}
