#include <stdio.h>
#include<iostream>
using namespace std;

//实现一个函数，匹配 '.'和'*'的正则表达式;'.'表示任意一个字符，'*'表示前面的字符出现任意次数

bool match(char* str, char* pattern)
{
  if(str[0] == '\0' && pattern[0] == '\0')//两个NULL字符串
    return true;
  else if(str[0] != '\0' && pattern[0] == '\0')//str不为空，pattern为空
    return false;
  if(pattern[1] == '*')//下一个字符是*
  {
    if(str[0]==pattern[0] ||(pattern[0] == '.'&&str[0] != '\0'))//例如ab,a*或者ab, .*的情况
      return match(str+1,pattern+1);
    return false;
  }
  else //下一个字符不是*
  {
    if(str[0] == pattern[0]||(pattern[0]=='.'&&str[0] != '\0'))//例如ab,ac ; 或者ab,.c
      return match(str,pattern+2)||match(str+1,pattern)||match(str+1,pattern+2);
    else 
      return match(str,pattern+2);
  }
}

int main()
{
  char* str="aaa";
  char* pattern="a.a";
  cout<<match(str,pattern)<<endl;
  return 0;

}
