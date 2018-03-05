/*!
*	@brief	X�t�@�C���i�X�L�����b�V�����f���j�p���f���N���X
*
*
**/
#pragma once

#include "GL.h"

#include "CXModelLoader.h"
#include "CTexture.h"
#include "CShader.h"


#include "Vertex.h"
#include "CModel.h"

class CMesh;
/*
  ���f���̊K�w�\���p�N���X
  CXFrame���X�L�����b�V���p�ɔh��
*/
class CFrameBone : public CXFrame{
private:
	CMatrix boneMatrix;
	CMatrix sMatrix;
	CMatrix matrixOffset;
	CMatrix blendMatrix;
	CMesh	*pMesh;
public:
	CFrameBone():CXFrame(){
	}
	CFrameBone(CXFrame &f){
		SetNo(f.GetNo());
		SetMatrix(f.GetMatrix());
		SetType(f.GetType());
		copyToken(f.GetToken());
		copyName(f.GetName());
	}
	CFrameBone(CFrameBone &f,CFrameBone *parent, CFrameBone *prev);
	CMatrix GetSMatrix(){
		return sMatrix;

	}
	void saveBlendMatrix() {
		blendMatrix = matrix;
	}
	void calcBlendMatrix(float r) {
		matrix = matrix*r + blendMatrix*(1-r);
	}
	void calcBoneMatrix(CMatrix *out);
	void calcMatrix(CMatrix *revMatrix);
	CMatrix GetMatrixOffset(){
		return matrixOffset ;
	}
	void seMatrixOffset(CMatrix mat){
		matrixOffset = mat;
	}

	friend class CModelX;
};
/*
  �A�j���[�V�����Ǘ��N���X
  �ǂݍ��񂾃A�j���[�V�����\�������̂܂܎g�p
*/
class CAnimation {

private:
	std::vector<CXAnimationSet*> *pAnimation;
	float time;
	int jam;
	float speed;
	bool loop;
	int endTime;
	CFrameBone *pBoneRoot;
	float blend;
	float blendS;
	SAnimData *pAnimData;
private:
	CMatrix calcMatrix(CXAnimationKey &key,float t);
public:
	CAnimation();
	CAnimation(std::vector<CXAnimationSet*> &a);
	~CAnimation();
	void Release();
	int GetEndTime(int j);
	void changeAnimation(int j,bool l = true,bool check=true,int blendFrame=5);
	void upDate();
	void updateMatrix();
	void saveBlendMatrix();
	bool isEnd(){
		if(time >= endTime-1.0f) return true;
		return false;
	}
	int GetJam() {
		return jam;
	}
	void SetSpeed(float s) {
		speed = s;
	}
	float GetAnimationFrame() {
		return time;
	}
	void attachFrame(CFrameBone *bone){
		pBoneRoot = bone;
	}
	void attachAnimData(SAnimData* p) {
		pAnimData = p;
	}
	
	friend class CModelX;
};
/*
  �}�e���A���N���X
*/
class CMaterialX : public CMaterial {

public:
	CMaterialX(CXMaterial &m,char *path);

};
struct SSkinWeight {
	SXVector4 bone;
	SXVector4 weight;
};


