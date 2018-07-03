//
// Created by yxr on 2018/7/3.
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(0,nums,S);
        return result;
    }
private:
    int result;
    void dfs(int i,vector<int>& nums,int S){
        if(i==nums.size()){
            if(S==0)
                result++;
            return;
        }
        dfs(i+1,nums,S-nums[i]);
        dfs(i+1,nums,S+nums[i]);
        return;
    }
};
