//第一输入一行整数，数字之间用空格间隔，
//第二行输入一个整数，
//使用二分查找，如果这个整数存在输出其下标。
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	int a = 0;
	int x = 0;
	char c = 0;
	cin >> a;
	v.push_back(a);
	while ((c = getchar()) != '\n')
	{
		cin >> a;
		v.push_back(a);
	}
	cin >> x;
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x>v[mid])
			left = mid + 1;
		else if (x < v[mid])
			right = mid - 1;
		else if (x == v[mid])
		{
			cout << mid;
			break;
		}
	}
	system("pause");
	return 0;
}