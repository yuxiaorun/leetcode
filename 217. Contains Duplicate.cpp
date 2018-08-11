//
// Created by yxr on 2018/8/11.
//
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 1)
            return false;
        unordered_set<int> st;
        st.insert(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if(st.find(nums[i]) != st.end())
                return true;
            else
                st.insert(nums[i]);
        }
        return false;
    }
};
