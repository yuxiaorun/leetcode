//
// Created by yxr on 2018/7/22.
//
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3)return false;
        int index=0;
        int m=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>=nums[i+1]){
                int one=find_min(0, i, nums);
                cout<<"one:"<<one;
                cout<<"three:"<<nums[i];
                int two=find_max(i+1, nums.size(), nums[i], nums);
                cout<<"two:"<<two<<endl;
                if(one<two)return true;

            }
        }
        return false;
    }
private:
    int find_max(int left, int right,int three , vector<int>& nums){
        int r=INT_MIN;
        for(int i=left;i<right;i++){
            if(nums[i]>r && nums[i]<three)r=nums[i];
        }
        return r;
    }
    int find_min(int left, int right, vector<int>& nums){
        int r=INT_MAX;
        for(int i=left;i<right;i++){
            if(nums[i]<r)r=nums[i];
        }
        return r;
    }
};
