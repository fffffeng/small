#include<stdio.h>
#include<iostream>
#include<map>
//题目描述：
//输入一列整数表示选票，表示每个被选举人的id；找出票数最多的人的id。
//例如：1 5 2 3 1 2 2 4 2 2；票数最多的是2号；

int main()
{
	map<int, int> a;
	char c;
	int id = 0;
	pair<map<int, int>::iterator, bool> res;
	cin >> id;
	a.insert(pair<int, int>(id, 1));
	while ((c = getchar()) != '\n')
	{
		cin >> id;
		res = a.insert(pair<int, int>(id, 1));
		if (res.second == false)
		{
			++a[id];
		}
	}
	map<int, int>::iterator it = a.begin();
	int max = it->second;
	int res_id = it->first;
	while (it != a.end())
	{
		if ((it->second) > max)
		{
			max = it->second;
			res_id = it->first;
		}
		++it;
	}
	cout << res_id;
	system("pause");
	return 0;
}
