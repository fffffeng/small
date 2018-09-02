#include <stdio.h>
#include<string>
#include<iostream>

using namespace std;
//有一种将字母编码成数字的方式：'a'->1, 'b->2', ... , 'z->26'。
//现在给一串数字，给出有多少种可能的译码结果。
//例如：12;输出：2( ab 和 l );
//--思路--：分为两种情况：1:单个数字字符对应一种；2：连续两个数字字符在1到26之间，
int numdecodings(const string& str)
{
  if(str.size() < 1 || str[0]=='0')
    return 0;
  //first表示加入第i个字符后的结果,
  int first = 1,second = 1;
  for(size_t i = 1; i < str.size(); ++i)//从下标为1的位置开始
  {
    if(str[i] == '0')
      first = 0;
    if((str[i-1] == '1' || str[i-1] == '2') && str[i] <='6')
    {
      first += second;
      first = first - second;
    }
    else 
      second = first;
  }
  return first;
}

int main()
{
  string str;
  getline(cin,str);
  cout<<numdecodings(str)<<endl;
  return 0;

}
