#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "glut.h"
/*
TGAファイルのフォーマット
*/
struct STgaheader{
	unsigned char    dummy1[12];
	unsigned short   width;//幅
	unsigned short   height;//高さ
	unsigned char    depth;//ビットの深さ
	unsigned char    dummy2;
};

/*
テクスチャークラス
*/
class CTexture{
public:
	GLuint mId;
	STgaheader header;
	/*
	デフォルトコンストラクタ
	*/
	CTexture() :mId(0){}
	/*
	デストラクタ
	（このインスタンスが破棄されるときに実行される）
	*/
	~CTexture(){
		if (mId != 0){
			glDeleteTextures(1, &mId);
			mId = 0;
		}
	}
	/*
	画像ファイルの読み込み
	（テクスチャファイルの読み込み）
	*/
	void Load(const char* filename);

	void CTexture::DrawImage(int left, int right, int bottom, int top, float tleft, float tright, float tbottom, float ttop);
};

#endif