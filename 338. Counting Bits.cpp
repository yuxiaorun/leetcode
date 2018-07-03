//
// Created by yxr on 2018/7/3.
//
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> record(num+1,0);
        if(num==0)return record;
        record[1]=1;
        for(int i=2;i<num+1;i++){
            if(i%2==0)record[i]=record[i/2];
            else record[i]=record[i/2]+1;
        }
        return record;
    }
};