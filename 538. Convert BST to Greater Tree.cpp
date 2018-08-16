//
// Created by yxr on 2018/8/16.
//
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)return root;
        postorder(root);
        return root;
    }
private:
    void postorder(TreeNode* root){
        if(root->right!=NULL){
            postorder(root->right);
            root->val+=get_most_left(root->right)->val;
        }
        if(root->left!=NULL){
            postorder(root->left);
            add_val(root->left, root->val);
        }

    }
    TreeNode* get_most_left(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    void add_val(TreeNode* root, int val){
        if(root==NULL){
            return;
        }
        root->val+=val;
        add_val(root->left, val);
        add_val(root->right, val);
    }
};
