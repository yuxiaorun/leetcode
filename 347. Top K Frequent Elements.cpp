//
// Created by yxr on 2018/7/4.
//

class Solution {
public:
    static bool cmp_by_value(pair<int, int> & lhs, pair<int, int> & rhs) {
        return lhs.second > rhs.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> record;
        for(int i=0;i<nums.size();i++){
            record[nums[i]]+=1;
        }
        vector<int> result;
        vector<pair<int, int>> sort_pairs(record.begin(), record.end());
        sort(sort_pairs.begin(), sort_pairs.end(), this->cmp_by_value);
        for(int i=0;i<k;i++){
            result.push_back(sort_pairs[i].first);
        }
        return result;
    }
};
