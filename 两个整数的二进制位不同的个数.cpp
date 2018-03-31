#define _CRT_SECURE_NO_DEPRECATE 1
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int n, m,count;
	while (1)
	{
		cin >> n >> m;
		count = 0;
		while (n!=0||m!=0)
		{
			if ((n & 1 )!= (m & 1))
				count++;
			n >>= 1;
			m >>= 1;
		}
		cout << "不同的个数：" << count << endl;
	}
	system("pasue");
	return 0;
}