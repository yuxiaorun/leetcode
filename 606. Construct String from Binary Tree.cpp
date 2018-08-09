//
// Created by yxr on 2018/8/9.
//
class Solution {
public:
    string tree2str(TreeNode* t) {

        return preorder(t);
    }
private:
    string preorder(TreeNode* t){
        string r="";
        if(t==NULL)return r;
        r+=to_string(t->val);
        if(t->right!=NULL){
            r+='(';
            r+=preorder(t->left);
            r+=')';
            r+='(';
            r+=preorder(t->right);
            r+=')';
        }else{
            if(t->left==NULL)return r;
            else{
                r+='(';
                r+=preorder(t->left);
                r+=')';
            }
        }

        return r;
    }
};
