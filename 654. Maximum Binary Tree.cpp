//
// Created by yxr on 2018/7/8.
//
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode result(0);
        result.left=helper(0, nums.size(), nums);
        return &result;
    }
private:
    TreeNode* helper(int left, int right, vector<int>& nums){
        if(left>=right)return NULL;
        int max=INT_MIN;
        int index=left;
        for(int i=left;i<right;i++){
            if(nums[i]>max){
                index=i;
                max=nums[i];
            }
        }
        TreeNode* root=new TreeNode(max);
        root->left=helper(left, index,nums);
        root->right=helper(index+1, right, nums);
        return root;
    }

};
