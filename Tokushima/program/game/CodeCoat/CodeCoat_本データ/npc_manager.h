/*!
@brief	�G�Ǘ��N���X hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "npc.h"

class CNpcManager
{
private:
	static CNpcManager* mp_Instance;
	CNpc *m_npc;	//npc�̃A�h���X
	/// �R���X�g���N�^
	CNpcManager();
public:
	/// �f�X�g���N�^
	~CNpcManager();

	static CNpcManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init(CNpc *npc);

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	npc�̃A�h���X�ԋp
	**/
	CNpc* GetNpcAdress() const;

	/*!
	@brief	�X�V����
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__