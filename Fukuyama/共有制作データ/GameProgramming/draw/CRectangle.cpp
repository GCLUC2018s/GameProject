#include"CRectangle.h"
#include"glut.h"

void CRectangle::Render(){
	if (!mEnabled) return;
	glBegin(GL_TRIANGLES);
	glVertex2d(mLeft, mTop);
	glVertex2d(mLeft, mBottom);
	glVertex2d(mRight, mBottom);
	glVertex2d(mLeft, mTop);
	glVertex2d(mRight, mBottom);
	glVertex2d(mRight, mTop);
	glEnd();
}

void CRectangle::SetVertex(float left, float right, float bottom, float top)
{
	mLeft = left;
	mRight = right;
	mBottom = bottom;
	mTop = top;
}