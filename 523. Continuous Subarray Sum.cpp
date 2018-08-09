//
// Created by yxr on 2018/8/9.
//

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> s(nums.size()+1, 0);

        for(int i=0;i<nums.size();i++){
            s[i+1]=s[i]+nums[i];
        }
        // if(s[nums.size()+1]<k)return false;
        for(int i=0; i<nums.size();i++){
            for(int j=i+2;j<=nums.size();j++){
                int t=s[j]-s[i];

                if(t==0)return true;
                if(k!=0 && t>=k && t%k==0)return true;
            }
        }
        return false;
    }
};