#define _CRT_SECURE_NO_DEPRECATE 1
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int n = 0;
	int count;
	while (1)
	{
		count = 0;
		cin >> n;
		while (n)
		{
			if (n & 1 == 1)
				count++;
			n >>= 1;
		}
		cout <<"1µÄ¸öÊý£º"<< count << endl;
	}
	system("pause");
	return 0;
}