//////////////////////////////////////////////////////////////////
//	File:			<Vector4.cpp>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<The .cpp file for the Vector4 class> 
//////////////////////////////////////////////////////////////////
#include "Vector4.h"
#include <cmath>
#include <iostream>

Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(const Vector4& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
}

Vector4::~Vector4()
{
}

Vector4 Vector4::Zero()
{
	return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}

Vector4 Vector4::One()
{
	return Vector4(1.0f, 1.0f, 1.0f, 1.0f);
}

float Vector4::Distance(const Vector4& one, const Vector4& two)
{
	return sqrtf((two.x - one.x)*(two.x - one.x) + (two.y - one.y)*(two.y - one.y)+(two.z - one.z)*(two.z - one.z)+(two.w - one.w)*(two.w - one.w));
}

float Vector4::ToRadians(float degrees)
{
	return static_cast<float>((degrees/180)*3.14159);
}

float Vector4::ToDegrees(float radians)
{
	return static_cast<float>((radians/3.14159)*180);
}

void Vector4::OutputToConsole()
{
	std::cout << x << "\n" << y << "\n" << z << "\n" << w << "\n" << std::endl;
}

float Vector4::Magnitude()
{
	double temp = sqrt((x*x)+(y*y)+(z*z)+(w*w));
	return static_cast<float>(temp);
}

Vector4 Vector4::Normalise()
{
	Vector4 normal(0.f, 0.f, 0.f, 0.f);
	float mag = Magnitude();
	normal.x = x/mag;
	normal.y = y/mag;
	normal.z = z/mag;
	normal.w = w/mag;
	return normal;
}

Vector4 Vector4::GetNormal()
{
	return Normalise();
}

float Vector4::Dot(const Vector4 &other)
{
	float temp;
	temp = (x*other.x)+(y*other.y)+(z*other.z)+(w*other.w);
	return temp;
}

//this needs to be modified for a vector4 functionality if possible
//float Vector4::AngleBetween(Vector4 &other)
//{
//	if(x == other.x && y == other.y)
//	{
//		return 0.0f;
//	}
//
//	float angle = 0.0f;
//	float dotProPerp = 0.0f;
//
//	Vector4 one(this->GetNormal());
//	Vector4 two(other.GetNormal());
//	Vector4 perp(y, -x, 0.0f);
//
//	angle = ToDegrees(acosf(one.Dot(two))); 
//	dotProPerp = perp.GetNormal().Dot(two); 
//
//	if(dotProPerp > 0)
//	{
//		return angle;
//	}
//	else if(dotProPerp < 0)
//	{
//		return angle+180;
//	}
//	else
//	{
//		//the vectors are pointing in the same direction
//		return 0;
//	}
//}

//this need to be implemented properly or deleted
Vector4 Vector4::Cross(const Vector4 &other)
	//Returns the normalised cross product of two vectors. The normalised vector is orthogonal to the original two. i.e. perpendicular to both.
{
	Vector4 temp(0.0f, 0.0f, 0.0f, 0.0f);
	temp.x = (y*other.z) - (z*other.y);
	temp.y = (z*other.x) - (x*other.z);
	temp.z = (x*other.y) - (y*other.x);
	return temp.GetNormal();
}

Vector4 Vector4::operator=(const Vector4 &other)
{
	if(this == &other)
		return *this;

	if(&other != this)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
	}
	return *this;
}

Vector4 Vector4::operator+(const Vector4 &other)
{
	Vector4 temp(0.f, 0.f, 0.f, 0.f);
	temp.x = x + other.x;
	temp.y = y + other.y;
	temp.z = z + other.z;
	temp.w = w + other.w;
	return temp;
}

Vector4& Vector4::operator+=(const Vector4 &other)
{
	*this = *this + other;
	return *this;
}

Vector4 Vector4::operator-(const Vector4 &other)
{
	Vector4 temp(0.f, 0.f, 0.f, 0.f);
	temp.x = x - other.x;
	temp.y = y - other.y;
	temp.z = z - other.z;
	temp.w = w - other.w;
	return temp;
}

Vector4& Vector4::operator-=(const Vector4 &other)
{
	*this = *this - other;
	return *this;
}

Vector4 Vector4::operator*(const float &multiplier)
{
	Vector4 temp(0.f, 0.f, 0.f, 0.f);
	temp.x = x * multiplier;
	temp.y = y * multiplier;
	temp.z = z * multiplier;
	temp.w = w * multiplier;
	return temp;
}

Vector4& Vector4::operator*=(const float &multiplier)
{
	*this = *this * multiplier;
	return *this;
}

Vector4 Vector4::operator/(const float &multiplier)
{
	Vector4 temp(0.f, 0.f, 0.f, 0.f);
	temp.x = x / multiplier;
	temp.y = y / multiplier;
	temp.z = z / multiplier;
	temp.w = w / multiplier;
	return temp;
}

Vector4& Vector4::operator/=(const float &multiplier)
{
	*this = *this / multiplier;
	return *this;
}

bool Vector4::operator==(const Vector4 &other)
{
	return x==other.x && y==other.y && z==other.z && w==other.w;
}

bool Vector4::operator!=(const Vector4 &other)
{
	return x!=other.x || y!=other.y || z!=other.z || w!=other.w;
}