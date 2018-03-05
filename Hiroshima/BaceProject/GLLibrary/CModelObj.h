/*!
*	@brief	OBJ�p���f���N���X
*
*
**/
#pragma once
#include "GL.h"
#include "CTexture.h"
#include "CModel.h"
#include "vector"


struct SObjModelHeader {
	char fileType[2];
	unsigned short verversion;
	int		m_materialCnt;
	int		m_raw;
	int		m_col;
};



class CMeshObj {
public:
	CVector3D*	m_pVertexAry;		//���_���W�z��
	CVector3D*	m_pNormalAry;		//�@���z��
	CVector2D*	m_pTexCoordAry;		//�e�N�X�`���[�R�[�h�z��
	std::vector<int> *m_colIdex;
	int			m_vertexNum;		//���_��
	CMaterial	m_material;		//�}�e���A���f�[�^
	char		m_materialname[128];	//�}�e���A����
	CVector3D	m_max;
	CVector3D	m_min;
	int			m_col;
	int			m_raw;
	unsigned long *m_colmask;
	float		m_lenghX;
	float		m_lenghZ;
	GLuint		m_buffers[3];

	CMeshObj();
	void Render(CShader *shader);
	void Release();
	void CreatCollsionIndex(int raw,int col);
	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt);

	void LoadBinary(FILE *fp, const char *filepath);
};
/*!
		@brief	OBJ�t�@�C���p���f���N���X
**/
class CModelObj : public CModel {
private:
	
	CMeshObj *m_mesh;
	int		m_materialCnt;
	int		m_raw;
	int		m_col;
	/*!
		@brief	�}�e���A���f�[�^�̓ǂݍ���
		@param	path		[in]	�t�@�C����
		@retval	����
	**/
	bool	LoadMaterial(char *path);
	bool	LoadBinary(const char *path);
public:

	/*!
		@brief	�R���X�g���N�^
	**/
	CModelObj();

	/*!
		@brief	�f�X�g���N�^
	**/
	~CModelObj();

	/*!
		@brief	OBJ�t�@�C�����烂�f���f�[�^��ǂݍ���
		@param	path				[in] �t�@�C����
		@retval	����
	**/
	bool	Load(const char *path);


	/*!
	@brief	OBJ�t�@�C�����烂�f���f�[�^��ǂݍ���
	@param	path				[in] �t�@�C����
	@param	raw					[in] X������
	@param	col					[in] Z������
	@retval	����
	**/
	bool	Load(const char *path,int raw,int col);

	/*!
		@brief	�`����s��
		@param	m				[in] ���[���h�s��
		@retval	����
	**/
	void	RenderM(CMatrix &m);

	/*!
		@brief	���f���f�[�^��j������
		@retval	����
	**/
	void	Release();

	CMaterial	*GetMaterial(int no,int mesh) {
		return &m_mesh[no].m_material;
	}
	int GetMaterialNum() { 
		return m_materialCnt;
	}

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


};