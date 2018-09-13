//..........
//01背包问题
//.........


int main()
{

	int w[5] = { 2, 2, 6, 5, 4 };
	int v[5] = { 6, 3, 5, 4, 6 };
	int bg = 10;
	int dp[6][11];
	int i, j;
	for (i = 0; i <= 5; i++)
		dp[i][0] = 0;
	for (j = 0; j <= 10; j++)
		dp[0][j] = 0;

	for (int i = 1; i < 6; ++i)
	{
		for (int j = 1; j < 11; ++j)
		{
			if (w[i-1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i-1]] + v[i-1]);
		}

	}

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << dp[4][10] << endl;
	system("pause");
	return 0;
}
