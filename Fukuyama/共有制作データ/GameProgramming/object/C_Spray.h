#ifndef C_SPRAY_H
#define C_SPRAY_H

#include "C_Object.h"

class C_Spray :public C_Object{
public:
	C_Spray() :C_Object(E_OBJ, eUDP_Object, eDWP_Object, 0, 0, 0)
	{
		//�摜�̑傫�����w��
		m_image.SetVertex(0, 30, 0, 30);
	}
private:
	C_Vector3 i_ShadowPos;           //�e�̈ʒu
	bool init;
	void Init();
	void Update();
	void Draw();
};

#endif