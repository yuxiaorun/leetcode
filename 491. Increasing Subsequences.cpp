//
// Created by yxr on 2018/8/15.
//
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        dfs(0, nums,path);
        return result;
    }
private:
    vector<vector<int>> result;
    void dfs(int step, vector<int>& nums, vector<int>& path){
        if(path.size()>=2){
            vector<int> r(path);
            result.push_back(r);
        }

        unordered_set<int> hash;
        for(int i=step;i<nums.size();i++){
            if((path.empty() || nums[i] >= path.back()) && hash.find(nums[i]) == hash.end()){
                path.push_back(nums[i]);
                dfs(i+1, nums,path);
                path.pop_back();
                hash.insert(nums[i]);
            }

        }


    }
};
