#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void Fun(vector<vector<int>> a)
{
	if (a.size() == 0)
		return;
	int row = a.size();
	int col = a[0].size();
	int x = 0;
	int y = 0;
	int end_row = row - 1;
	int end_col = col - 1;
	while (x <= end_row&&y <= end_col)
	{

		//ֻ��һ��(���������������ֻ��һ�� + ����ֻ��ʣ��һ�����ӡ)
		if (x == end_row)
		{
			for (int i = y; i <= end_col; ++i)
				cout << a[x][i] << " ";
		}
		//ֻ��һ��(��������� ������ֻ��һ�� + ����ֻʣ��һ�����ӡ)
		else if (y == end_col)
		{
			for (int i = x; i <= end_row; ++i)
				cout << a[i][y] << " ";
		}
		else
		{
			int x1 = x;
			int y1 = y;
			//��ӡ����һ��
			while (y1 != end_col)
				cout << a[x][y1++] << " ";
			//��ӡ����һ��
			while (x1 != end_row)
				cout << a[x1++][end_col] << " ";
			//�ڴ�ӡ����һ��
			while (y1 != y)
				cout << a[end_row][y1--] << " ";
			//�ڴ�ӡ����һ��
			while (x1 != x)
				cout << a[x1--][y] << " ";
		}
		x++;
		y++;
		end_row--;
		end_col--;
	}
}

int main()
{
	vector<vector<int>> v;
	vector<int> a1 = { 1, 2, 3, 4 };
	vector<int> a2 = { 10, 11, 12, 5 };
	vector<int> a3 = { 9, 8, 7, 6 };
	v.push_back(a1);
	v.push_back(a2);
	v.push_back(a3);
	Fun(v);
	system("pause");
	return 0;
}