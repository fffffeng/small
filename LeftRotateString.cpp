#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
//左旋字符串，比如adcXYZdef,左旋3位得：XYZdefabc
//解法：三步旋转法,将字符串看成2部分，abc和XYZdef
//1，cabXYZdef--(将abc旋转)
//2，cabfedZYX--(将剩下XYZdef旋转)
//3，XYZdefabc--(将整个字符串旋转)
string LeftRoatateString(string str,int n)
{
 if(str.size() < 1 || n < 1)
   return str;

 int len = str.length();
 int begin = 0;
 int end = n-1;
 while(begin < end)
   swap(str[begin++], str[end--]);
 begin = n;
 end = len-1;
 while(begin < end)
   swap(str[begin++],str[end--]);
 begin = 0; 
 end = len-1;
 while(begin < end)
   swap(str[begin++],str[end--]);

 return str;
}


int main()
{
  string str = "abcXYZdef";
  cout<<LeftRoatateString(str,3).c_str()<<endl;
  return 0;
}
