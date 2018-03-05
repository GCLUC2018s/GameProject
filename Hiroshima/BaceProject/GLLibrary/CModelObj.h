/*!
*	@brief	OBJ用モデルクラス
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
	CVector3D*	m_pVertexAry;		//頂点座標配列
	CVector3D*	m_pNormalAry;		//法線配列
	CVector2D*	m_pTexCoordAry;		//テクスチャーコード配列
	std::vector<int> *m_colIdex;
	int			m_vertexNum;		//頂点数
	CMaterial	m_material;		//マテリアルデータ
	char		m_materialname[128];	//マテリアル名
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
		@brief	OBJファイル用モデルクラス
**/
class CModelObj : public CModel {
private:
	
	CMeshObj *m_mesh;
	int		m_materialCnt;
	int		m_raw;
	int		m_col;
	/*!
		@brief	マテリアルデータの読み込み
		@param	path		[in]	ファイル名
		@retval	無し
	**/
	bool	LoadMaterial(char *path);
	bool	LoadBinary(const char *path);
public:

	/*!
		@brief	コンストラクタ
	**/
	CModelObj();

	/*!
		@brief	デストラクタ
	**/
	~CModelObj();

	/*!
		@brief	OBJファイルからモデルデータを読み込む
		@param	path				[in] ファイル名
		@retval	無し
	**/
	bool	Load(const char *path);


	/*!
	@brief	OBJファイルからモデルデータを読み込む
	@param	path				[in] ファイル名
	@param	raw					[in] X分割数
	@param	col					[in] Z分割数
	@retval	無し
	**/
	bool	Load(const char *path,int raw,int col);

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

	CMaterial	*GetMaterial(int no,int mesh) {
		return &m_mesh[no].m_material;
	}
	int GetMaterialNum() { 
		return m_materialCnt;
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


};