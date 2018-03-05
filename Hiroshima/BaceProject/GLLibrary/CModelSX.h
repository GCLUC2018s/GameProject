/*!
*	@brief	Xファイル（スタティックモデル）用モデルクラス
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
	@brief　Xファイル用モデルクラス
**/
class CModelSX : public CModel{
private:
	CSPoly		*m_poly;
	CMaterial	*m_material;
	int			m_materialNum;
public:
	/*!
		@brief	コンストラクタ

	**/
	CModelSX();
	/*!
		@brief	デストラクタ
				データの破棄はしない
	**/
	~CModelSX();
	
	/*!
		@brief	読み込み
		@retval true:成功　false:失敗
	**/
	bool Load(const char *filePath);
	
	/*!
		@brief	行列を指定して描画する
		@param	m				[in] ワールド行列
		@retval	無し
	**/
	void RenderM(CMatrix &m);
	
	/*!
		@brief	モデルデータを破棄する
		@retval	無し
	**/
	void Release();

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
	
	CMaterial *GetMaterial(int no,int mesh){
		return &m_material[no];
	}
};