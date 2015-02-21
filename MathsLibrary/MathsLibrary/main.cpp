#include <iostream> 
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
using namespace std;
int main()
{
	Vector3 boop(2.0f, 2.0f, 0.0f);
	Vector3 beep(1.0f, 1.0f, 0.0f);
	Matrix3x3 matrix(Matrix3x3::Identity());
	Matrix3x3 matrix2(Matrix3x3::Identity());
	Vector2 broop(1.0f, 1.0f);
	Vector4 moop(1.0f, 1.0f, 1.0f, 1.0f);
	matrix*=Matrix3x3::setupTranslation(Vector3(100.0f, 100.0f, 0.0f));

	//matrix.OutputToConsole();
	if(matrix == matrix2)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	//(matrix*boop).OutputToConsole();
	//cout << boop.GetNormal().x << endl;
	//cout << boop.Dot(beep) << endl;
	//cout << beep.Dot(boop) << endl;
	//cout << beep.AngleBetween(boop) << endl;
	system("pause");
	return 0;
}