//
// Created by yxr on 2018/8/13.
//
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long n = nums.size();
        return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
    }
};
