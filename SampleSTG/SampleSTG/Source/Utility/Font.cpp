/*!
	@brief	文字列描画クラス cpp
	@author	s.namizashi
**/

#include "Source/Include.hpp"
#include "Font.hpp"

namespace
{
	// 定数
	const int	FHUNDLE_INVALID	= -1;	// 無効フォントハンドル
	const int	FSIZE_DEFAULT	= -1;	// フォントサイズのデフォルト値
	const int	FTHICK_DEFAULT	= -1;	// フォントの太さのデフォルト値
	const int	FTHICK_MIN		= 0;	// フォントの太さの最小値
	const int	FTHICK_MAX		= 9;	// フォントの太さの最大値
	const DWORD	FCOLOR_DEFAULT	= 0xffffffff;		// フォントカラーのデフォルト値(白色)
	const char*	FNAME_DEFALUT	= "ＭＳ ゴシック";	// 使用デフォルトフォント名

	// フォントタイプテーブル
	const int FONT_TYPE_TABLE[] =
	{
		DX_FONTTYPE_NORMAL,		// デフォルト
		DX_FONTTYPE_NORMAL,
		DX_FONTTYPE_EDGE,
		DX_FONTTYPE_ANTIALIASING,
		DX_FONTTYPE_ANTIALIASING_4X4,
		DX_FONTTYPE_ANTIALIASING_8X8,
		DX_FONTTYPE_ANTIALIASING_EDGE,
		DX_FONTTYPE_ANTIALIASING_EDGE_4X4,
		DX_FONTTYPE_ANTIALIASING_EDGE_8X8
	};
}

// コンストラクタ
clFont::clFont()
	: m_fName(FNAME_DEFALUT)
	, m_fHundle(FHUNDLE_INVALID)
	, m_fSize(FSIZE_DEFAULT)
	, m_fThick(FTHICK_DEFAULT)
	, m_fType(FONT_TYPE_TABLE[FTYPE_DEFAULT])
	, m_fColor(FCOLOR_DEFAULT)
	, m_IsShadow(false)
	, m_IsChange(false)
	, m_IsCenter(false)
{
}

// デストラクタ
clFont::~clFont()
{
}

// 読み込んでいるフォント解放
void clFont::Release()
{
	// 既にフォントが読み込まれていれば、
	if(m_fHundle != FHUNDLE_INVALID)
	{
		// フォントデータ削除
		DeleteFontToHandle(m_fHundle);
		m_fHundle = FHUNDLE_INVALID;
	}
}

// フォント作成
void clFont::Create()
{
	// 現在のフォント削除
	Release();
	// 新しいフォント作成
	m_fHundle = CreateFontToHandle(m_fName.c_str(),m_fSize,m_fThick,m_fType);
}

// 初期化処理
void clFont::Init()
{
	// フォントを作成
	Create();
}

// フォント名設定
void clFont::SetName( const char* fName )
{
	SN_ASSERT(fName);
	if(!fName) return;

	m_fName.clear();
	m_fName.append(fName);
	m_IsChange = true;
}

// フォントサイズ設定
void clFont::SetSize( int size )
{
	SN_ASSERT((size == FSIZE_DEFAULT) || (size > 0));
	if(!((size == FSIZE_DEFAULT) || (size > 0))) return;

	m_fSize = size;
	m_IsChange = true;
}

// フォントの太さ設定
void clFont::SetThick( int thick )
{
	SN_ASSERT(FTHICK_DEFAULT <= thick && thick <= FTHICK_MAX);
	if(!(FTHICK_DEFAULT <= thick && thick <= FTHICK_MAX)) return;

	m_fThick = thick;
	m_IsChange = true;
}

// フォントタイプ設定
void clFont::SetType( enFontType type )
{
	SN_ASSERT(FTYPE_NONE < type && type < FTYPE_COUNT);
	if(!(FTYPE_NONE < type && type < FTYPE_COUNT)) return;

	m_fType = FONT_TYPE_TABLE[type];
	m_IsChange = true;
}

// フォントカラー設定
void clFont::SetColor( DWORD color )
{
	m_fColor = color;
}

// 影の有無設定
void clFont::SetShadow( bool flag )
{
	m_IsShadow = flag;
}

// 描画文字列設定
void clFont::Print( VECTOR2I pos, const char* format, ... )
{
	// 引数リスト作成
	va_list arg;
	// リスト初期化
	va_start(arg, format);

	// 描画情報
	stDrawInfo info;
	info.pos = pos;
	info.color = m_fColor;

	// 文字列書き込み
	vsprintf_s(info.str,format,arg);

	m_DrawList.push_back(info);

	va_end(arg);
}

// デバッグ文字列描画用
void clFont::DebugPrint( VECTOR2I pos, const char* format, ... )
{
	// デバッグフォント描画クラスが読み込まれてなければ、リターン
	if(!nsGameBoard::g_debug_font) return;

	// 引数リスト作成
	va_list arg;
	// リスト初期化
	va_start(arg, format);

	// 文字列書き込み
	char tStr[FONT_BUFFER_SIZE];
	ZeroMemory(tStr,sizeof(tStr));
	vsprintf_s(tStr,format,arg);

	// デバッグフォント描画クラスに書き込み
	nsGameBoard::g_debug_font->Print(pos,tStr);

	va_end(arg);
}

// 更新処理
void clFont::Update()
{
	// フォント切り替え
	if(m_IsChange)
	{
		// 新しいフォント作成
		Create();
		m_IsChange = false;
	}
}

// 描画処理
void clFont::Draw()
{
	// フォント読み込み済み
	if(m_fHundle != FHUNDLE_INVALID)
	{
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		// リスト内の描画情報を元に全て描画
		DRAWLIST::iterator it = m_DrawList.begin();
		while(it != m_DrawList.end())
		{
			// 描画
			const stDrawInfo* info(&(*it));
			VECTOR2I pos(info->pos);
			if(m_IsCenter)
			{
				int width(GetDrawStringWidth(info->str,strlen(info->str)-1));
				pos.x -= width/2;
			}
			// 影が有効ならば、
			if(m_IsShadow)
			{
				// 影描画(カラー反転)
				DrawStringToHandle(pos.x+1,pos.y+1,info->str,info->color^0x00ffffff,m_fHundle);
			}
			// 本体
			DrawStringToHandle(pos.x,pos.y,info->str,info->color,m_fHundle);
			++it;
		}
		// 描画が終われば、描画情報リスト解放
		m_DrawList.clear();
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}
