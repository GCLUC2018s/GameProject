/*!
	@brief	文字列描画クラス hpp
	@author	s.namizashi
**/

#ifndef __FONT_HPP__
#define __FONT_HPP__

class clFont
{
	private:
		enum
		{
			FONT_BUFFER_SIZE	= 512,	// 一度のPrintで設定出来る文字数
		};

		// フォント描画情報
		struct stDrawInfo
		{
			char		str[FONT_BUFFER_SIZE];
			VECTOR2I	pos;
			DWORD		color;
			stDrawInfo()
			{
				ZeroMemory(str,sizeof(str));
				pos = VECTOR2I(0,0);
				color = 0xffffffff;
			}
		};

		// フォント描画情報リストのデータ型
		typedef	std::vector<stDrawInfo> DRAWLIST;

		DRAWLIST	m_DrawList;		//!< フォント描画情報リスト
		std::string	m_fName;		//!< フォント名
		int			m_fHundle;		//!< フォントハンドル
		int			m_fSize;		//!< フォントサイズ
		int			m_fThick;		//!< フォントの太さ
		int			m_fType;		//!< フォントタイプ
		DWORD		m_fColor;		//!< フォントカラー
		bool		m_IsShadow;		//!< 影の有無(trueならば、影有り)
		bool		m_IsChange;		//!< フォント変更するかどうか
		bool		m_IsCenter;

		/*!
			@brief	読み込んでいるフォント解放
		**/
		void Release();

		/*!
			@brief	フォント作成
		**/
		void Create();
	public:
		// フォントタイプ
		enum enFontType
		{
			FTYPE_NONE = -1,

			FTYPE_DEFAULT,					// デフォルトフォント
			FTYPE_NORMAL,					// ノーマルフォント
			FTYPE_EDGE,						// エッジつきフォント
			FTYPE_ANTIALIASING,				// アンチエイリアスフォント( 標準機能アンチエイリアス )
			FTYPE_ANTIALIASING_4X4,			// アンチエイリアスフォント( 4x4サンプリング )
			FTYPE_ANTIALIASING_8X8,			// アンチエイリアスフォント( 8x8サンプリング )
			FTYPE_ANTIALIASING_EDGE,		// アンチエイリアス＆エッジ付きフォント( 標準機能アンチエイリアス )
			FTYPE_ANTIALIASING_EDGE_4X4,	// アンチエイリアス＆エッジ付きフォント( 4x4サンプリング )
			FTYPE_ANTIALIASING_EDGE_8X8,	// アンチエイリアス＆エッジ付きフォント( 8x8サンプリング )

			FTYPE_COUNT
		};

		/// コンストラクタ
		clFont();
		/// デストラクタ
		~clFont();

		/*!
			@brief	初期化処理
		**/
		void Init();

		void SetCenter( bool flag ) { m_IsCenter = flag; }

		/*!
			@brief	フォント名設定
			@param[in]	name	設定するフォント名
		**/
		void SetName( const char* fName );

		/*!
			@brief	フォントサイズ設定(-1:デフォルト)
			@param[in]	size	設定するフォントサイズ
		**/
		void SetSize( int size );

		/*!
			@brief	フォントの太さ設定(0~9,-1:デフォルト)
			@param[in]	thick	設定するフォントの太さ
		**/
		void SetThick( int thick );

		/*!
			@brief	フォントタイプ設定
			@param[in]	type	設定するフォントタイプ
		**/
		void SetType( enFontType type );

		/*!
			@brief	フォントカラー設定
			@param[in]	color	設定するフォントカラー
		**/
		void SetColor( DWORD color );

		/*!
			@brief	影の有無設定
			@param[in]	flag	影の有無(trueならば、影有り)
		**/
		void SetShadow( bool flag );

		/*!
			@brief	描画文字列設定(printf式)
			@param[in]	pos		描画位置
			@param[in]	format	文字列のフォーマット
			@param[in]	...		文字列
		**/
		void Print( VECTOR2I pos, const char* format, ... );

		/*!
			@brief	デバッグ文字列描画用
			@param[in]	pos		描画位置
			@param[in]	format	文字列のフォーマット
			@param[in]	...		文字列
		**/
		static void DebugPrint( VECTOR2I pos, const char* fotmat, ... );

		/*!
			@brief	更新処理
		**/
		void Update();

		/*!
			@brief	描画処理
		**/
		void Draw();
};

#endif	// #ifndef __FONT_HPP__