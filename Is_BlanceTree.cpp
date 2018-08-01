#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include"Tree.h"


//判断一棵二叉树是否是平衡二叉树

//思路：计算左右子树的高度差是否超过1，并且左右子树也同时满足平衡---递归
int Depth(treeNode* root)//计算高度
{
  int dp = 0;
  if(root == NULL)
  {
    return dp;
  }
  int left = Depth(root->_left);
  int right = Depth(root->_right);

  return left > right ? left+1 : right+1;

}
bool Is_balance(treeNode* root)
{
  
  if(root == NULL)
  {
    return false;
  }
  int left_dp = 0, right_dp = 0;
  left_dp = Depth(root->_left);
  right_dp = Depth(root->_right);
  int dv = left_dp - right_dp;
  if(dv < -1 || dv > 1)
    return false;
  return Is_balance(root->_left) && Is_balance(root->_right); 
}

//***优化版本****
//上述算法的时间复杂度是O(m*n);
//繁杂之处在于多次的计算了子树高度--
//--通过叶子节点开始判断，将高度放在参数列表中，通过递归将其返回给上一层

bool Is_balance_II(treeNode* root, int dp)
{
  if(root == NULL)
  {
    dp = 0;
    return true;
  }
  int left = 0;
  if(Is_balance_II(root->_left, left) == false)
    return false;
  int right = 0;
  if(Is_balance_II(root->_right, right) == false)
    return false;

  int dv = left - right;
  return abs(dv < 2);

}
int main()
{

  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Tree tree(a,sizeof(a)/sizeof(a[0]));
  treeNode* root = tree.root;
  std::cout<<Is_balance_II(root,0)<<std::endl;
  //std::cout<<root->_data<<std::endl;
  return 0;
}

