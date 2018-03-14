/*!
@brief	�G�Ǘ��N���X hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "player.h"

class CPlayerManager
{
private:
	static CPlayerManager* mp_Instance;
	CPlayerControl *m_player;	//��l���̃A�h���X
	/// �R���X�g���N�^
	CPlayerManager();
public:
	/// �f�X�g���N�^
	~CPlayerManager();

	static CPlayerManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init(CPlayerControl *player);

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	��l���̃A�h���X�ԋp
	**/
	CPlayerControl* GetPlayerAdress() const;

	/*!
	@brief	�X�V����
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__