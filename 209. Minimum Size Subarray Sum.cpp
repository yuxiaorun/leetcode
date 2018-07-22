//
// Created by yxr on 2018/7/22.
//
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result=INT_MAX;
        int sum=0;
        int c=0;
        int start=0;
        int i=0;
        while(i<nums.size()){
            sum+=nums[i];
            c++;
            i++;
            while(sum>=s){
                result=min(result, c);
                sum-=nums[start];
                start++;
                c--;
            }
        }
        if(result==INT_MAX)return 0;
        return result;

    }
};
