#pragma once
#include "GL.h"
#include "CMatrix.h"
namespace Utility {
	/*!
		@brief	Degree（度）をRadianに変換
		@param	d				[in] 角度
		@retval	Radianに変換された角度
	**/

	inline float DgreeToRadian(float d) {
		return (float)(d*M_PI / 180.0f);
	}
	inline float RadianToDgree(float d) {
		return (float)(d *180.0f/ M_PI);
	}
	/*!
		@brief	角度の正規化
		@param	a				[in] 角度
		@retval	-PI～PI
	**/

	inline float NormalizeAngle(float a) {
		if (a>M_PI) return (float)(a - M_PI * 2);
		else if (a<-M_PI) return (float)(a + M_PI * 2);
		return a;
	}
	/*!
		@brief	角度の差を取得
		@param	a			[in] 角度
		@param	b			[in] 角度
		@retval	aとbの角度の差
	**/

	inline float DiffAngle(float a,float b) {
		if(a*b < 0){
			if(fabsf(a)+fabsf(b) > M_PI) {
				if (b<0) a -= (float)M_PI * 2;
				else a+=(float)M_PI*2;
			}
		}
		return b-a;
	}
	/*!
		@brief	乱数取得
		@param	min				[in] 最低値
		@param	max				[in] 最大値
		@retval	最低値～最大値の乱数
	**/

	template <typename T> inline T Rand(T min,T max) {
		return min + ((max-min) * rand()/ RAND_MAX);
	}
	/*!
		@brief	スクリーン座標変換→ワールド座標
		@param	out				[out] ワールド座標
		@param	spos			[in] スクリーン座標
		@param	mProj			[in] 射影行列
		@param	mView			[in] ビュー行列
		@param	w				[in] スクリーン幅
		@param	h				[in] スクリーン高さ
		@retval	無し
	**/
	void ScreenToWorld(CVector3D *out,CVector3D spos,CMatrix mProj,CMatrix mView,int w,int h);
	void ScreenToWorld(CVector3D *out, CVector3D spos);
	/*!
		@brief	ワールド座標→スクリーン座標変換
		@param	out				[out] スクリーン座標
		@param	wpos			[in] ワールド座標
		@param	mProj			[in] 射影行列
		@param	mView			[in] ビュー行列
		@param	w				[in] スクリーン幅
		@param	h				[in] スクリーン高さ
		@retval	無し
	**/
	void WorldToScreen(CVector3D *out, CVector3D wpos, CMatrix mProj, CMatrix mView, int w, int h);
	void WorldToScreen(CVector3D *out,CVector3D wpos);
	/*!
	@brief	線を引く
	@param	s				[in] 線分の始点
	@param	e				[in] 線分の終点
	@param	color			[in] 色
	@retval	無し
	**/
	void DrawLine(CVector2D &s, CVector2D &e, CVector4D &color);

	void DrawQuad(CVector2D &pos, CVector2D &size, CVector4D &color);


	void DrawLine(CVector3D &s, CVector3D &e, CVector4D &color);
	void DrawCube(CVector3D &pos, float size, CVector4D &color);
}