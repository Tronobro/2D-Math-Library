////////////////////////////////////////////////////////////////////
//	File:			<Vector2.h>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<This a Vector2 class for the maths library it
//					 can hold 2D co-ordinates among other things>
////////////////////////////////////////////////////////////////////
#ifndef VECTOR2_H
#define VECTOR2_H
class Vector2
{
public:
	Vector2(float x, float y);
	Vector2(const Vector2& other);
	~Vector2();

	float x;	//4 bytes
	float y;	//4 bytes

	static Vector2 Zero();
	static Vector2 One(); 
	static float Distance(const Vector2& one, const Vector2& two);	//Calculates the magnitude between two Vector2s
	//done
	static Vector2 FromAngle(float degrees);

	float Magnitude();
	Vector2 GetNormal();
	float Dot(const Vector2 &other);	//Calculates the dot product between 2 vectors
	float AngleBetween(Vector2 &other);

	void OutputToConsole();
	 
	//Overloads
	Vector2 operator=(const Vector2 & other);
	Vector2 operator+(const Vector2 &other);
	Vector2& operator+=(const Vector2 &other);
	Vector2 operator-(const Vector2 &other);
	Vector2& operator-=(const Vector2 &other);
	Vector2 operator*(const float &multiplier);
	Vector2& operator*=(const float &multiplier);
	Vector2 operator/(const float &multiplier);
	Vector2& operator/=(const float &multiplier);

private:
	Vector2 Normalise();
	float ToRadians(float degrees);
	float ToDegrees(float radians);
};
#endif
