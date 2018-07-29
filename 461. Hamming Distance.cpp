//
// Created by yxr on 2018/7/29.
//
class Solution {
public:
    int hammingDistance(int x, int y) {
        int i=0;
        int result=0;
        int d=x^y;
        while(i<32){
            if(d&1)
                result+=1;
            d=d>>1;
            i++;
        }
        return result;
    }
};
