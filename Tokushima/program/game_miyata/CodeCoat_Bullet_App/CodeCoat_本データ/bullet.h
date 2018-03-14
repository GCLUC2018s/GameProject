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
	CVector2D m_pos;					//���W
	CVector2D m_vec;
	float m_flying_time;				//�e�e����ԋ���
	int m_create_time;
	int m_whose;
public:
	void Update();
	void Draw();
	CBullet(CVector2D* pos,CVector2D* vec,float fdist,int whose);
	~CBullet();
	CVector2D GetPos()const{ return m_pos; }
};

#endif __BULLET_H__