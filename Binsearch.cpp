//��һ����һ������������֮���ÿո�����
//�ڶ�������һ��������
//ʹ�ö��ֲ��ң���������������������±ꡣ
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