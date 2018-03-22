/*!
@brief	�v���C���[�Ǘ��N���X hpp
@author	s.namizashi
**/

#ifndef __PLAYER_MANAGER_HPP__
#define __PLAYER_MANAGER_HPP__

#include "Include.h"

#include "player.h"

class CPlayerManager
{
private:
	int m_evasion;				//���������
	bool m_evasion_flag;		//����t���O
	int m_nodamage_movement;	//�_���[�W���󂯂��ɑ���������
	bool m_ndm_flag;			//�_���[�W���󂯂��ɂ�����܂Ői�ނ�true
	bool m_passflag;			//��x�ʂ�����
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

	void countEvasion(){ m_evasion++; };								//�ǉ�	
	float getNoDamageMovement(){ return m_nodamage_movement; };			//�ǉ�
	bool getNdmFalg(){ return m_ndm_flag; };							//�ǉ�
	void setNoDamageMovement(float ndm){ m_nodamage_movement = ndm; };	//�ǉ�
	void setNdmFalg(bool f){ m_ndm_flag = f; };							//�ǉ�
	void noDamageDistance();	//�ǉ�
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__