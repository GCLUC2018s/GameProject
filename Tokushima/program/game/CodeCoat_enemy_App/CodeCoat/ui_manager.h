/*!
@brief	�G�Ǘ��N���X hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "ui.h"

class CUiManager
{
private:
	static CUiManager* mp_Instance;
	Ui *m_ui;	//��l���̃A�h���X
	/// �R���X�g���N�^
	CUiManager();
public:
	/// �f�X�g���N�^
	~CUiManager();

	static CUiManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init(Ui *ui);

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	��l���̃A�h���X�ԋp
	**/
	Ui* GetPlayerAdress() const;

	/*!
	@brief	�X�V����
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__