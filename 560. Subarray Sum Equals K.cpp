//
// Created by yxr on 2018/7/13.
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        vector<int> f(nums.size()+1, 0);
        for(int i=1;i<=nums.size();i++){
            f[i]=f[i-1];

            int j=i-1;
            int sum=nums[j];
            if(sum==k)f[i]++;
            j--;
            while(j>=0){
                sum+=nums[j];
                if(sum==k)f[i]++;
                j--;
            }
        }
        return f[nums.size()];
    }
};
