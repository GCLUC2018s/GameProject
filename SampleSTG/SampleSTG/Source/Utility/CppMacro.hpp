/*!
	@brief	C++マクロ集
	@author	s.namizashi
**/

#ifndef __CPP_MACRO_HPP__
#define __CPP_MACRO_HPP__

#include <assert.h>

#ifdef	_DEBUG
/*!
	@brief	アサート(式がfalseならば、停止)
	@param[in]	exp	式
**/
#define	SN_ASSERT(exp)	assert(exp)
/*!
	@brief	メッセージ付きアサート
	@param[in]	exp	式
	@param[in]	msg	メッセージ
**/
#define SN_ASSERTM(exp, msg) assert(exp && msg)
#else
// アサート
#define SN_ASSERT(exp)
// メッセージ付きアサート
#define SN_ASSERTM(exp, msg)
#endif

template <bool> struct StaticAssert;
template <> struct StaticAssert<true> {typedef int t;};
/*!
	@brief	静的アサート(式がfalseならば、コンパイルエラー)
	@param[in]	exp	式
**/
#define SN_STATIC_ASSERT(exp) typedef StaticAssert<(exp)>::t STATIC_ASSERTION_ERROR##__LINE__;

/*!
	@brief	動的確保領域解放(ポインタ初期化)
	@param[in]	ptr	解放アドレス
**/
#define	SN_SAFE_DELETE(ptr)	if(ptr != NULL)	\
							{				\
								delete ptr;	\
								ptr = NULL;	\
							}
/*!
	@brief	動的確保配列領域解放(ポインタ初期化)
	@param[in]	ptr	解放アドレス
**/
#define	SN_SAFE_DELETEA(ptr)	if(ptr != NULL)		\
								{					\
									delete []ptr;	\
									ptr = NULL;		\
								}

/*!
	@brief	配列の要素数を求める
	@param[in]	ary	要素数を求める配列
**/
#define	SN_ELEMENTSOF(ary)	( sizeof(ary)/sizeof(ary[0]) )

/*!
	@brief	Degree→Radian
	@param[in]	ang	変換する角度
**/
#define SN_DIGTORAD(ang)	( (float)ang * (float)(M_PI/180.0) )

#endif	// #ifndef __CPP_MACRO_HPP__
