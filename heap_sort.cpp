堆排序及TOK问题

void Adjustdown(int*a,int root,int n)
{
	int parent = i;
	int child = 2*i+1;
	while(child<n)
	{
		if(child+1<n&&a[child]>a[child+1])
			++child;
		if(a[parent]<a[child])
		{
			swap(a[parent],a[child])
			parint = child;
			child = 2*parent+1;
		}
		else
			break;
	}
}
void Head_sort(int *a,int n)
{
	//建大堆
	for(int i = (n-2)/2;i>=0;--i)
	{
		Adjustdown(a,i,n);
	}
	
	//调整(此时堆顶元素最大，)
	int end=n-1;
	while(end>0)
	{
		swap(a[0],a[end]);
		Adjustdown(a,0,end);
		--end;
	}
}


void Adjustdown(int *array,int root,int n)
{
	int parent = root;
	int child = 2*parent+1;
	while(child<n)
	{
		if(child+1<n&&array[child]<array[child+1])
		{
			++child;
		}
		if(array[parent]<array[child])
		{
			swap(array[parent],array[child]);
			parent = child;
			child = 2*parent+1;
		}
		else
			break;
	}
}
void Heap_sort(int *array,int n)
{
	//建大堆
	for(int i=(n-2)/2;i>=0;--i)
	{
		Adjustdown(array,i,n);
	}
	//调整
	int end=n-1;
	while(end>0)
	{
		swap(array[0],array[end]);
		Adjustdown(array,0,end);
		--end;
	}
}































