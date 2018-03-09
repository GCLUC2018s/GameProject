/*!
	@brief	画像描画クラス hpp
	@author	s.namizashi
**/

#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

class clImage
{
	private:
		VECTOR2F	m_Pos;			//!< 描画位置
		UVI			m_UV;			//!< UV値
		VECTOR2F	m_Center;		//!< 中心点位置
		VECTOR2F	m_Scale;		//!< スケール値
		COLOR4I		m_Color;		//!< カラー
		int			m_iHundle;		//!< ハンドル
		float		m_Angle;		//!< 回転値
		bool		m_IsTurn;		//!< 左右反転するかどうか

		/*!
			@brief	描画情報初期化
		**/
		void InitDrawInfo();
	public:
		/// コンストラクタ
		clImage();
		/// デストラクタ
		~clImage();

		/*!
			@brief	初期化処理
		**/
		void Init();

		/*!
			@brief	画像読み込み
			@param[in]	name	読み込む画像名
		**/
		void Load( const char* name );

		/*!
			@brief	描画位置設定
			@param[in]	x	X座標値
			@param[in]	y	Y座標値
		**/
		void SetPos( float x, float y );

		/*!
			@brief	UV設定
					ピクセルで指定する用(0～画像サイズ)
			@param[in]	sx	開始X座標
			@param[in]	sy	開始Y座標
			@param[in]	ex	終了X座標
			@param[in]	ey	終了Y座標
		**/
		void SetUV( int sx, int sy, int ex, int ey );

		/*!
			@brief	UV設定
					割合で指定する用(0.0f～1.0f)
			@param[in]	sx	開始X座標割合
			@param[in]	sy	開始Y座標割合
			@param[in]	ex	終了X座標割合
			@param[in]	ey	終了Y座標割合
		**/
		void SetUV( float sx, float sy, float ex, float ey );

		UVI GetUV() const;

		/*!
			@brief	中心点設定(タイプ指定用)
			@param[in]	type	設定する中心点タイプ
		**/
		void SetCenter( enDirection type );

		/*!
			@brief	中心点設定(位置指定用)
			@param[in]	x	X座標位置
			@param[in]	y	Y座標位置
		**/
		void SetCenter( int x, int y );

		/*!
			@brief	スケール値設定(個別指定用)
			@param[in]	x	X軸スケール値
			@param[in]	y	Y軸スケール値
		**/
		void SetScale( float x, float y );

		/*!
			@brief	スケール値設定(共通指定用)
			@param[in]	scl	スケール値
		**/
		void SetScale( float scl );

		/*!
			@brief	スケール値取得
			@return	スケール値
		**/
		VECTOR2F GetScale() const;

		/*!
			@brief	カラー設定(COLOR4I型用)
			@param[in]	color	設定するカラー
		**/
		void SetColor( COLOR4I color );

		/*!
			@brief	回転値設定(ラジアン指定用)
			@param[in]	rot	回転量
		**/
		void SetRotate( float rot );

		/*!
			@brief	回転値設定(ディグリー指定用)
			@param[in]	rot	回転値
		**/
		void SetRotate( int rot );

		/*!
			@brief	左右反転するかどうかを設定
			@param[in]	is_turn	trueならば左右反転
		**/
		void SetTurn( bool is_turn );

		/*!
			@brief	読み込んでいる画像解放
		**/
		void Release();

		/*!
			@brief	更新処理
		**/
		void Update();

		/*!
			@brief	描画処理
		**/
		void Draw();
};

#endif	// #ifndef __IMAGE_HPP__