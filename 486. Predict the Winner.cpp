//
// Created by yxr on 2018/7/27.
//

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        return !dfs(0,0,true,left,right,nums);
    }
private:
    // return true if A can not win.
    bool dfs(int score_a, int score_b, bool is_a, int left, int right, vector<int>& nums){
        if(left >= right){
            if(is_a)score_a+=nums[left];
            else score_b+=nums[right];
            if(score_a<score_b)return true;
            return false;
        }

        bool result=false;
        if(is_a){
            // return true if A will lose in both two choices.
            return dfs(score_a+ nums[right], score_b, false, left, right-1, nums) && dfs(score_a + nums[left], score_b, false, left+1, right, nums);
        }else{
            //return true if B can win in choose left or choose right.
            result=result || dfs(score_a, score_b+nums[left], true, left+1, right, nums);
            if(result)return true;
            //choose right.
            result=result || dfs(score_a, score_b+nums[right], true, left, right-1, nums);
            return result;
        }
    }
};
