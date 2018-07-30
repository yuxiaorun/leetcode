//
// Created by yxr on 2018/7/30.
//
class Solution {
public:
    map<int, int> r;
    int climbStairs(int n) {
        if(n==1 or n==0 )return 1;
        if(r.find(n) != r.end())return r[n];
        else r[n]= climbStairs(n-1)+climbStairs(n-2);
        return r[n];
    }
};
