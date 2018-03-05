/*!
*	@brief	X�t�@�C���i�X�^�e�B�b�N���f���j�p���f���N���X
*
*
**/


#pragma once
#include "CXSModelLoader.h"
#include "CModel.h"
#include "CTexture.h"
#include "CShader.h"
#include "CCollision.h"

class CSPoly {
	int			m_vertexCnt;
	bool		m_useNormal;
	bool		m_useTex;
	GLuint		m_buffer[3];
public:
	~CSPoly();
	void create(CXSModelLoader &loader,int materialNo);
	void draw(CShader *s);
	bool rayTest(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength);
	int	sphereTest(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt);
	int	cupselTest(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt);


};
#define POLY_CUT 5

/*!
	@brief�@X�t�@�C���p���f���N���X
**/
class CModelSX : public CModel{
private:
	CSPoly		*m_poly;
	CMaterial	*m_material;
	int			m_materialNum;
public:
	/*!
		@brief	�R���X�g���N�^

	**/
	CModelSX();
	/*!
		@brief	�f�X�g���N�^
				�f�[�^�̔j���͂��Ȃ�
	**/
	~CModelSX();
	
	/*!
		@brief	�ǂݍ���
		@retval true:�����@false:���s
	**/
	bool Load(const char *filePath);
	
	/*!
		@brief	�s����w�肵�ĕ`�悷��
		@param	m				[in] ���[���h�s��
		@retval	����
	**/
	void RenderM(CMatrix &m);
	
	/*!
		@brief	���f���f�[�^��j������
		@retval	����
	**/
	void Release();

	/*!
		@brief	�����ƃ��f���̔���
		@param	c				[out] �ڐG�n�_
		@param	s				[in] �����̊J�n�n�_
		@param	e				[in] �����̏I���n�_
		@retval	true:�ڐG�@false:��ڐG
	**/
	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e);
	
	/*!
		@brief	���ƃ��f���̔���
		@param	out				[out] �ڐG�f�[�^
		@param	center			[in] ���̒��S
		@param	radius			[in] ���̔��a
		@retval	�ڐG�|���S����
	**/
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt = 1);

	
	
	/*!
		@brief	�J�v�Z���ƃ��f���̔���
		@param	out				[out] �ڐG�f�[�^
		@param	top				[in] �J�v�Z���̓V��
		@param	bottom			[in] �J�v�Z���̒�
		@param	radius			[in] ���̔��a
		@retval	�ڐG�|���S����
	**/
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt = 1);
	
	CMaterial *GetMaterial(int no,int mesh){
		return &m_material[no];
	}
};