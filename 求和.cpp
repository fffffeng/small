//求1+3+3+...+n；
//不能使用乘除法、循环、选择、条件判断等关键字
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//方法一，利用构造函数和静态变量
//class A
//{
//public:
//  A()
//  {
//    ++num;
//    sum+=num;
//  }
//
//  static void Reset()
//  {
//    num = 0;
//    sum = 0;
//  }
//
//  static int GetSum()
//  {
//    return sum;
//  }
//private:
//  static int num; 
//  static int sum;
//};
//
//int A::num = 0;
//int A::sum = 0;
//
//
//int main()
//{
//  A*a = new A[100];//构造函数100次
//  delete[] a;
//  a = 0;
//  //cout<<A::GetSum()<<endl;;
//  int ret = A::GetSum();
//  cout<<ret<<endl;
//  return 0;
//}


//方法二：递归
int GetSum(int n,int sum)
{
  sum+=n;
  if(n==0)
    return sum;
  else{
    GetSum(n-01,sum);
  }
}
int main()
{
  int sum = 0;
  cout<<GetSum(100,sum)<<endl;
  return 0;
}
