//
// Created by yxr on 2018/8/12.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        queue<TreeNode*> s1,s2;
        TreeNode* p;TreeNode* q;
        s1.push(root->left);
        s2.push(root->right);
        while(!s1.empty() || !s2.empty()){
            p=s1.front();
            s1.pop();
            q=s2.front();
            s2.pop();
            if(p==NULL && q!=NULL)return false;
            if(q==NULL && p!=NULL)return false;
            if(q==NULL && p==NULL)continue;
            if(p->val!=q->val)return false;
            s1.push(p->left);
            s1.push(p->right);
            s2.push(q->right);
            s2.push(q->left);

        }
        return true;
    }
};
