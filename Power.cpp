#include<stdio.h>
#include<iostream>
using namespace std;

double Power(double base,int exponent)
{

  double res = 1.0;
  if(base==0.0) //底数==0；
    return 0.0;
  else  //底数不为0
  {
    if(exponent==0) //底数不为0，指数为0；
      return 1.0;
    else if(exponent>0) //底数不为0，指数大于0；
    {
      for(int i=0;i<exponent;++i)
      {
        res*=base;
      }
    }
    else if(exponent<0) //底数不为0，指数小于0
    {
      for(int i = 0;i<-exponent;++i)
        res*=base;
      res = 1/res;
    }
  }

  return res;
}

int main()
{
  while(1)
  {
    double a ;
    double b ;
    cin>>a;
    cin>>b;
    cout<<Power(a,b)<<endl;
  }
  return 0;
}
