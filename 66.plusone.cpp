//
// Created by yxr on 2018/7/6.
//

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add=1;
        for(auto i=digits.end()-1;i>=digits.begin();i--){
            *i+=add;
            add=0;
            if(*i==10){
                *i=0;
                add=1;
            }

        }
        if(add==1){
            digits[0]=0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};