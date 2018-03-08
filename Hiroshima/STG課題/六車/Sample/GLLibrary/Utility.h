#pragma once
#include "GL.h"
#include "CMatrix.h"
namespace Utility {
	/*!
		@brief	Degree�i�x�j��Radian�ɕϊ�
		@param	d				[in] �p�x
		@retval	Radian�ɕϊ����ꂽ�p�x
	**/

	inline float DgreeToRadian(float d) {
		return (float)(d*M_PI / 180.0f);
	}
	inline float RadianToDgree(float d) {
		return (float)(d *180.0f/ M_PI);
	}
	/*!
		@brief	�p�x�̐��K��
		@param	a				[in] �p�x
		@retval	-PI�`PI
	**/

	inline float NormalizeAngle(float a) {
		if (a>M_PI) return (float)(a - M_PI * 2);
		else if (a<-M_PI) return (float)(a + M_PI * 2);
		return a;
	}
	/*!
		@brief	�p�x�̍����擾
		@param	a			[in] �p�x
		@param	b			[in] �p�x
		@retval	a��b�̊p�x�̍�
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
		@brief	�����擾
		@param	min				[in] �Œ�l
		@param	max				[in] �ő�l
		@retval	�Œ�l�`�ő�l�̗���
	**/

	template <typename T> inline T Rand(T min,T max) {
		return min + ((max-min) * rand()/ RAND_MAX);
	}

	/*!
	@brief	��������
	@param	s				[in] �����̎n�_
	@param	e				[in] �����̏I�_
	@param	color			[in] �F
	@retval	����
	**/
	void DrawLine(CVector2D &s, CVector2D &e, CVector4D &color);

	/*!
	@brief	��`�̕`��
	@param	pos				[in] �ʒu
	@param	size				[in] �傫��
	@param	color			[in] �F
	@retval	����
	**/
	void DrawQuad(CVector2D &pos, CVector2D &size, CVector4D &color);

	/*!
	@brief	�~�̕`��
	@param	pos				[in] �ʒu
	@param	size			[in] �傫��
	@param	color			[in] �F
	@retval	����
	**/
	void DrawCircle(CVector2D &pos, float size, CVector4D &color);
}