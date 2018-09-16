递归：

#include "stdio.h"
#include "stdlib.h"
 
bool fn(unsigned int x)      //判断x是否是4的幂次方
{
  if ( x & (x - 1) )         //判断x是否为2的幂次方
	  return false;
  return x & 0x55555555;     //判断1是否在奇数位置上
}
 
int log4(int value)      //递归判断一个数是4的多少次方
{
	if (value == 1)
		return 0;
	else
	{
		value>>=1;       //往右移位
		return 1+log4(value>>1);       //往右移位
	}
}
 
int main(void)
{
	int num;
	printf("请输入一个整数：");
	scanf("%d",&num);
	if(fn(num))     //使用与运算判断一个数是否是2的幂次方
		printf("%d是4的%d次方！\n",num,log4(num));
	else
		printf("%d不是4的幂次方！\n",num);
	system("pause");
	return 0;
}
