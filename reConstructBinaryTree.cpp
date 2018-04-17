*****************重构二叉树*********************
//根据二叉树的先序序列和中序序列构造二叉树
//例如：先序：1 2 4 7 3 5 6 8
        中序：4 7 2 1 5 3 8 6
思想：先序的第一个节点总是二叉树根节点的值；
      但是在中序序列中根节点的值位于中间，左边都是左子树节点的中序，右边都是右子树节点的中序
	  因此:我们需要扫描中序序列，找到根节点。
	  例如:先序里1是根节点，下标是0；那么1在中序实在下标为3的位置，记为index=3；
	        所以4 7 2就是根节点1的左子树的中序遍历；5 3 8 6是右子树的中序遍历；
			然后在先序中，从下标1到下标index区间中，2 4 7就是根节点1左子树的先序，3 5 6 8是右子树的先序
	  ...
	  既然我们找到了左右子树的先序和中序序列，我们就可以用同样的方法分别构建左右子树；
	  也就是说接下来的事情可以用递归完成
	  
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = vin.size();
        if(len<=0)
            return NULL;
        Node* root = new Node(pre[0]);
        vector<int> left_pre,left_in,right_pre,right_in;
        int index = 0;
        for(int i = 0;i<len;++i)
        {
            if(vin[i]==pre[0])
            {
                index = i;
                break;
            }
        }
        for(int i=1;i<=index;++i)
        {
            left_pre.push_back(pre[i]);
            left_in.push_back(vin[i-1]);
        }
        for(int i = index+1;i<len;++i)
        {
            right_pre.push_back(pre[i]);
            right_in.push_back(vin[i]);
        }
        
        root->left = reConstructBinaryTree(left_pre,left_in);
        root->right = reConstructBinaryTree(right_pre,right_in);
        return root;
    }