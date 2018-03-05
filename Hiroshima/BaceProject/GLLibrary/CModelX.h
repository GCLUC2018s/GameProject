/*!
*	@brief	Xファイル（スキンメッシュモデル）用モデルクラス
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
  モデルの階層構造用クラス
  CXFrameをスキンメッシュ用に派生
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
  アニメーション管理クラス
  読み込んだアニメーション構造をそのまま使用
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
  マテリアルクラス
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
  各頂点に設定されたウェイト値を頂点毎にまとめるクラス
*/
class CSkinWeights {
public:
	SSkinWeight *weight;
public:
	CSkinWeights( CXModelLoader &loader, CXMesh &mesh);
	~CSkinWeights();
};
/*
  ポリゴンクラス
  マテリアル毎にまとめる
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
	  ローダーからポリゴンデータを構築
	*/
	CPoly( CXModelLoader &loader,  CXMesh &mesh,CSkinWeights *bone,int matNo);
	~CPoly();
	/*
	  描画
	*/
	void draw(CShader *shader);

	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius);

};
/*
  メッシュ毎のボーンオフセット行列を格納
*/
class CBoneOffset{
public:
	char transformNodeName[64];
	CMatrix matrixOffset;
	CBoneOffset(){
	}
	/*
	  SkinWeightsからボーン名とマトリックスのみを格納
	*/
	CBoneOffset(CXSkinWeights &s){
		strcpy_s(transformNodeName,sizeof(transformNodeName),s.transformNodeName);
		matrixOffset = s.matrixOffset;
	}

};
/*
  メッシュクラス
*/
class CMesh{
private:
	std::vector<CPoly*> polyList;
	std::vector<CBoneOffset*> boneList;
	CMatrix matrix;
public:
	/*
	  ローダーからメッシュデータを構築
	*/
	CMesh(CXModelLoader &loader,  CXMesh &mesh,CSkinWeights *bone);
	~CMesh();
	/*
	  描画
	*/
	void draw(std::vector<CMaterialX*> &materialList,CShader *shader,CFrameBone *pFrameRoot,CMatrix *boneMatrix,int boneNum);


	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius);
	friend class CModelX;

};

/*
  ｘファイル用モデルクラス
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
	  ローダーからモデルを構築
	*/
	bool Load(CXModelLoader &loader);
	/*
	  ファイルからモデルを構築
	*/
	bool Load(const char* filePath);
	/*
	  アニメーションを更新
	*/
	void UpdateAnimation();
	/*
	アニメーションを更新
	*/
	void UpdateAnimationMatrix();
	/*
	  アニメーションの終了を判定
	*/
	bool isAnimationEnd(){
		if(!animation) return true;
		return animation->isEnd();
	}
	/*
	  アニメーションの種類を取得
	*/
	int GetAnimationJam(){
		if(!animation) return true;

		return animation->GetJam();
	}
	/*
	　アニメーション速度の変更
	*/
	void SetAnimationSpeed(float s) {
		animation->SetSpeed(s);
	}
	/*!
	@brief	アニメーションの現在フレームを取得
	@retval	フレーム
	**/
	float GetAnimationFrame(){ 
		return 	animation->GetAnimationFrame();
	}

	/*
	  アニメーションを切り替える
	*/
	void ChangeAnimation(int jam, bool loop = true, bool check = true, int blendFrame = 5){
		if(!animation) return;
		animation->changeAnimation(jam,loop,check,blendFrame);
	}

	void attachAnimData(SAnimData *p) {
		animation->attachAnimData(p);
	}
	/*
	  描画
	*/
	void RenderM(CMatrix &m);

	/*
	　ボーンの行列を取得
	*/
	CMatrix GetFrameMatrix(const char *name,bool local=false);
	/*
	　ボーンの行列を取得
	*/
	CMatrix GetFrameMatrix(int no,bool local=false);


	/*
	　ボーンの補正行列を設定
	 */
	void SetFrameRevMatrix(const char *name, CMatrix &m);
	/*
	　ボーンの補正行列を設定
	 */
	void SetFrameRevMatrix(int no, CMatrix &m);


	CMaterial *GetMaterial(int no, int mesh);

	/*!
		@brief	線分とモデルの判定
		@param	c				[out] 接触地点
		@param	s				[in] 線分の開始地点
		@param	e				[in] 線分の終了地点
		@retval	true:接触　false:非接触
	**/
	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e);


	/*!
		@brief	球とモデルの判定
		@param	out				[out] 接触データ
		@param	center			[in] 球の中心
		@param	radius			[in] 球の半径
		@retval	接触ポリゴン数
	**/
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt = 1);



	/*!
		@brief	カプセルとモデルの判定
		@param	out				[out] 接触データ
		@param	top				[in] カプセルの天井
		@param	bottom			[in] カプセルの底
		@param	radius			[in] 球の半径
		@retval	接触ポリゴン数
	**/
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt = 1);

	friend class CModelX;
};