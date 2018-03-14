#include "enemy_manager.h"

CEnemyManager* CEnemyManager::mp_instance = nullptr;

CEnemyManager* CEnemyManager::getInstance(){
	if (mp_instance == nullptr)
	{
		mp_instance = new CEnemyManager();
	}
	return mp_instance;
}

void CEnemyManager::clearInstance(){
	if (mp_instance != nullptr)delete mp_instance;
}

CEnemyManager::CEnemyManager(){
	LoadFile();
}

void CEnemyManager::LoadFile(){
	CEnemy *temp = new CEnemy();	//����new��add()���g�p����Ȃ���
	FILE *fp;
	char buf[256];
	int c;
	int col = 1;		//Excel��
	int row = 0;		//Excel�c

	memset(buf, 0, sizeof(buf));
	fopen_s(&fp, "enemydata.csv", "r");

	if (fp == NULL) {
		printfDx("�t�@�C�����J���܂���");
	}
	//�w�b�_�[�ǂݔ�΂�
	while (fgetc(fp) != '\n');

	while (1){

		while (1){

			c = fgetc(fp);

			//�����Ȃ烋�[�v�𔲂���
			if (c == EOF){
				goto out;
			}

			//�J���}�����s�łȂ���΁A�����Ƃ��ĂȂ���
			if (c != ','&&c != '\n')
				strcat_s(buf, (const char*)&c);
			//�J���}�����s�Ȃ烋�[�v������
			else
				break;
		}


		//�����ɗ����Ƃ������Ƃ́A1�Z�����̕����񂪏o���オ�����Ƃ�������
		switch (col)
		{
			//1��ڂ͓G��ނ�\���Batoi�֐�(�i��)�Ő��l�Ƃ��đ��
		case 1: temp->SetType(atoi(buf)); break;
			//2��ڂ͍��Wx�B�ȍ~�ȗ�
		case 2: temp->SetDistance(atoi(buf)); break;
		case 3: temp->SetPosX(atoi(buf)); break;
		case 4: temp->SetPosY(atoi(buf)); break;
		case 5: temp->SetHp(atoi(buf)); break;
		}
		//�o�b�t�@��������
		memset(buf, 0, sizeof(buf));
		//�񐔂𑫂�
		++col;

		//�����ǂݍ��񂾕��������s��������񐔂����������čs���𑝂₷
		//����new CEnemy��add���g�����
		if (c == '\n'){
			CEnemy* enemy = new CEnemy(temp);
			col = 1;
			++row;
			m_enemy_list.push_back(enemy);
		}
	}

out:
	fclose(fp);
}

CEnemyManager::~CEnemyManager(){}

void CEnemyManager::Update(){
	clsDx();
	for (auto it = m_enemy_list.begin(); it != m_enemy_list.end(); it++){
		auto l_e_pos = (*it)->GetPos();
		printfDx("%f,%f\n", l_e_pos.getX(), l_e_pos.getY());
	}
}

//void 