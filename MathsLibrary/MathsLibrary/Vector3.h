////////////////////////////////////////////////////////////////////
//	File:			<Vector3.h>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<This a Vector3 class for the maths library it
//					 can hold 2D co-ordinates among other things>
////////////////////////////////////////////////////////////////////
#ifndef VECTOR3_H
#define VECTOR3_H
class Vector3
{
public:


	float x;
	float y;
	float z;

	Vector3(float x, float y, float z);
	Vector3(const Vector3& other);
	~Vector3();

	static Vector3 Zero();
	static Vector3 One(); 
	static float Distance(const Vector3& one, const Vector3& two);

	float Magnitude();
	Vector3 GetNormal();
	float Dot(const Vector3 &other);
	float AngleBetween(Vector3 &other);
	Vector3 Cross(Vector3 &other);

	//Overloads
	Vector3 operator=(const Vector3 &other);
	Vector3 operator+(const Vector3 &other);
	Vector3& operator+=(const Vector3 &other);
	Vector3 operator-(const Vector3 &other);
	Vector3& operator-=(const Vector3 &other);
	Vector3 operator*(const int &multiplier);
	Vector3& operator*=(const int &multiplier);
	Vector3 operator/(const int &multiplier);
	Vector3& operator/=(const int &multiplier);

private:
	Vector3 Normalise();
	float ToRadians(float degrees);
	float ToDegrees(float radians);
};
#endif
