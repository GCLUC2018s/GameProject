#ifndef C_SCORE_H
#define C_SCORE_H
#include "object\C_Object.h"
#include "CCollider.h"
class C_Score{
public:
	void DrawString(int s[], float lef, float bot, float size);
	//�R���X�g���N�^��ݒ�
	C_Score();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�X�R�A�����Z����
	static int Score;
	//Texture�\��t��
	CTexture ScoreTexture;
	//Collision����
	bool Collision(CTask*, CTask*);
};
#endif