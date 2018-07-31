#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

vector<int> res;//存放最k 个数

void adjustdown(vector<int>&a, int root, int  k)
{
  int parent = root;
  int child = 2*parent+1;
  while(child < k)
  {
    //找出孩子中最大的
    if(child+1 < k && a[child+1] > a[child])
      child += 1;

    if(a[parent] < a[child])
    {
      swap(a[parent], a[child]);
      parent = child;
      child = 2*parent+1;
    }
    else 
      break;
  }
}

void topk(vector<int>& a, int k)
{
  for(int i = (k-2)/2; i>=0; --i)
  {
    adjustdown(a, i, k);
  }

  int end = k-1;
  while(end)
  {
    swap(a[0], a[end]);
    adjustdown(a, 0, end);
    --end;
  }
}

int main()
{
  int k = 1;
  res.resize(k);
  int a[10] = {10, 5, 7, 3, 2, 1, 4, 6, 8,9};
  for(int i = 0; i <k; ++i)
    res[i] = a[i];

  topk(res,k);
 for(int i = k; i < 10; ++i)
 {
   if(a[i] < res[k-1])
   {
     res[k-1] = a[i];
     topk(res, k);  //每当有新的数换到res是，调用堆排序，重新让K个数有序
   }
 } 
  for(int i = 0; i<k; ++i)
    cout<<res[i]<<" ";
  return 0;
}
