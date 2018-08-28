//求数组中逆序对的个数
//时间复杂度为O(nlgn)解法：例如数组1 2 3 4 5 6 7 0
//将数组分成左右两部分：1 2 3 4 和5 6 7 0;逆序对个数=左部分逆序对+右部分逆序对+左，右两部分中构成的逆序对个数
//递归，利用归并排序的思想，
//
#include <stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int meger_count(vector<int>&a,int left,int mid,int right)
{
  vector<int> tmp(a);
  int count = 0;
  int i = left;
  int j = mid+1;
  int index = left;
  while(i<=mid&&j<=right)
  {
    if(a[i]>a[j])
    {
      tmp[index++] = a[j++];
      count+=mid-i+1;
    }
    else 
      tmp[index++] = a[i++];
  }
  while(i<=mid)
    tmp[index++]=a[i++];
  while(j<=right)
    tmp[index++] = a[j++];
  for(int k = left; k<=right;++k)
    a[k] = tmp[k];
  return count;
}

int meger(vector<int>& a,int left,int right)
{
  if(left >= right)
    return 0;
  int mid = (left+right)>>1;
  int left_count = meger(a,left,mid);
  int right_count = meger(a,mid+1,right);
  int count = meger_count(a,left,mid,right);
  return left_count+right_count+count;
}

int count(vector<int> a,int n)
{
  return meger(a,0,n-1);
}

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(0);
  cout<<count(v,8)<<endl;
  return 0;

}
