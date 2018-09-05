#include<stdio.h>
#include<iostream>
using namespace std;
int m,n;
int *p;
int sum;
 
/**让一个值为key的节点和他周围值为key的节点连通
 *key!=set
 */
void link(int key,int sx,int sy,int set)
{
    sum++;
    p[sy*n+sx]=set;
    if(sx-1>=0&&p[sy*n+sx-1]==key) link(key,sx-1,sy,set);
    if(sx+1<n&&p[sy*n+sx+1]==key) link(key,sx+1,sy,set);
    if(sy-1>=0&&p[(sy-1)*n+sx]==key) link(key,sx,sy-1,set);
    if(sy+1<m&&p[(sy+1)*n+sx]==key) link(key,sx,sy+1,set);
}
 
int main()
{
    int i,j;
    cin>>m>>n;
    p=new int[m*n];
    for(i=0;i<m*n;i++)
    {
        cin>>p[i];
    }
/*连通所有海洋且标记为-1*/
    for(i=0;i<n;i++)
    {
        if(p[i]==0) link(0,i,0,-1);
    }
    for(i=0;i<m;i++)
    {
        if(p[i*n]==0) link(0,0,i,-1);
        if(p[i*n+n-1]==0) link(0,n-1,i,-1);
    }
/*其余的都为陆地，将地中海变为陆地*/
    for(i=1;i<m-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(p[i*n+j]==0) p[i*n+j]=1;
        }
    }
    sum=0;
/*计算陆地面积*/
    link(1,0,m-1,2);
    cout<<sum<<endl;
}
