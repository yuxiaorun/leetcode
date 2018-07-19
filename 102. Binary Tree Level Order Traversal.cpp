//
// Created by yxr on 2018/7/20.
//
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> st1;
        queue<TreeNode*> st2;
        vector<vector<int>> result;
        if(root==NULL)return result;
        TreeNode* p=root;

        st1.push(root);
        while(!st1.empty() || !st2.empty()){
            vector<int> cur_level;
            while(!st1.empty()){
                p=st1.front();
                st1.pop();
                cur_level.push_back(p->val);
                if(p->left!=NULL)st2.push(p->left);
                if(p->right!=NULL)st2.push(p->right);
            }
            if(!cur_level.empty())result.push_back(cur_level);
            vector<int> next_level;
            while(!st2.empty()){
                p=st2.front();
                st2.pop();
                next_level.push_back(p->val);
                if(p->left!=NULL)st1.push(p->left);
                if(p->right!=NULL)st1.push(p->right);
            }

            if(!next_level.empty())result.push_back(next_level);
        }
        return result;
    }

};
