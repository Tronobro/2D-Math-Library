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

	float x;	//4 bytes
	float y;	//4 bytes
	float z;	//4 bytes
	float w;	//4 bytes

	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(const Vector4& other);
	~Vector4();

	static Vector4 Zero();	//Returns Vector4 with all values set to 0.0f

	static Vector4 One();	//Returns a Vector4 with all values set to 1.0f

	static float Distance(const Vector4& one, const Vector4& two);
							//Calulates the magnitude between two Vector4s

	static float ToRadians(float degrees);
							//Converts degrees to radians

	static float ToDegrees(float radians);
							//Converts radians to degrees

	void OutputToConsole();	//Outputs the Vector4 to the console

	float Magnitude();	//Calculates the magnitude of the vector

	Vector4 GetNormal();	//Returns the normalised version of the vector

	float Dot(const Vector4 &other);	//Calculates the dot product with another vector

	//float AngleBetween(Vector4 &other);

	Vector4 Cross(Vector4 &other);		//Calculates the cross product with another vector
										//Homogenus 3D vector

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
	bool operator==(Vector4 &other);
	bool operator!=(Vector4 &other);

private:
	Vector4 Normalise();	//Returns the normalised vector
};
#endif

