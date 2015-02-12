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


	float x;	//4 bytes
	float y;	//4 bytes
	float z;	//4 bytes

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& other);
	~Vector3();

	static Vector3 Zero();
	static Vector3 One(); 
	static float Distance(const Vector3& one, const Vector3& two);
	static float ToRadians(float degrees);
	static float ToDegrees(float radians);

	void OutputToConsole();
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
	Vector3 operator*(const float &multiplier);
	Vector3& operator*=(const float &multiplier);
	Vector3 operator/(const float &multiplier);
	Vector3& operator/=(const float &multiplier);

private:
	Vector3 Normalise();
	
};
#endif
