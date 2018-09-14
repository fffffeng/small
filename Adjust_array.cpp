#define _CRT_SECURE_NO_DEPRECATE 1

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
//-------------------------------------------------------
//输入一个数组，然后将数组元素中的所有奇数放在偶数前面---
//并且奇数从小到大的顺序，偶数从大到小；              ---
//-------------------------------------------------------
using namespace std;

static bool cmp(int a, int b)
{
	return a > b;
}

vector<int> fun(const vector<int>& v)
{
	vector<int> tmp;
	vector<int> res;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] % 2 == 0)
			tmp.push_back(v[i]);
		else
			res.push_back(v[i]);
	}
	sort(tmp.begin(), tmp.end(), cmp);
	sort(res.begin(), res.end());
	for (int i = 0; i < tmp.size(); ++i)
		res.push_back(tmp[i]);
	return res;
}

int main()
{
	vector<int> v;
	vector<int> tmp;
	vector<int> res;
	int data = 0;
	cin >> data;
	v.push_back(data);
	char ch = 0;
	while (ch = getchar() != '\n')
	{
		cin >> data;
		v.push_back(data);
	}
	res = fun(v);
	for (int i = 0; i < res.size() - 1; ++i)
		cout << res[i] << " ";
	cout << res[res.size() - 1] << endl;
	system("pause");

	return 0;
}
