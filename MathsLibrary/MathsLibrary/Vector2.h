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
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& other);
	~Vector2();

	float x;	//4 bytes
	float y;	//4 bytes

	static Vector2 Zero();	//Returns Vector2 with all values set to 0.0f

	static Vector2 One();	//Returns a Vector2 with all values set to 1.0f

	static float Distance(const Vector2& one, const Vector2& two);	//Calculates the magnitude between two Vector2s
	
	static float ToRadians(float degrees);
							//Converts degrees to radians

	static float ToDegrees(float radians);
							//Converts radians to degrees

	static Vector2 FromAngle(float degrees);
							//Creates a Vector2 based on an angle

	float Magnitude();		//Calculates the magnitude of the vector

	Vector2 GetNormal();	//Returns the normalised version of the vector

	float Dot(const Vector2 &other);	//Calculates the dot product between 2 vectors

	float AngleBetween(Vector2 &other);	//Finds the angle between two vectors

	void OutputToConsole();	//Outputs the Vector2 to the console
	 
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
	bool operator==(const Vector2 &other);
	bool operator!=(const Vector2 &other);

	friend Vector2 operator-(const Vector2 &vector);


private:
	Vector2 Normalise();

};
#endif
