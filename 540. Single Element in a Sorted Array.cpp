//
// Created by yxr on 2018/8/8.
//
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s^=nums[i];
        }
        return s;
    }
};
