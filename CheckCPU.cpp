//union联合体的存放顺序是先从低地址开始，
//如果是大端：低字节应该放在高地址处；
int check()//大端--0； 小端--1
{
	union W
	{
		int a;
		char b;
	}c;
	c.a = 1;
	return c.b == 1;
}
int check1()
{
	int num = 1;
	char *p = (char*)&num;
	if (*p == 1)
		return 0;//小端
	else
		return 1;//大端
}
