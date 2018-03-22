#ifndef MAGATAMA_GUARD
#define MAGATAMA_GUARD

#include "../GameProject/Game/CObjectBase/CObjectBase.h"

/*

����@�Z��
�ҏW�@�{��

*/

#define MAGATAMA_POS_X 0
#define MAGATAMA_POS_Y 0

class CMagatama :public CObjectBase {
private:
	int m_cnt;
	CAnimImage m_img_max;

public:
	CMagatama();
	~CMagatama();
	void Update();
	void Draw();
	//�����������̏���
	void Hit(CObjectBase *t);
	//�K�E�Z����
	void SetAttack();
};

#endif // !MAGATAMA_GUARD