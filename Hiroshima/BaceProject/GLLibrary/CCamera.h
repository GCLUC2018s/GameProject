/*!
 *	@brief		�J�����N���X
 *	5�̃J���������݂���B
 *�@�J�����g�J�����ɐݒ肵���r���[�s��Ń��f�����\�������B
 */
#pragma once

#include "CVector.h"
#include "CMatrix.h"
#include "CRect.h"
class CCamera {
private:
	CVector3D m_pos;	//�J�����̈ʒu
	CVector3D m_at;		//�����_
	CVector3D m_up;		//Up�x�N�g��
	CVector3D m_dir;	//�����iFront�x�N�g���j
	CMatrix m_mView;	//�J�����s��
	CMatrix m_mProj;	//�ˉe�s��
	float	m_whidth;	//�J�����̕�
	float	m_height;	//�@�V�@�@����
	static CCamera m_camera[5];
	static CCamera *m_pCurrent;
	CRect	m_screen;
public:

	/*!
		@brief	�J�����I�u�W�F�N�g���擾
		@param	num			[in] �擾����J�����̔ԍ�
		@retval	�J�����I�u�W�F�N�g�̃A�h���X
	**/
	static CCamera* GetCamera(int num=0);
	
	/*!
		@brief	���ݎg�p���Ă���J�����I�u�W�F�N�g���擾
		@retval	�J�����g�J�����I�u�W�F�N�g�̃A�h���X
	**/
	static CCamera* GetCurrent();

	/*!
		@brief	�g�p����J�����ɐݒ�
		@param	num			[in] �g�p����J�����̔ԍ�
		@retval�@����
	**/

	static void SetCurrent(int num);
	/*!
		@brief	�g�p����J�����ɐݒ�
		@param	p			[in] �g�p����J�����̃A�h���X
		@retval�@����
	**/
	static void SetCurrent(CCamera *p);
	/*!
		@brief	�R���X�g���N�^
		@retval�@����
	**/
	CCamera();
	/*!
		@brief	�J�����̕����擾
		@retval�@�J�����̕��@
	**/
	float GetWhidth();
	/*!
		@brief	�J�����̍������擾
		@retval�@�J�����̍����@
	**/
	float GetHeight();
	/*!
		@brief	�J�����̕��ƍ����ݒ�
		@param	w			[in] ��
		@param	h			[in] ����
		@retval�@�����@
	**/
	void SetSize(float w,float h);

	/*!
		@brief	�����J�����Ńr���[�s��
		@param	eye			[in] �ʒu
		@param	at			[in] �����_
		@param	up			[in] ��x�N�g��
		@retval�@�����@
	**/
	void LookAt(CVector3D &eye,CVector3D &at,CVector3D &up);

	/*!
		@brief	�ʒu�Ɖ�]�l�Ńr���[�s���ݒ�
		@param	pos			[in] �ʒu
		@param	rot			[in] ��]�l
		@retval�@�����@
	**/
	void SetTranseRot(CVector3D &pos,CVector3D &rot);
	/*!
		@brief	���f���s�񂩂�r���[�s���ݒ�
		@param	mtx			[in] ���f���s��
		@retval�@�����@
	**/
	void SetTranseRot(CMatrix &mtx);

	/*!
		@brief	�r���[�s��𒼐ڐݒ�
		@param	m			[in] �r���[�s��
		@retval�@�����@
	**/
	void SetMatrix(CMatrix &m);

	/*!
		@brief	�r���[�s����擾
		@retval�@�����@
	**/
	CMatrix GetMatrix();

	
	/*!
		@brief	�r���[�s����擾
		@retval�@�����@
	**/
	CMatrix GetBuilbordMatrix();
	
	/*!
		@brief	�J�����̈ʒu���擾
		@retval�@�J�����̈ʒu
	**/
	CVector3D GetPos();

	/*!
		@brief	�J�����̌������擾
		@retval�@�J�����̌���
	**/
	CVector3D GetDir();

	/*!
	@brief	�������e�s��p
	@param	fovy			[in] ����
	@param	aspect			[in] �A�X�y�N�g��
	@param	zNear			[in] �O�ʋ���
	@param	zFar			[in] �w�ʋ���
	@retval�@
	**/
	void Perspective(float fovy, float aspect, float zNear, float zFar);
	void Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
	/*!
		@brief	�ˉe�s��̐ݒ�
		@param	m			[in] �ˉe�s��
	**/
	void SetProjectionMatrix(CMatrix &m) {
		m_mProj = m;
	}
	/*!
		@brief	 �ˉe�s����擾
		@retval�@�ˉe�s��
	**/
	CMatrix GetProjectionMatrix() {
		return m_mProj;
	}

	void SetScreenRect(CRect r) {
		m_screen = r;
	}
	CRect GetScreenRect() {
		return m_screen;
	}
};