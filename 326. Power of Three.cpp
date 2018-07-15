//
// Created by yxr on 2018/7/15.
//
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n%3==0 && n>3)n=n/3;
        if(n==3 || n==1)return true;
        return false;
    }
};
