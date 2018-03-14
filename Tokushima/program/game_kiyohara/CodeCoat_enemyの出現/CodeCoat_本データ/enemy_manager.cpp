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
	CEnemy *temp = new CEnemy();	//このnewはadd()が使用されない方
	FILE *fp;
	char buf[256];
	int c;
	int col = 1;		//Excel横
	int row = 0;		//Excel縦

	memset(buf, 0, sizeof(buf));
	fopen_s(&fp, "enemydata.csv", "r");

	if (fp == NULL) {
		printfDx("ファイルが開けません");
	}
	//ヘッダー読み飛ばし
	while (fgetc(fp) != '\n');

	while (1){

		while (1){

			c = fgetc(fp);

			//末尾ならループを抜ける
			if (c == EOF){
				goto out;
			}

			//カンマか改行でなければ、文字としてつなげる
			if (c != ','&&c != '\n')
				strcat_s(buf, (const char*)&c);
			//カンマか改行ならループ抜ける
			else
				break;
		}


		//ここに来たということは、1セル分の文字列が出来上がったということ
		switch (col)
		{
			//1列目は敵種類を表す。atoi関数(進数)で数値として代入
		case 1: temp->SetType(atoi(buf)); break;
			//2列目は座標x。以降省略
		case 2: temp->SetDistance(atoi(buf)); break;
		case 3: temp->SetPosX(atoi(buf)); break;
		case 4: temp->SetPosY(atoi(buf)); break;
		case 5: temp->SetHp(atoi(buf)); break;
		}
		//バッファを初期化
		memset(buf, 0, sizeof(buf));
		//列数を足す
		++col;

		//もし読み込んだ文字が改行だったら列数を初期化して行数を増やす
		//このnew CEnemyはaddが使われる方
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