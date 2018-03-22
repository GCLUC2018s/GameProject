#ifndef __BULLET_H__
#define __BULLET_H__

//�w�b�_�[�t�@�C��
#include <DxLib.h>
#include <list>
#include "myLib.h"
#include "Task\CTask.h"

using namespace std;

//�萔
const int BULLET_SIZE = 20;
const float BULLET_CENTER = 10.0f;
const float BULLET_COLLISION = 15;

//�񋓑�
enum whose_number{ PLAYER = 0, ENEMY };

//��l���Ƀf�[�^��n���p�̃N���X(��)
/*class CItemData{
public:
	ItemType m_type;
	int m_img;
	ItemName m_name;
	int m_useful;			//�h��̏ꍇ�͑ϋv�l�A�A�C�e���̏ꍇ�͎c�莞�Ԃ�����
};*/

class CBullet : public CTask{
private:
	CVector3D m_pos;					//���W
	CVector3D m_vec;					//�ړ�����
	float m_flying_time;				//�e�e����ԋ���
	int m_create_time;					//���ꂽ�ۂ̎���
	int m_whose;						//�N�̒e�� Player or Enemy
	bool m_living;						//�����Ă��邩
public:
	void Update();
	void Draw();
	CBullet(CVector3D* pos,CVector3D* vec,float fdist,int whose);
	~CBullet();
	CVector3D getPos()const{ return m_pos; }
	int getWhoseBullet()const{ return m_whose; }
	void Kill(){ m_living = false; }
	bool GetLive()const{ return m_living; }
};

#endif __BULLET_H__