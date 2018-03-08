#include"CRectangle.h"
void CRectangle::SetVertex(float left, float right, float bottom, float top){
	mLeft = left;
	mRight = right;
	mBottom = bottom;
	mTop = top;

}
void CRectangle::SetTexture(CTexture *t, float left, float right, float bottom, float top){
	mpTexture = t;
	uv[0] = left;
	uv[1] = right;
	uv[2] = bottom;
	uv[3] = top;
}
void CRectangle::Render(){
	glBegin(GL_TRIANGLES);
	glVertex2f(mLeft, mTop);
	glVertex2f(mLeft, mBottom);
	glVertex2f(mRight, mBottom);
	glVertex2f(mLeft, mTop);
	glVertex2f(mRight, mBottom);
	glVertex2f(mRight, mTop);
	glEnd();
}