#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#include "../GameProject/Task/CTask.h"

class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//画像オブジェクト
	CVector2D	m_pos;		//座標
	CVector2D	m_vec;		//移動量
	CRect	m_rect;			//当たり判定用短形
	bool	m_flipH;		//反転フラグ
	bool	m_active;		//生存フラグ
	bool	m_move;
	int		m_type;
	float	m_color;		//色
	static CVector2D m_scroll;
public:
	CObjectBase();
	//~CCharaBase();

private:
	//描画命令
	virtual void Draw();

};

#endif // !CHARABASE_GUARD
