#include "CRectangle.h"
void CRectangle::SetVer(float left, float right, float bottom, float top){
	mLeft = left;
	mRight = right;
	mBottom = bottom;
	mTop = top;
}
void CRectangle::Init(){

}
void CRectangle::Update(){

}
void CRectangle::Render(){
	if (!mEnabled){
		return;
	}
	else{
		glBegin(GL_QUADS);
		glVertex2f(mLeft, mTop);
		glVertex2f(mLeft, mBottom);
		//glVertex2f(mRight, mBottom);
		//glVertex2f(mLeft, mTop);
		glVertex2f(mRight, mBottom);
		glVertex2f(mRight, mTop);
		glEnd();
	}
}