#include <iostream> 
#include "Vector2.h"
#include "Vector3.h"
using namespace std;
int main()
{
	Vector3 boop(1.0f, 1.0f, 0.0f);
	Vector3 beep(1.0f, 1.0f, 0.0f);
	cout << boop.GetNormal().x << endl;
	//cout << boop.Dot(beep) << endl;
	//cout << beep.Dot(boop) << endl;
	cout << beep.AngleBetween(boop) << endl;
	system("pause");
	return 0;
}