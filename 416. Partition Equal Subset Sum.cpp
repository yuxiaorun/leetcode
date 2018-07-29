//
// Created by yxr on 2018/7/29.
//
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        if(nums[nums.size()-1]>sum/2)return false;
        return dfs(sum/2,nums.size()-1,nums);
    }
private:
    bool dfs(int target, int step, vector<int>& nums){
        if(target==0)return true;
        if(target<0) return false;
        if(step<0)return false;
        return dfs(target-nums[step], step-1, nums) || dfs(target, step-1, nums);
    }
};
