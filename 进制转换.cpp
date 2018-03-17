#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
void Fun(int num)
{
	int k = 0;
	int a[4] = { 0 };
	while (num != 0)
	{
		a[k] = num % 8;
		k++;
		num /= 8;
	}
	cout << "Octal: ";
	for (int i = sizeof(a) / sizeof(a[0]) - 1; i >= 0; --i)
	{
		cout << a[i];
	}
}
int main()
{
	char str[3] = { 0 };
	int str2[4] = { 0 };
	int a = 0, b = 1;
	cin >> str;
	cout << "Hex: Ox" << str << endl;
	//十进制输出
	for (int i = strlen(str) - 1; i >= 0; --i)
	{
		if (str[i] >= 'A')
			a += (str[i] - 'A' + 10)*b;
		else
			a += (str[i] - '0')*b;
		b *= 16;
	}
	cout << "Decimal: " << a << endl;
	//8进制输出
	Fun(a);
	system("pause");
	return 0;
}