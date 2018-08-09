//
// Created by yxr on 2018/8/9.
//
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildRoot(preorder, inorder);
    }
private:
    TreeNode* buildRoot(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size()==0 || inorder.size()==0)return NULL;
        if(preorder.size()==1 && inorder.size()==1)
            return new TreeNode(preorder[0]);
        else{
            int root=preorder[0];
            int pos;
            for(int i=0;i<inorder.size(); i++){
                if(inorder[i]==root){
                    pos=i;
                    break;
                }
            }
            cout<<pos<<endl;
            vector<int> a(inorder.begin(), inorder.begin()+pos);
            vector<int> b(inorder.begin()+pos+1, inorder.end());
            vector<int> c(preorder.begin()+1, preorder.begin()+1+pos);
            vector<int> d(preorder.begin()+pos+1, preorder.end());

            TreeNode* r=new TreeNode(root);
            r->left=buildRoot(c, a);
            r->right=buildRoot(d, b);
            return r;
        }

    }
};
