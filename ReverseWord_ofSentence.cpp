#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
////逆置一个句子的单词；例如: i love you!   ----->you! love  i
//思路：1,逆置整个句子
 //     2,逆置每个单词


int main()
{
	vector<char> v;
	char ch = 0;

	while (ch != '\n')
	{
		scanf("%c", &ch);
		v.push_back(ch);
	}
	v[v.size() - 1] = 0;

	int begin = 0;
	int end = v.size() - 2;
	while (begin != end && begin != end + 1)
	{
		swap(v[begin++], v[end--]);
	}

	begin = 0;
	end = 0;
	int next_begin = 0;
	int i = 0;
	while (i < v.size())
	{
		if (v[i] == ' ' || v[i] == '\0')
		{
			begin = next_begin;
			end = i - 1;
			while (begin != end && begin != end + 1)
				swap(v[begin++], v[end--]);
			next_begin = i + 1;
		}
		i++;
	}
	for (i = 0; i < v.size(); ++i)
		cout << v[i];
	system("pause");
	return 0;
}