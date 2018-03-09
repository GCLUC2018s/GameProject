/*!
	@brief	入力判定クラス hpp
	@author	s.namizashi
**/

#ifndef __INPUT_MANAGER_HPP__
#define __INPUT_MANAGER_HPP__

#include "Source/Include.hpp"

class clInputManager
{
	private:
		static clInputManager* mp_Instance;

		bool	m_IsPushKey[IK_COUNT];	// 各キーの押下フラグ
		bool	m_IsJudgeKey[IK_COUNT];	// キー判定するかどうか

		/// コンストラクタ
		clInputManager();
	public:
		/// デストラクタ
		~clInputManager();

		static clInputManager* GetInstance();
		static void ClearInstance();

		void Init();

		/*!
			@brief	指定したキーを押しているかどうか
			@param[in]	type	キータイプ
			@return	trueならば押している
		**/
		bool IsOnKey( enKeyType type ) const;

		/*!
			@brief	指定したキーを押した瞬間かどうか
			@param[in]	type	キータイプ
			@retrun	trueならば押した瞬間
		**/
		bool IsPushKey( enKeyType type ) const;

		/*!
			@brief	更新処理
		**/
		void Update();
};

#endif	// #ifndef __INPUT_HPP__