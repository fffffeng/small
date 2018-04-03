#include<stdio.h>
#include<iostream>
using namespace std;

//不用加减乘除四则运算计算两个数的和
int Add(int a,int b)
{
  int sum = 0;
  int ret = 0;
  do{
    sum = a^b;
    ret = (a&b)<<1;  //处理进位
    a = sum;
    b = ret;
  }while(ret != 0);
  return sum;
}
int main()
{
  cout<<Add(1,1)<<endl;
  return 0;
}
