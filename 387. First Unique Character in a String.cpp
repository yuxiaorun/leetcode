//
// Created by yxr on 2018/7/18.
//
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size()==0)return -1;
        map<char,int> m;
        for(int i=0;i<s.size(); i++){
            m[s[i]]+=1;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==1)return i;
        }

        return -1;

    }
};
