#include<stdio.h>
#include<iostream>
using namespace std;

//第一项F1 = 1,第二项F2 = 1,第三项F3 = F2+F1..........
int Fibinacci(int n)
{
	int a1 = 1, a2 = 1, fn = 0;
	if (n <= 2)
		return 1;
	for (int i = 3; i <= n; ++i)
	{
		fn = a1 + a2;
		a1 = a2;
		a2 = fn;
	}
	return fn;
}
int main()
{
	int n = 0, m = 0, p = 0;
	while (1)
	{
		cin >> n;
		cout << Fibinacci(n) << endl;
	}
	system("pause");
	return 0;
}