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

	static Vector3 Zero();	//Returns Vector3 with all values set to 0.0f

	static Vector3 One();	//Returns a Vector3 with all values set to 1.0f

	static float Distance(const Vector3& one, const Vector3& two);
							//Calculates the magnitude between two Vector3s

	static float ToRadians(float degrees);
							//Converts degrees to radians

	static float ToDegrees(float radians);
							//Converts radians to degrees

	void OutputToConsole();	//Outputs the Vector3 to the console

	float Magnitude();	//Calculates the magnitude of the vector

	Vector3 GetNormal();	//Returns the normalised version of the vector

	float Dot(const Vector3 &other);	//Calculates the dot product with another vector

	float AngleBetween(Vector3 &other);	//Finds the angle between two vectors

	Vector3 Cross(const Vector3 &other);		//Calculates the cross product with another vector

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
	bool operator==(const Vector3 &other);
	bool operator!=(const Vector3 &other);

	friend Vector3 operator-(const Vector3 &vector);

private:
	Vector3 Normalise();	//Calculates the normalised version of the vector
};
#endif
