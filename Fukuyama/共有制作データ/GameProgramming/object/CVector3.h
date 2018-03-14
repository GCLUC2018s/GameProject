#ifndef CVECTOR3_H
#define CVECTOR3_H

class C_Vector3{
public:

	C_Vector3()
		:x(0.0f)
		, y(0.0f)
		, z(0.0f)
	{}
	C_Vector3(float x, float y, float z)
		:x(x)
		, y(y)
		, z(z)
	{}

	float x, y, z;

	const C_Vector3 C_Vector3::operator + (const C_Vector3 &v);
	const C_Vector3 C_Vector3::operator - (const C_Vector3 &v);
	const C_Vector3 C_Vector3::operator * (const C_Vector3 &v);


};

#endif