//
// Created by yxr on 2018/7/26.
//

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balancedHeight(root)>=0;
    }
private:
    int balancedHeight(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 1;
        int left_h=balancedHeight(root->left);
        int right_h=balancedHeight(root->right);
        if(abs(left_h-right_h)>1 )return -999;
        return max(left_h, right_h)+1;
    }

};