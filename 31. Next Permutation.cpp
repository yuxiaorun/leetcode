//
// Created by yxr on 2018/7/11.
//
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool lowest=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])lowest=false;
        }
        if(lowest){
            sort(nums.begin(), nums.end());
            return;
        }
        int i=nums.size()-1;
        while(i>0 && nums[i]<=nums[i-1]){
            i--;
        }
        i--;
        cout<<i<<endl;
        int index=0;
        int min=INT_MAX;
        for(int k=nums.size()-1;k>i;k--)
            if(nums[k]>nums[i] && min>nums[k]){
                index=k;
                min=nums[k];
            }
        cout<<index<<endl;
        int t=nums[i];
        nums[i]=nums[index];
        nums[index]=t;
        sort(nums.begin()+i+1,nums.end());
        return;

    }
};
