//////////////////////////////////////////////////////////////////
//	File:			<Vector3.cpp>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<The .cpp file for the Vector3 class> 
//////////////////////////////////////////////////////////////////
#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::Zero()
{
	return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::One()
{
	return Vector3(1.0f, 1.0f, 1.0f);
}

float Vector3::Distance(const Vector3& one, const Vector3& two)
{
	return sqrtf((two.x - one.x)*(two.x - one.x) + (two.y - one.y)*(two.y - one.y)+(two.z - one.z)*(two.z - one.z));
}

float Vector3::ToRadians(float degrees)
{
	return static_cast<float>((degrees/180)*3.14159);
}

float Vector3::ToDegrees(float radians)
{
	return static_cast<float>((radians/3.14159)*180);
}

float Vector3::Magnitude()
{
	double temp = sqrt((x*x)+(y*y)+(z*z));
	return static_cast<float>(temp);
}

Vector3 Vector3::Normalise()
{
	Vector3 normal(0.f, 0.f, 0.f);
	float mag = Magnitude();
	normal.x = x/mag;
	normal.y = y/mag;
	normal.z = z/mag;
	return normal;
}

Vector3 Vector3::GetNormal()
{
	return Normalise();
}

float Vector3::Dot(const Vector3 &other)
{
	float temp;
	temp = (x*other.x)+(y*other.y)+(z*other.z);
	return temp;
}

float Vector3::AngleBetween(Vector3 &other)
{
	if(x == other.x && y == other.y)
	{
		return 0.0f;
	}

	float angle = 0.0f;
	float dotProPerp = 0.0f;

	Vector3 one(this->GetNormal());
	Vector3 two(other.GetNormal());
	Vector3 perp(y, -x, 0.0f);

	angle = ToDegrees(acosf(one.Dot(two))); 
	dotProPerp = perp.GetNormal().Dot(two); 

	if(dotProPerp > 0)
	{
		return angle;
	}
	else if(dotProPerp < 0)
	{
		return angle+180;
	}
	else
	{
		//the vectors are pointing in the same direction
		return 0;
	}
}

Vector3 Vector3::Cross(Vector3 &other)
	//Returns the normalised cross product of two vectors. The normalised vector is orthogonal to the original two. i.e. perpendicular to both.
{
	Vector3 temp(0.0f, 0.0f, 0.0f);
	temp.x = (y*other.z) - (z*other.y);
	temp.y = (z*other.x) - (x*other.z);
	temp.z = (x*other.y) - (y*other.x);
	return temp.GetNormal();
}

Vector3 Vector3::operator=(const Vector3 &other)
{
	if(this == &other)
		return *this;

	if(&other != this)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

Vector3 Vector3::operator+(const Vector3 &other)
{
	Vector3 temp(0.f, 0.f, 0.f);
	temp.x = x + other.x;
	temp.y = y + other.y;
	temp.z = z + other.z;
	return temp;
}

Vector3& Vector3::operator+=(const Vector3 &other)
{
	*this = *this + other;
	return *this;
}

Vector3 Vector3::operator-(const Vector3 &other)
{
	Vector3 temp(0.f, 0.f, 0.f);
	temp.x = x - other.x;
	temp.y = y - other.y;
	temp.z = z - other.z;
	return temp;
}

Vector3& Vector3::operator-=(const Vector3 &other)
{
	*this = *this - other;
	return *this;
}

Vector3 Vector3::operator*(const int &multiplier)
{
	Vector3 temp(0.f, 0.f, 0.f);
	temp.x = x * multiplier;
	temp.y = y * multiplier;
	temp.z = z * multiplier;
	return temp;
}

Vector3& Vector3::operator*=(const int &multiplier)
{
	*this = *this * multiplier;
	return *this;
}

Vector3 Vector3::operator/(const int &multiplier)
{
	Vector3 temp(0.f, 0.f, 0.f);
	temp.x = x / multiplier;
	temp.y = y / multiplier;
	temp.z = z / multiplier;
	return temp;
}

Vector3& Vector3::operator/=(const int &multiplier)
{
	*this = *this / multiplier;
	return *this;
}