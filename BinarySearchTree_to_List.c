//思路：中序遍历二叉搜索树(从小到大顺序)，
//遇到根节点时，分为三部分:左子树，根节点，右子树；
//把左子树的最大节点和根节点连接；根节点和右子树的最小节点连接。

    typedef TreeNode Node;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        Node* list = NULL;
        ConvertNode(pRootOfTree,list);
        Node* newhead = list;
        while(newhead!=NULL&&newhead->left!=NULL)
            newhead = newhead->left;
        return newhead;
    }
    void ConvertNode(Node* pNode,Node*&list)
    {
        if(pNode==NULL)
            return ;
        Node* cur = pNode;
        if(cur->left!=NULL)
            ConvertNode(cur->left,list);
        cur->left = list;
        if(list!=NULL)
            list->right = cur;
        list = cur;
        if(cur->right!=NULL)
            ConvertNode(cur->right,list);
    }
