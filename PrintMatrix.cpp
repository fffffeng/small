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

		//只有一行(两种情况：矩阵本身只有一行 + 矩阵只会剩下一行需打印)
		if (x == end_row)
		{
			for (int i = y; i <= end_col; ++i)
				cout << a[x][i] << " ";
		}
		//只有一列(两种情况： 矩阵本身只有一列 + 矩阵只剩下一列需打印)
		else if (y == end_col)
		{
			for (int i = x; i <= end_row; ++i)
				cout << a[i][y] << " ";
		}
		else
		{
			int x1 = x;
			int y1 = y;
			//打印上面一行
			while (y1 != end_col)
				cout << a[x][y1++] << " ";
			//打印右面一列
			while (x1 != end_row)
				cout << a[x1++][end_col] << " ";
			//在打印下面一行
			while (y1 != y)
				cout << a[end_row][y1--] << " ";
			//在打印左面一列
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