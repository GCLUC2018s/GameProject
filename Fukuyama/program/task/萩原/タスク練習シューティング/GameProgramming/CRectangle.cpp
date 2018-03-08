#include "CRectangle.h"

void CRectangle::Init(){
	tPlayer.Load("Image/Player.tga");
}

void CRectangle::SetVertex(int Left,int Right, int Bottom, int Top){
	mRight = Right;
	mLeft = Left;
	mBottom = Bottom;
	mTop = Top;
}