//
// Created by yxr on 2018/8/9.
//
TreeNode* buildTreeFun(vector<int>& inorder, vector<int>& postorder, int left_in, int right_in, int left_post, int right_post)
{
    if(left_post >= right_post)
        return NULL;
    int dis=0;
    while(inorder[left_in+dis] != postorder[right_post-1])
    {
        dis++;
    }
    TreeNode *root = new TreeNode(postorder[right_post-1]);
    root->left = buildTreeFun(inorder, postorder, left_in, left_in+dis, left_post, left_post+dis);
    root->right = buildTreeFun(inorder, postorder, left_in+dis+1, right_in, left_post+dis, right_post-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0 || postorder.size() == 0)
        return NULL;

    return buildTreeFun(inorder, postorder, 0, inorder.size(), 0, postorder.size());
}
