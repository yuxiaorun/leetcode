//
// Created by yxr on 2018/7/13.
//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(record.find(target-nums[i])!=record.end()){
                result.push_back(record[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            record[nums[i]] = i;  //注意为什么要放在后面
        }
        return result;
    }
};
