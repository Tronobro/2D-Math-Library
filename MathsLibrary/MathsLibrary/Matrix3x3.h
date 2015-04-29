//////////////////////////////////////////////////////////////////////
//	File:			<Matrix3x3.h>
//	Author:			<Reginald Ashman
//	Date Created:	<1/11/14>
//	Brief:			<This a Matrix3x3 class for the maths library. It
//					 will be used for matrix transformations for 
//					 positioning objects in 2D space> 
//////////////////////////////////////////////////////////////////////
#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "Vector3.h"
#include "Vector2.h"

class Matrix3x3
{
public:
	Matrix3x3();
	Matrix3x3(const Matrix3x3& other);
	~Matrix3x3();

	//matrix is in row major order
	float matrix[3][3]; //16 bytes

	//builds and returns a new identity matrix
	static Matrix3x3 Identity();
	
	//builds and returns a new rotation matrix
	//static Matrix3x3 setupRotation(float Radians);
	static Matrix3x3 setupRotation(float Degrees);

	//builds and returns a new scale matrix
	static Matrix3x3 setupScale(Vector2 Scale);
	//static Matrix3x3 setupScale(float Scale);

	//builds and returns a new translation matrix
	static Matrix3x3 setupTranslation(Vector2 Translation);
	static Matrix3x3 setupTranslation(Vector3 Translation);

	//outputs to console
	void OutputToConsole();

	//transposes matrix and returns *this
	Matrix3x3& Transpose();//needs testing
	//builds and returns a new matrix that is the transpose of this matrix
	Matrix3x3 GetTranspose();

	Matrix3x3 GetInverse();	//Returns the inverse of the matrix

	Matrix3x3& Inverse();	//Replaces the matrix with its inverse
	
	Matrix3x3 operator +(const Matrix3x3& other);
	Matrix3x3 operator -(const Matrix3x3& other);
	Matrix3x3 operator *(const Matrix3x3& other);
    Vector3 operator *(const Vector3& other);

	Matrix3x3 operator*(const float& scalar);
	Matrix3x3& operator*=(const float& scalar);

	Matrix3x3& operator +=(const Matrix3x3& other);
	Matrix3x3& operator -=(const Matrix3x3& other);
	Matrix3x3& operator *=(const Matrix3x3& other);
	bool operator == (const Matrix3x3& other);
	bool operator != (const Matrix3x3& other);

	friend Matrix3x3 operator-(const Matrix3x3 &matrix);

private: 
	float GetDeterminant();	//Returns the determinant of the matrix
};
#endif
