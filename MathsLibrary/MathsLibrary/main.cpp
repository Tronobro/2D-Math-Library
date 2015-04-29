#include <iostream> 
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
using namespace std;
int main()
{
	Vector3 boop(2, 2, 1.0f);
	Vector3 beep(10.0f, 10.0f, 1.0f);
	Matrix3x3 matrix(Matrix3x3::Identity());
	Matrix3x3 matrix2(Matrix3x3::Identity());
	Matrix3x3 rotate(Matrix3x3::Identity());
	Vector2 broop(1.0f, 1.0f);
	Vector4 moop(1.0f, 1.0f, 1.0f, 1.0f);

	Vector3 tl(-5.f, 5.f, 1.f);
	Vector3 bl(-5.f, -5.f, 1.f);
	Vector3 br(5.f, -5.f, 1.f);
	Vector3 tr(5.f, 5.f, 1.f);
	Vector3 origin(0.f, 0.f, 1.f);

	matrix*=Matrix3x3::setupTranslation(Vector3(100.0f, 100.0f, 0.0f));
	//matrix*=Matrix3x3::setupRotation(10.f);
	//matrix*=Matrix3x3::setupScale(Vector2(2.0f, 2.0f));
	(matrix).OutputToConsole();

	//matrix = matrix*matrix.GetInverse();
	//matrix.OutputToConsole();

	/*(matrix*tl).OutputToConsole();
	(matrix*bl).OutputToConsole();
	(matrix*br).OutputToConsole();
	(matrix*tr).OutputToConsole();
	(matrix*origin).OutputToConsole();*/

	//if(matrix == matrix2)
	//{
	//	cout << "yes" << endl;
	//}
	//else
	//{
	//	cout << "no" << endl;
	//}
	//(matrix*boop).OutputToConsole();
	//(matrix*beep).OutputToConsole();
	//cout << boop.GetNormal().x << endl;
	//cout << boop.Dot(beep) << endl;
	//cout << beep.Dot(boop) << endl;
	//cout << beep.AngleBetween(boop) << endl;


	//Creates sets up an identity matrix
	Matrix3x3 initial(Matrix3x3::Identity());

	//Multiplies the initial matrix by the translation matrix
	initial*=Matrix3x3::setupTranslation(Vector3(10.0f, 10.0f, 1.0f));

	//outputs initial to the console
	initial.OutputToConsole();

	//Creates a new matrix called inverse and sets it to the inverse
	//of initial
	Matrix3x3 inverse = initial.GetInverse();

	//Outputs the result of initial multiplied by inverse
	//to the console. If the inverse was properly calculated
	//result of the multiplication should be an Identity matrix.
	(initial*inverse).OutputToConsole();
	
	initial.OutputToConsole();
	system("pause");
	return 0;
}