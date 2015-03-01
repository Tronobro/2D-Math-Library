//////////////////////////////////////////////////////////////////
//	File:			<Matrix3x3.cpp>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<The .cpp file for the Matrix 3x3 class> 
//////////////////////////////////////////////////////////////////
#include "Matrix3x3.h"
#include <cmath>
#include <iostream>

Matrix3x3::Matrix3x3()
{
	for(size_t i = 0; i<3; i++)
	{
		for(size_t j = 0; j<3; j++)
		{
			matrix[i][j] = 0.0f;
		}
	}
}

Matrix3x3::Matrix3x3(const Matrix3x3& other)
{
	for(size_t i = 0; i<3; i++)
	{
		for(size_t j = 0; j<3; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

Matrix3x3::~Matrix3x3()
{
}


Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 temp;
	temp.matrix[0][0] = 1.0f;
	temp.matrix[1][1] = 1.0f;
	temp.matrix[2][2] = 1.0f;
	return temp;
}

//builds and returns a new rotation matrix
//Matrix3x3 Matrix3x3::setupRotation(float Radians)
//{
//	Matrix3x3 temp(Identity());
//	temp.matrix[0][0] = cos(Radians);
//	temp.matrix[0][1] = -sin(Radians);
//	temp.matrix[1][0] = sin(Radians);
//	temp.matrix[1][1] = cos(Radians);
//
//	return temp;
//}

Matrix3x3 Matrix3x3::setupRotation(float Degrees)
{
	Matrix3x3 temp(Identity());
	float radians = Vector3::ToRadians(Degrees);
	temp.matrix[0][0] = cos(radians);
	temp.matrix[0][1] = -sin(radians);
	temp.matrix[1][0] = sin(radians);
	temp.matrix[1][1] = cos(radians);

	return temp;
}

//builds and returns a new scale matrix
Matrix3x3 Matrix3x3::setupScale(Vector2 Scale)
{
	Matrix3x3 temp(Identity());
	temp.matrix[0][0] = Scale.x;
	temp.matrix[1][1] = Scale.y; 

	return temp;
}

//Single scalar parameter
//Matrix3x3 Matrix3x3::setupScale(float Scale)
//{
//	Matrix3x3 temp(Identity());
//	temp.matrix[0][0] = Scale;
//	temp.matrix[1][1] = Scale; 
//	return temp;
//}

//builds and returns a new translation matrix
Matrix3x3 Matrix3x3::setupTranslation(Vector2 Translation)
{
	Matrix3x3 temp(Identity());
	temp.matrix[0][2] = Translation.x;
	temp.matrix[1][2] = Translation.y;

	return temp;
}

Matrix3x3 Matrix3x3::setupTranslation(Vector3 Translation)
{
	Matrix3x3 temp(Identity());
	temp.matrix[0][2] = Translation.x;
	temp.matrix[1][2] = Translation.y;

	return temp;
}

void Matrix3x3::OutputToConsole()
{
	for(size_t i = 0; i<3; i++)
	{
		std::cout <<matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << std::endl;
	}
	std::cout << std::endl; 
}

Matrix3x3& Matrix3x3::Transpose()
{
	*this = GetTranspose();
	return *this;
}

//builds and returns a new matrix that is the transpose of this matrix
Matrix3x3 Matrix3x3::GetTranspose()
{
	Matrix3x3 temp = *this;
	for(size_t rows = 0; rows<3; rows++)
	{
		for(size_t cols = 0; cols<3; cols++)
		{
			temp.matrix[rows][cols] = matrix[cols][rows];
		}
	}
	return temp;
}

Matrix3x3 Matrix3x3::GetInverse()
{
	float determinant = GetDeterminant();
	Matrix3x3 minors;
	Matrix3x3 cofactor;

	minors.matrix[0][0] = ((matrix[1][1]*matrix[2][2]) - (matrix[1][2]*matrix[2][1]));
	minors.matrix[0][1] = ((matrix[1][0]*matrix[2][2]) - (matrix[2][0]*matrix[1][2]));
	minors.matrix[0][2] = ((matrix[1][0]*matrix[2][1]) - (matrix[2][0]*matrix[1][1]));

	minors.matrix[1][0] = ((matrix[0][1]*matrix[2][2]) - (matrix[2][1]*matrix[0][2]));
	minors.matrix[1][1] = ((matrix[0][0]*matrix[2][2]) - (matrix[2][0]*matrix[0][2]));
	minors.matrix[1][2] = ((matrix[0][0]*matrix[2][1]) - (matrix[2][0]*matrix[0][1]));

	minors.matrix[2][0] = ((matrix[0][1]*matrix[1][2]) - (matrix[1][1]*matrix[0][2]));
	minors.matrix[2][1] = ((matrix[0][0]*matrix[1][2]) - (matrix[1][0]*matrix[0][2]));
	minors.matrix[2][2] = ((matrix[0][0]*matrix[1][1]) - (matrix[1][0]*matrix[0][1]));

	cofactor.matrix[0][0] = minors.matrix[0][0];
	cofactor.matrix[0][1] = -minors.matrix[0][1];
	cofactor.matrix[0][2] = minors.matrix[0][2];

	cofactor.matrix[1][0] = -minors.matrix[1][0];
	cofactor.matrix[1][1] = minors.matrix[1][1];
	cofactor.matrix[1][2] = -minors.matrix[1][2];

	cofactor.matrix[2][0] = minors.matrix[2][0];
	cofactor.matrix[2][1] = -minors.matrix[2][1];
	cofactor.matrix[2][2] = minors.matrix[2][2];

	cofactor.Transpose();

	for(size_t rows = 0; rows<3; rows++)
	{
		for(size_t cols = 0; cols<3; cols++)
		{
			cofactor.matrix[rows][cols] = cofactor.matrix[rows][cols]/determinant;
		}
	}
	return cofactor;
}

Matrix3x3& Matrix3x3::Inverse()
{
	*this = GetInverse();
	return *this;
}

Matrix3x3 Matrix3x3::operator +(const Matrix3x3& other)
{
	Matrix3x3 temp; 
	for(size_t i = 0; i<3; i++)
	{
		for(size_t j = 0; j<3; j++)
		{
			temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return temp;
}

Matrix3x3& Matrix3x3::operator +=(const Matrix3x3& other)
{
	*this = *this + other;
	return *this;
}

Matrix3x3 Matrix3x3::operator -(const Matrix3x3& other)
{
	Matrix3x3 temp; 
	for(size_t i = 0; i<3; i++)
	{
		for(size_t j = 0; j<3; j++)
		{
			temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}
	return temp;
}

Matrix3x3& Matrix3x3::operator -=(const Matrix3x3& other)
{
	*this = *this - other;
	return *this;
}

Matrix3x3 Matrix3x3::operator *(const Matrix3x3& other)
{
	Matrix3x3 temp;
	for(size_t j = 0; j<3; j++)
	{
		for(size_t i = 0; i<3; i++)
		{
			temp.matrix[j][i]
			= (matrix[j][0]*other.matrix[0][i])
				+ (matrix[j][1]*other.matrix[1][i])
				+ (matrix[j][2]*other.matrix[2][i]);
		}
	}
	return temp;
}

Matrix3x3& Matrix3x3::operator *=(const Matrix3x3& other)
{
	*this = *this * other;
	return *this;
}

Vector3 Matrix3x3::operator *(const Vector3& other)
{
	Vector3 temp(0.0f, 0.0f, 0.0f);	

	temp.x = (matrix[0][0]*other.x)+(matrix[0][1]*other.y)+(matrix[0][2]*other.z);
	temp.y = (matrix[1][0]*other.x)+(matrix[1][1]*other.y)+(matrix[1][2]*other.z);
	temp.z = (matrix[2][0]*other.x)+(matrix[2][1]*other.y)+(matrix[2][2]*other.z);

	return temp;
}

Matrix3x3 Matrix3x3::operator*(const float& scalar)
{
	Matrix3x3 temp(*this);
	for(size_t j = 0; j<3; j++)
	{
		for(size_t i = 0; i<3; i++)
		{
			temp.matrix[j][i]*=scalar;
		}
	}
	return temp;
}

Matrix3x3& Matrix3x3::operator*=(const float& scalar)
{
	*this = *this * scalar;
	return *this;
}

bool Matrix3x3::operator == (const Matrix3x3& other)
{
	return
		(matrix[0][0] == other.matrix[0][0]
	&& matrix[0][1] == other.matrix[0][1]
	&& matrix[0][2] == other.matrix[0][2]
	&& matrix[1][0] == other.matrix[1][0]
	&& matrix[1][1] == other.matrix[1][1]
	&& matrix[1][2] == other.matrix[1][2]
	&& matrix[2][0] == other.matrix[2][0]
	&& matrix[2][1] == other.matrix[2][1]
	&& matrix[2][2] == other.matrix[2][2]);
}

bool Matrix3x3::operator != (const Matrix3x3& other)
{
	return
		(matrix[0][0] != other.matrix[0][0]
	|| matrix[0][1] != other.matrix[0][1]
	|| matrix[0][2] != other.matrix[0][2]
	|| matrix[1][0] != other.matrix[1][0]
	|| matrix[1][1] != other.matrix[1][1]
	|| matrix[1][2] != other.matrix[1][2]
	|| matrix[2][0] != other.matrix[2][0]
	|| matrix[2][1] != other.matrix[2][1]
	|| matrix[2][2] != other.matrix[2][2]);
}

float Matrix3x3::GetDeterminant()
{
	float determinant = 0;
	determinant
		= (matrix[0][0]*matrix[1][1]*matrix[2][2])
		+ (matrix[0][1]*matrix[1][2]*matrix[2][0])
		+ (matrix[0][2]*matrix[1][0]*matrix[2][1])
		- (matrix[0][1]*matrix[1][0]*matrix[2][2])
		- (matrix[0][0]*matrix[1][2]*matrix[2][1])
		- (matrix[0][2]*matrix[1][1]*matrix[2][0]);
	return determinant;
}






