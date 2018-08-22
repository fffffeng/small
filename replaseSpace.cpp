#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
//将字符串的空格替换成20%

string replaceSpace(string str, int length)
{
  if(str.size() < 1)
    return str;
  int count = 0;
  for(int i = 0; i < length; ++i)
  {
    if(isspace(str[i]))
      count++;
  }
  int newlen = length+2*count;
  str.resize(newlen);//注意此时需要增容
  for(int i = length; i >= 0; --i)
  {
    if(isspace(str[i]))
    {
      str[newlen--] = '0';
      str[newlen--] = '2';
      str[newlen--] = '%';
    }
    else 
    {
      str[newlen--] = str[i];
    }
  }
  return str;
}

int main()
{
 string str = "we are happy";
 cout<<replaceSpace(str,str.length()).c_str()<<endl;
  return 0; 
}
