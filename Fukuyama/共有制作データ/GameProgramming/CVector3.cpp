#include "CVector3.h"

const C_Vector3 C_Vector3::operator + (const C_Vector3 &v){
	return C_Vector3(x + v.x, y + v.y, z + v.z);
}

const C_Vector3 C_Vector3::operator - (const C_Vector3 &v){
	return C_Vector3(x - v.x, y - v.y, z - v.z);
}

const C_Vector3 C_Vector3::operator * (const C_Vector3 &v){
	return C_Vector3(x * v.x, y * v.y, z * v.z);
}