/*
  �e���_�ɐݒ肳�ꂽ�E�F�C�g�l�𒸓_���ɂ܂Ƃ߂�N���X
*/
class CSkinWeights {
public:
	SSkinWeight *weight;
public:
	CSkinWeights( CXModelLoader &loader, CXMesh &mesh);
	~CSkinWeights();
};
/*
  �|���S���N���X
  �}�e���A�����ɂ܂Ƃ߂�
*/
class CPoly{
public:
	MY_VERTEX  *m_pVertex;
	int			vertexCnt;
	int			faceCnt;
	bool		bNormal;
	bool		bTexCode;
	bool		bWeight;
	int			material;
	GLuint		buffer;
public:
	/*
	  ���[�_�[����|���S���f�[�^���\�z
	*/
	CPoly( CXModelLoader &loader,  CXMesh &mesh,CSkinWeights *bone,int matNo);
	~CPoly();
	/*
	  �`��
	*/
	void draw(CShader *shader);

	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius);

};
/*
  ���b�V�����̃{�[���I�t�Z�b�g�s����i�[
*/
class CBoneOffset{
public:
	char transformNodeName[64];
	CMatrix matrixOffset;
	CBoneOffset(){
	}
	/*
	  SkinWeights����{�[�����ƃ}�g���b�N�X�݂̂��i�[
	*/
	CBoneOffset(CXSkinWeights &s){
		strcpy_s(transformNodeName,sizeof(transformNodeName),s.transformNodeName);
		matrixOffset = s.matrixOffset;
	}

};
/*
  ���b�V���N���X
*/
class CMesh{
private:
	std::vector<CPoly*> polyList;
	std::vector<CBoneOffset*> boneList;
	CMatrix matrix;
public:
	/*
	  ���[�_�[���烁�b�V���f�[�^���\�z
	*/
	CMesh(CXModelLoader &loader,  CXMesh &mesh,CSkinWeights *bone);
	~CMesh();
	/*
	  �`��
	*/
	void draw(std::vector<CMaterialX*> &materialList,CShader *shader,CFrameBone *pFrameRoot,CMatrix *boneMatrix,int boneNum);


	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius);
	friend class CModelX;

};

/*
  ���t�@�C���p���f���N���X
*/
class CModelX : public CModel{
public:
	std::vector<CMesh*> *pMeshList;
	std::vector<CMaterialX*> *pMaterialList;
	CFrameBone *pFrameRoot;
	int			boneNum;
	CMatrix *boneMatrix;
	CMatrix *revMatrix;
	CAnimation *animation;
	void createFrame(CXFrame *xf, CFrameBone *f, int *num);
	void createMesh(CFrameBone *f, CXModelLoader &loader);
	void drawMesh(CFrameBone *f,CMatrix m);
public:
	CModelX();
	~CModelX();
	CModelX(const CModelX &m);
	void operator = (const CModelX &m);
	void Release();
	/*
	  ���[�_�[���烂�f�����\�z
	*/
	bool Load(CXModelLoader &loader);
	/*
	  �t�@�C�����烂�f�����\�z
	*/
	bool Load(const char* filePath);
	/*
	  �A�j���[�V�������X�V
	*/
	void UpdateAnimation();
	/*
	�A�j���[�V�������X�V
	*/
	void UpdateAnimationMatrix();
	/*
	  �A�j���[�V�����̏I���𔻒�
	*/
	bool isAnimationEnd(){
		if(!animation) return true;
		return animation->isEnd();
	}
	/*
	  �A�j���[�V�����̎�ނ��擾
	*/
	int GetAnimationJam(){
		if(!animation) return true;

		return animation->GetJam();
	}
	/*
	�@�A�j���[�V�������x�̕ύX
	*/
	void SetAnimationSpeed(float s) {
		animation->SetSpeed(s);
	}
	/*!
	@brief	�A�j���[�V�����̌��݃t���[�����擾
	@retval	�t���[��
	**/
	float GetAnimationFrame(){ 
		return 	animation->GetAnimationFrame();
	}

	/*
	  �A�j���[�V������؂�ւ���
	*/
	void ChangeAnimation(int jam, bool loop = true, bool check = true, int blendFrame = 5){
		if(!animation) return;
		animation->changeAnimation(jam,loop,check,blendFrame);
	}

	void attachAnimData(SAnimData *p) {
		animation->attachAnimData(p);
	}
	/*
	  �`��
	*/
	void RenderM(CMatrix &m);

	/*
	�@�{�[���̍s����擾
	*/
	CMatrix GetFrameMatrix(const char *name,bool local=false);
	/*
	�@�{�[���̍s����擾
	*/
	CMatrix GetFrameMatrix(int no,bool local=false);


	/*
	�@�{�[���̕␳�s���ݒ�
	 */
	void SetFrameRevMatrix(const char *name, CMatrix &m);
	/*
	�@�{�[���̕␳�s���ݒ�
	 */
	void SetFrameRevMatrix(int no, CMatrix &m);


	CMaterial *GetMaterial(int no, int mesh);

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

	friend class CModelX;
};