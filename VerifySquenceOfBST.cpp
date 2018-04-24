
//输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历结果。如果是返回true;否则返回false;
//例如：输入数组{5，7，6，9，11，10，8}，返回true
bool bst(vector<int> v,int left,int right)
{
    if(v.empty()||left>right)
        return false;
    int root = v[right];
    int i = 0;
    for(;i<right;++i)
    {
        if(v[i]>root)
            break;
    }
    for(int j = i;j<right;++j)
    {
        if(v[j]<root)
            return false;
    }
        
    bool left_tree = true;
    if(i>left)
        left_tree = bst(v,0,i-1);
    bool right_tree = true;
    if(i<right)
        right_tree = bst(v,i,right-1);
    return left_tree&&right_tree;
}

    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence,0,sequence.size()-1);
    }