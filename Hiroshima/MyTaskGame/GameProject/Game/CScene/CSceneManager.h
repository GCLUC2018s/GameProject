#ifndef SCENE_MANAGER_GUARD
#define SCENE_MANAGER_GUARD

#include "../GameProject/Gamesource.h"
/*

制作者　宮﨑

*/

enum {
	eTitle,
	eMain,
	eBoss,
	eEnd,
	eNull,
};
class CSceneManager : public CTask
{
public:
	//この中の物は何も触らない
	CSceneManager(int scene);
	~CSceneManager();
	void SetSceneObject(int scene_num);
private:
	//タイトル画面に必要なものをこの中で生成
	void TitleScene();
	//メイン画面に必要なものをこの中で生成
	void MainScene();
	//ボス画面に必要なものをこの中で生成
	void BossScene();
	//エンド画面に必要なものをこの中で生成
	void EndScene();

};
#endif // !SCENE_MANAGER_GUARD
