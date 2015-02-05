#include <iostream> 
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3x3.h"
using namespace std;
int main()
{
	Vector3 boop(2.0f, 2.0f, 0.0f);
	Vector3 beep(1.0f, 1.0f, 0.0f);
	Vector2 shoop(2.0f, 3.0f);
	Matrix3x3 matrix(Matrix3x3::Identity());

	boop.OutputToConsole();

	matrix.OutputToConsole();

	matrix *= Matrix3x3(Matrix3x3::setupTranslation(boop)); 

	matrix.OutputToConsole();

	matrix *= Matrix3x3(Matrix3x3::setupRotation(Vector3::ToRadians(20)));

	matrix.OutputToConsole();

	matrix *= Matrix3x3(Matrix3x3::setupScale(Vector2(3.0f, 3.0f)));

	matrix.OutputToConsole();

	(matrix*boop).OutputToConsole();

	shoop.OutputToConsole();
	//cout << boop.GetNormal().x << endl;
	//cout << boop.Dot(beep) << endl;
	//cout << beep.Dot(boop) << endl;
	//cout << beep.AngleBetween(boop) << endl;
	system("pause");
	return 0;
}