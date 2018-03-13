/*!
@brief	�G�Ǘ��N���X hpp
@author	s.namizashi
**/

#ifndef __BULLET_MANAGER_HPP__
#define __BULLET_MANAGER_HPP__

#include "Include.h"

#include "bullet.h"

class CBulletManager
{
private:
	static CBulletManager* mp_Instance;
	std::vector<CBullet*> m_bullet_list;
	int			m_Elapsed;
	int m_img;
	/// �R���X�g���N�^
	CBulletManager();
public:
	/// �f�X�g���N�^
	~CBulletManager();

	static CBulletManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init();

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	�A�C�e������
	**/
	void Create(CVector2D* pos, CVector2D *vec, float fdist,int whose);
	/*!
	@brief �G�����X�g���珜�O
	**/
	void Remove(CBullet* bullet);

	/*!
	@brief	�e�̃��X�g�擾
	**/
	std::vector<CBullet*> GetBulletList() const;

	//�摜��Ԃ�
	int getImg();

	/*!
	@brief	�X�V����
	**/
	void Update();
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__