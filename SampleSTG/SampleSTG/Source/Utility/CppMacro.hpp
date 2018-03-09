/*!
	@brief	C++�}�N���W
	@author	s.namizashi
**/

#ifndef __CPP_MACRO_HPP__
#define __CPP_MACRO_HPP__

#include <assert.h>

#ifdef	_DEBUG
/*!
	@brief	�A�T�[�g(����false�Ȃ�΁A��~)
	@param[in]	exp	��
**/
#define	SN_ASSERT(exp)	assert(exp)
/*!
	@brief	���b�Z�[�W�t���A�T�[�g
	@param[in]	exp	��
	@param[in]	msg	���b�Z�[�W
**/
#define SN_ASSERTM(exp, msg) assert(exp && msg)
#else
// �A�T�[�g
#define SN_ASSERT(exp)
// ���b�Z�[�W�t���A�T�[�g
#define SN_ASSERTM(exp, msg)
#endif

template <bool> struct StaticAssert;
template <> struct StaticAssert<true> {typedef int t;};
/*!
	@brief	�ÓI�A�T�[�g(����false�Ȃ�΁A�R���p�C���G���[)
	@param[in]	exp	��
**/
#define SN_STATIC_ASSERT(exp) typedef StaticAssert<(exp)>::t STATIC_ASSERTION_ERROR##__LINE__;

/*!
	@brief	���I�m�ۗ̈���(�|�C���^������)
	@param[in]	ptr	����A�h���X
**/
#define	SN_SAFE_DELETE(ptr)	if(ptr != NULL)	\
							{				\
								delete ptr;	\
								ptr = NULL;	\
							}
/*!
	@brief	���I�m�۔z��̈���(�|�C���^������)
	@param[in]	ptr	����A�h���X
**/
#define	SN_SAFE_DELETEA(ptr)	if(ptr != NULL)		\
								{					\
									delete []ptr;	\
									ptr = NULL;		\
								}

/*!
	@brief	�z��̗v�f�������߂�
	@param[in]	ary	�v�f�������߂�z��
**/
#define	SN_ELEMENTSOF(ary)	( sizeof(ary)/sizeof(ary[0]) )

/*!
	@brief	Degree��Radian
	@param[in]	ang	�ϊ�����p�x
**/
#define SN_DIGTORAD(ang)	( (float)ang * (float)(M_PI/180.0) )

#endif	// #ifndef __CPP_MACRO_HPP__
