////////////////////////////////////////////////////////////////////
//	File:			<Vector4.h>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<This a Vector4 class for the maths library it
//					 can hold 3D co-ordinates among other things>
////////////////////////////////////////////////////////////////////
#ifndef VECTOR4_H
#define VECTOR4_H
class Vector4
{
public:

	float x;
	float y;
	float z;
	float w;

	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(const Vector4& other);
	~Vector4();

	static Vector4 Zero();
	static Vector4 One(); 
	static float Distance(const Vector4& one, const Vector4& two);
	static float ToRadians(float degrees);
	static float ToDegrees(float radians);

	void OutputToConsole();
	float Magnitude();
	Vector4 GetNormal();
	float Dot(const Vector4 &other);
	//float AngleBetween(Vector4 &other);
	Vector4 Cross(Vector4 &other);

	//Overloads
	Vector4 operator=(const Vector4 &other);
	Vector4 operator+(const Vector4 &other);
	Vector4& operator+=(const Vector4 &other);
	Vector4 operator-(const Vector4 &other);
	Vector4& operator-=(const Vector4 &other);
	Vector4 operator*(const float &multiplier);
	Vector4& operator*=(const float &multiplier);
	Vector4 operator/(const float &multiplier);
	Vector4& operator/=(const float &multiplier);

private:
	Vector4 Normalise();
};
#endif

