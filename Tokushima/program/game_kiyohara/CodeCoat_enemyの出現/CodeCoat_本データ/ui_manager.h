/*!
@brief	敵管理クラス hpp
@author	s.namizashi
**/

#ifndef __UI_MANAGER_HPP__
#define __UI_MANAGER_HPP__

#include "Include.h"

#include "ui.h"

class CUiManager
{
private:
	static CUiManager* mp_Instance;
	Ui *m_ui;	//主人公のアドレス
	/// コンストラクタ
	CUiManager();
public:
	/// デストラクタ
	~CUiManager();

	static CUiManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	初期化処理
	**/
	void Init(Ui *ui);

	/*!
	@brief	終了処理
	**/
	void Finish();

	/*!
	@brief	主人公のアドレス返却
	**/
	Ui* GetPlayerAdress() const;

	/*!
	@brief	更新処理
	**/
	void Update();
};

#endif __UI_MANAGER_HPP__// #ifndef __ENEMY_MANAGER_HPP__