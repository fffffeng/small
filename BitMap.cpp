#define _CRT_SECURE_NO_DEPRECATE 1
#include<stdio.h>
#include<iostream>
using namespace std;

class BitMap
{
public:
	BitMap(size_t size = 10)//默认开辟10*4字节大小数组
	{
		array = (int*)malloc(sizeof(int)*size);
		Size = 0;
		Capcity = size;
		memset(array, 0, sizeof(int)*Capcity);
	}
	void Set(size_t num)//对现有数据num所对应的位置置1
	{
		size_t index = num >> 5;//等价于：num / 32
		size_t pos = num % 32;
		array[index] |= (1 << pos);
		++Size;
	}
	void Reset(size_t num)//把num对应位置重置
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		array[index] &= ~(1 << pos);
		--Size;
	}
	bool IsExist(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		if (array[index] &(1 << pos))
			return true;
		else
			return false;
	}
private:
	int *array;
	int Capcity;
	int Size;
};

//测试
int main()
{
	BitMap bp;
	bp.Set(1);
	bp.Set(3);
	bp.Set(10);
	bp.Set(5);
	bp.Set(33);
	bp.Set(555);
	cout << bp.IsExist(10) << endl;
	cout << bp.IsExist(555) << endl;
	cout << bp.IsExist(3) << endl;
	system("pause");
	return 0;
}
