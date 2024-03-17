#include "Header.h"
#include <iomanip>
#include <iostream>
#include<cstdlib>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	do { cout << "Ведите N- размертость поля. Обратите внимание 2<=N<=10"; cin >> n; } while (n < 2 || n>10);
	system("color C");
	play(n);
	int a;
	cin >> a;
	return 0;
}