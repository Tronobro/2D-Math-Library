//////////////////////////////////////////////////////////////////
//	File:			<Vector2.cpp>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<The .cpp file for the Vector2 class> 
//////////////////////////////////////////////////////////////////
#include "Vector2.h"
#include <cmath> 
#include <iostream>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
}

Vector2::~Vector2(void)
{
	
}

Vector2 Vector2::Zero()
{
	return Vector2(0.0f, 0.0f);
}

Vector2 Vector2::One()
{
	return Vector2(1.0f, 1.0f);
}

float Vector2::Distance(const Vector2& one, const Vector2& two)
{
	return sqrtf((two.x - one.x)*(two.x - one.x) + (two.y - one.y)*(two.y - one.y));
}

float Vector2::ToRadians(float degrees)
{
	return static_cast<float>((degrees/180)*3.14159);
}

float Vector2::ToDegrees(float radians)
{
	return static_cast<float>((radians/3.14159)*180);
}

Vector2 Vector2::FromAngle(float degrees)
{
	float radian = static_cast<float>(degrees / 180.0f * 3.14159);
	return Vector2(cos(radian), sin(radian));
}

float Vector2::Magnitude()
{
	double temp = sqrt((x*x)+(y*y));
	return static_cast<float>(temp);
}

Vector2 Vector2::Normalise()
{
	Vector2 normal(0.f, 0.f);
	float mag = Magnitude();
	normal.x = x/mag;
	normal.y = y/mag;
	return normal;
}

Vector2 Vector2::GetNormal()
{
	return Normalise();
}

float Vector2::Dot(const Vector2 &other)
{
	float temp;
	temp = (x*other.x)+(y*other.y);
	return temp;
}

float Vector2::AngleBetween(Vector2 &other)
{
	if(x == other.x && y == other.y)
	{
		return 0.0f;
	}

	float angle = 0.0f;
	float dotProPerp = 0.0f;

	Vector2 one(this->GetNormal());
	Vector2 two(other.GetNormal());
	Vector2 perp(y, -x);

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

void Vector2::OutputToConsole()
{
	std::cout << x << "\n"<< y << std::endl;
}

Vector2 Vector2::operator=(const Vector2 &other)
{
	if(this == &other)
		return *this;

	if(&other != this)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

Vector2 Vector2::operator+(const Vector2 &other)
{
	Vector2 temp(0.f, 0.f);
	temp.x = x + other.x;
	temp.y = y + other.y;

	return temp;
}

Vector2& Vector2::operator+=(const Vector2 &other)
{
	*this = *this + other;
	return *this;
}

Vector2 Vector2::operator-(const Vector2 &other)
{
	Vector2 temp(0.f, 0.f);
	temp.x = x - other.x;
	temp.y = y - other.y;
	return temp;
}

Vector2& Vector2::operator-=(const Vector2 &other)
{
	*this = *this - other;
	return *this;
}

Vector2 Vector2::operator*(const float &multiplier)
{
	Vector2 temp(0.f, 0.f);
	temp.x = x * multiplier;
	temp.y = y * multiplier;
	return temp;
}

Vector2& Vector2::operator*=(const float &multiplier)
{
	*this = *this * multiplier;
	return *this;
}

Vector2 Vector2::operator/(const float &multiplier)
{
	Vector2 temp(0.f, 0.f);
	temp.x = x / multiplier;
	temp.y = y / multiplier;
	return temp;
}

Vector2& Vector2::operator/=(const float &multiplier)
{
	*this = *this * multiplier;
	return *this;
}

bool Vector2::operator==(Vector2 &other)
{
	return x==other.x && y == other.y;
}

bool Vector2::operator!=(Vector2 &other)
{
	return x!=other.x || y != other.y;
}