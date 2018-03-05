/*!
*	@brief	fieldファイル（シームレスマップ）用モデルクラス
*			ConvertField.exeでobjファイル→fieldファイルへコンバート
*
**/
#pragma once

#include "CModel.h"
#include <vector>
#if _MSC_VER < 1600
#include <process.h>
#else
#define USE_THREAD_CLASS
#include <thread>
#endif
//SFieldModelHeader
//meshOffset * ブロック数
//SMaterial * マテリアル数
//CMesh *　メッシュ数
//

struct SFieldMeshHeader {
	unsigned long *offSet;
};
struct SFieldModelHeader {
	char fileType[2];
	unsigned short verversion;
	unsigned long cutX;
	unsigned long cutZ;
	float			cutLength;
	unsigned long	colCut;
	float			colCutLength;
	CVector3D	min;
	CVector3D	max;
	unsigned long meshHeaderOffset;
	unsigned long materialCnt;
	unsigned long materialOffset;
};

class SFieldMaterial {
public:
	char m_name[128];
	char m_texName[128];
	CVector4D m_ambient;	//アンビエントカラー
	CVector4D m_diffuse;	//デフューズカラー
	CVector3D m_specular;	//スペキュラーカラー
	CVector3D m_emissive;	//自己発光
	float m_shininess;		//スペキュラー係数
	SFieldMaterial(){
		memset(this, 0, sizeof(SFieldMaterial));
	}
};
struct SFieldVertex {
	CVector3D		m_vertex;
	CVector3D		m_normal;
	CVector2D		m_texcode;

};
struct CFieldColIndex {
	unsigned long m_size;
	unsigned long *m_idx;
	CFieldColIndex() :m_idx(NULL){

	}
	~CFieldColIndex(){
		if (m_idx) delete m_idx;
	}
};
class CFieldPoly {
public:

	unsigned long	m_materialIdx;
	unsigned long	m_vertexCnt;
	SFieldVertex			*m_pVertex;
	unsigned long	m_cut;
	CFieldColIndex	*m_colIdx;
	CVector3D		*colNormal;

	unsigned long*	m_colmask;
	GLuint			m_buffer;
	CFieldPoly();
	~CFieldPoly();
	void Load(FILE *fp);
	void Render(CShader *shader);

	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength, int raws, int rawe, int cols, int cole);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt, int raws, int rawe, int cols, int cole);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt, int raws, int rawe, int cols, int cole);

};
class CFieldMesh {
public:
	bool		m_load;
	CVector3D		m_min;
	CVector3D		m_max;
	unsigned long m_polyCnt;
	CFieldPoly*		m_poly;
	CFieldMesh() :m_load(false),m_poly(NULL){
		m_polyCnt = 0;
	}
	~CFieldMesh() {
		Release();
	}
	void Load(FILE *fp);
	void Render(CShader *shader, int matNo);
	void Release();

	bool CollisionRay(CVector3D *c, CVector3D *n, const CVector3D &s, const CVector3D &e, float *pLength, const SFieldModelHeader &header);
	int CollisionSphere(CCollTriangle *out, const CVector3D &center, float radius, int maxcnt, const SFieldModelHeader &header);
	int CollisionCupsel(CCollTriangle *out, const CVector3D &top, const CVector3D &bottom, float radius, int maxcnt, const SFieldModelHeader &header);

};


class CModelField : public CModel {
	SFieldModelHeader m_header;
	SFieldMeshHeader m_offSet;
	char			m_fileName[256];
	CVector3D		m_center;
	int				m_posX;
	int				m_posZ;

	int				m_minX;
	int				m_maxX;
	int				m_minZ;
	int				m_maxZ;

	int				m_OldminX;
	int				m_OldmaxX;
	int				m_OldminZ;
	int				m_OldmaxZ;
	float			m_length;
	CMaterial		*m_pMaterial;
	int				m_materialCnt;
	CFieldMesh		*m_pMesh;
	FILE *m_fp;
	int				m_raw;
	int				m_col;

	bool			m_isRender;
	bool			m_isLoading;
	bool			m_isDestroy;
#ifdef USE_THREAD_CLASS
	std::thread		*m_pLoadThread;
#else
	HANDLE			m_threadHandle;
	static void		_loadThread(void *arg) {
		((CModelField*)arg)->LoadMeshProc();
	}

#endif


	/*
	@brief	一区画の頂点データを読み込む
	@param	x					[in] 区画位置横
	@param	z					[in] 区画位置奥
	@retval	成功true 失敗false
	*/
	bool	LoadMesh(int x, int z);


	int GetIdx(int x, int z) {
		return x + z*m_header.cutX;
	}
	void CalcRenderRange();
public:
	/*!
	@brief	コンストラクタ
	**/
	CModelField();

	/*!
	@brief	デストラクタ
	**/
	~CModelField();

	/*!
	@brief	fieldファイルからモデルデータを読み込む
	@param	path				[in] ファイル名
	@retval	成功true 失敗false
	**/
	bool	Load(const char *path);

	/*!
	@brief	描画を行う
	@param	m				[in] ワールド行列
	@retval	無し
	**/
	void	RenderM(CMatrix &m);

	/*!
	@brief	モデルデータを破棄する
	@retval	無し
	**/
	void	Release();
	void SetDrawLength(float l) {
		m_length = l;
	}
	CMaterial	*GetMaterial(int no, int ) {
		return &m_pMaterial[no];
	}
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


	void		LoadMeshProc();
};