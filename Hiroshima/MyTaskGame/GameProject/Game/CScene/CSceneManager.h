#ifndef SCENE_MANAGER_GUARD
#define SCENE_MANAGER_GUARD

#include "../GameProject/Source/Gamesource.h"
/*

制作者　宮﨑

*/

enum {
	eDebug,
	eGameStart,
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
private:
	//変更禁止。要望は宮﨑へ
	void SetSceneObject(int scene_num);

	//スタート画面に必要なものをこの中で生成
	void GameStartScene();
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
