#define _CRT_SECURE_NO_DEPRECATE 1
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

class Buffer
{
public:
	Buffer(int size)
	{
		array = (char*)malloc(size);
		Size = 0;
		Capacity = size;
		for (int i = 0; i < Capacity; ++i)//缓冲区初始化为'\0'
			array[i] = '\0';
	}
	~Buffer()
	{
		free(array);
		array = NULL;
		Size = 0;
		Capacity = 0;
	}

	//从缓冲区读数据读到buf中
	char Read(char* buf, int read_size);
	//把buf中的数据写进缓冲区
	char Write(const char* buf, int write_size);

private:
	char* array;
	int Size;
	int  Capacity;
};

char Buffer::Read(char* buf, int read_size)
{
	int count = 0;
	if (read_size == 0||Size == 0)
		return count;
	int ret = Size;
	for (int i = 0; i < read_size; ++i)
	{
		if (i >= ret)
			break;
		buf[i] = array[i];
		--Size;
		++count;
	}
	return count;
}

char Buffer::Write(const char* buf, int write_size)
{
	int count = 0;
	if (write_size >= Capacity)
	{
		char* tmp = array;
		int new_Size = write_size;
		int new_Capacity = write_size;
		array = (char*)malloc(write_size);
		for (int i = 0; i < Size; ++i)
		{
			array[i] = tmp[i];
		}

		for (int i = Size; i < write_size; ++i)
		{
			array[i] = '\0';
		}
		free(tmp);
		tmp = NULL;
		Size = 0;
		Capacity = new_Capacity;
	}
	for (int i = 0; i < write_size; ++i)
	{
		array[i] = buf[i];
		++Size;
		++count;
	}
	return count;
}


int main()
{
	Buffer b(1024);
	char buf[] = "hello";
	char res[1024] = { '\0' };
	b.Write(buf, sizeof(buf) / sizeof(buf[0]));
	b.Read(res, 1024);
	b.Write(" world", 10);
	char res1[1024] = { '\0' };
	b.Read(res1, 1024);
	printf("%s\n", res1);

	system("pause");
	return 0;
}
