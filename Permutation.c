
//输入一个字符串，按照字典顺序打印出该字符串的所有排列。
//例如字符串abc;就应该打印出abc,acb,bac,bca,cab和cba；(把结果放在一个数组里)

//思路：
//--把字符串分为两部分；一部分：第一个字符；第二部分：第一个字符以后的部分；
//--然后求第二部分的排列；
//--然后再把第二部分看成一个字符串；也分成两部分，第一个字符和后面的字符串
//此时很容易想到用递归完成

vector<string> a;
void Permuta(string& str,int n)
{
	if(n==(int)str.length())
	{
		a.push_back(str);
		return;
	}
	else{
		for(int i = n;i<str.length();++i)
		{
			if(i!=n&&str[i]==str[n])
				continue;
			swap(str[n],str[i]);
			Permuta(str,n+1);
			swap(str[n],str[i]);
		}
	}
}
vector<string> Permutation(string str) {
	if(str.length()==0)
		return a;
	Permuta(str,0);
	sort(a.begin(),a.end());
	return a;
}