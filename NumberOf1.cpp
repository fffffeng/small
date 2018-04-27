#include<stdio.h>
#include<iostream>
using namespace std;

int counts_1(int n)
{
	//此方法有问题；当n时负数时会死循环。
	int res = 0;
	while (n)
	{
		if (n & 1)
			res++;
		n = n >> 1;
	}
	return res;
}

int counts_2(int n)
{
	//解决死循环
	int res = 0;
	int flag = 1;
	while (flag)
	{
		if (n & flag)
			res++;
		flag = flag << 1;
	}
	return res;
}

int counts_3(int n)
{
	//最优解法
	int res = 0;
	while (n)
	{
		res++;
		n = n&(n - 1);
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	cout << counts_1(n) << endl;
	cout << counts_2(n) << endl;
	cout << counts_3(n) << endl;
	system("pause");
}
