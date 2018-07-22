//
// Created by yxr on 2018/7/22.
//
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;    //~(diff-1)
        vector<int> rets={0,0};
        for(int num: nums){
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }

        }
        return rets;
    }
};
