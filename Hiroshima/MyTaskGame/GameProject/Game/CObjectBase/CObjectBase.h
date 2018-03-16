#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#include "../GameProject/Task/CTask.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../GameProject/stdafx.h"
#include "../GameProject/ImageResource.h"

/*

»ì@{ú±

*/


class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//æIuWFNg
	CVector2D	m_pos2D;		//ÀW
	CVector2D	m_vec2D;		//Ú®Ê
	CVector3D	m_pos3D;		//ÀW
	CVector3D	m_vec3D;		//Ú®Ê
	CRect	m_rect_F;		//üêÖ¦»èpZ`
	CRect	m_rect;			//½è»èpZ`
	bool	m_flipH;		//½]tO
	bool	m_move;
	int		m_type;	
	static CVector2D m_scroll;	//XN[l
	static bool m_wave_flag;	//¡waveÈçtrueBGSÅ³¹½çfalseÉµÄAXN[Jn
	static 	bool m_sc_flag_x;	//vC[ª®¢½±ÆÉæéXN[tOBtrueÈçvC[Ì®«Í~Üé
	int m_hp;  //ÌÍ
	int m_at;  //UÍ
	int m_state; //óÔ
	CColorRGBA m_color;	//F
	//óÔ
	enum {
		eIdol,			//Ò@
		eAttack,		//U
		eKnockBack,    //mbNobN
		eFall,			//|êé
		eMove,         //Ú®
	};
public:
	CObjectBase(int id, int updatePrio, int drawPrio);
	////ÀWæ¾
	//CVector3D *GetPos() {
	//	return &m_pos3D;
	//};
	////é`æ¾
	//virtual CRect *GetRect() {
	//	return &m_rect;
	//};
	////üêÖ¦pé`æ¾
	//CRect *GetRect_F() {
	//	return &m_rect_F;
	//};

	//dÈèmF
	void CheckOverlap() {
		if(m_pos3D.z <= 0){
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_pos3D.z);
		}
	};

	//XN[lðæ¾

	////`æÊüêÖ¦
	//void SwapDrawPriority(CObjectBase *t);

	////`æ`FbNÖ
	//void CheckOverlapAll();
	//~CCharaBase();

	/*!
	@brief	lðwèlÜÅAwèlªã¸³¹é
	@param	v_Price_UF	[in] úl
	@param	v_Price_UE	[in] Åål
	@param	a			[in] l
	@retval	Ê
	**/
	float Price_Up(float v_Price_UF, float v_Price_UE, float a)
	{
		if (v_Price_UF < v_Price_UE)
			v_Price_UF += a;
		else v_Price_UF = v_Price_UE;

		return v_Price_UF;
	}
	/*!
	@brief	lðwèlÜÅAwèlªº~³¹é
	@param	v_Price_DF	[in] úl
	@param	v_Price_DE	[in] Å¬l
	@param	a			[in] ¸l
	@retval	Ê
	**/
	float Price_Down(float v_Price_DF, float v_Price_DE, float a)
	{
		if (v_Price_DF > v_Price_DE)
			v_Price_DF -= a;
		else v_Price_DF = v_Price_DE;

		return v_Price_DF;
	}
	//`æ½ß
	virtual void Draw();
	//½è»è
	void HitCheck(CTask * t1, CTask * t2);
	//½Á½Ì
	virtual void Hit(CTask *t);
	////dÈèmF
	//void CheckOverlap(CObjectBase *t1, CObjectBase *t2);
};


#endif // !CHARABASE_GUARD
