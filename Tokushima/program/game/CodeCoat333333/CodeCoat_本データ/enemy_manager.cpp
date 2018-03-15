#include "enemy_manager.h"
#include "bullet_manager.h"

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
		case 5: temp->SetHp(atoi(buf)); 
			temp->SetLive(true);
			break;
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

void CEnemyManager::Remove(CEnemy* enemy)
{
	auto itr = std::find(m_enemy_list.begin(), m_enemy_list.end(), enemy);
	m_enemy_list.erase(itr);
}


void CEnemyManager::Update(){
	/*clsDx();
	for (auto it = m_enemy_list.begin(); it != m_enemy_list.end(); it++){
		auto l_e_pos = (*it)->GetPos();
		printfDx("%f,%f\n", l_e_pos.getX(), l_e_pos.getY());
	}*/

	//当たり判定

	auto _bullet_list = CBulletManager::GetInstance()->GetBulletList();

	for (auto it = m_enemy_list.begin(); it != m_enemy_list.end(); ){
		for (auto it2 = _bullet_list.begin(); it2 != _bullet_list.end(); ){
			if ((*it2)->getWhoseBullet() == 0){
				if (IsHitCircle(ENEMY_COLLISION, BULLET_COLLISION, &CVector3D((*it)->GetPos().getX() + ENEMY_CENTER,(*it)->GetPos().getY(),(*it)->GetPos().getZ() + ENEMY_LOWER_SIZE)
					, &CVector3D((*it2)->getPos().getX() + BULLET_CENTER, (*it2)->getPos().getY(), (*it2)->getPos().getZ() + BULLET_CENTER)))
				{
					if ((*it)->GetLive() && (*it2)->GetLive()){
						//接触した弾丸を消す
						(*it2)->Kill();
						//敵の体力を減らし、体力が0以下になると削除する
						(*it)->SetHp((*it)->GetHp() - 1);
						if ((*it)->GetHp() <= 0){
							(*it)->SetLive(false);
						}
					}
					
				}
			}
			it2++;
		}
		it++;
	}


}

std::vector<CEnemy*> CEnemyManager::getEnemyList() const
{
	return m_enemy_list;
}


//void 