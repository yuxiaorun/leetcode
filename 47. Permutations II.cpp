//
// Created by yxr on 2018/7/7.
//
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> r;
        sort(nums.begin(), nums.end());
        helper(nums, r);
        return re;
    }
private:
    vector<vector<int>> re;
    void helper(vector<int>& nums, vector<int>& r){
        vector<int> result(r);
        if(nums.size()==0){
            re.push_back(result);
            return;
        }
        int preNum;
        int s=nums.size();
        for(int i=0;i<s;i++){
            int in=nums[i];
            if(in == preNum)continue;
            preNum=in;
            result.push_back(in);

            nums.erase(nums.begin()+i);
            helper(nums, result);
            nums.insert(nums.begin()+i, in);
            result.erase(result.end()-1);
        }
    }

};
