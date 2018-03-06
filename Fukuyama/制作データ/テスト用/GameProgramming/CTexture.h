#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "glut.h"
/*
TGAファイルのヘッダフォーマット
*/
struct STgaheader{
	unsigned char dummy1[12];
	unsigned short width;//幅
	unsigned short height;//高さ
	unsigned char depth;//ビット深さ
	unsigned char dummy2;
};
/*
テクスチャクラス
*/
class CTexture{
public:
	//テクスチャID
	GLuint mId;
	//TGAファイルのヘッダ情報
	STgaheader header;
	/*
	デフォルトコンストラクタ
	*/
	CTexture() : mId(0) {}

	/*
	デストラクタ
	(このインスタンスが破棄されるときに実行される)
	*/
	~CTexture(){
		//テクスチャデータがあれば削除
		if (mId != 0){
			//テクスチャデータの削除
			glDeleteTextures(1, &mId);
			mId = 0;
		}
	}
	/*
	画像ファイルの読み込み
	(テクスチャファイルの読み込み)
	*/
	void Load(const char* filename);
};
#endif