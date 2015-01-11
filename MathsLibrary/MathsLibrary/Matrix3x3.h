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

class Matrix3x3
{
public:
	Matrix3x3();
	~Matrix3x3();

	float matrix[3][3];

	//builds and returns a new identity matrix
	static Matrix3x3 Identity();
	//transposes matrix and returns *this
	Matrix3x3& Transpose();//needs testing
	//builds and returns a new matrix that is the transpose of this matrix
	Matrix3x3 GetTranspose();

	Matrix3x3 GetInverse();

	Matrix3x3& Inverse();//needs testing
	
	Matrix3x3 operator +(Matrix3x3& other);
	Matrix3x3 operator -(Matrix3x3& other);
	Matrix3x3 operator *(Matrix3x3& other);
    Vector3 operator *(Vector3& other);

	Matrix3x3& operator +=(Matrix3x3& other);
	Matrix3x3& operator -=(Matrix3x3& other);
	Matrix3x3& operator *=(Matrix3x3& other);

private: 
	float GetDeterminant();//needs testing
};
#endif
