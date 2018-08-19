#define _CRT_SECURE_NO_WARNINGS

#include "Application.h"

using namespace std;


void main()
{
	setlocale(0, "");
	Application app;
	app.start();
	cout << endl;
	system("pause");
}