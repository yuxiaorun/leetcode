//
// Created by yxr on 2018/8/12.
//
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str1,str2;
        for(int i = 1;i<= s.size()/2;i++)
        {
            str1 = s.substr(0, i);
            int j;
            for(j = i;i < s.size();)
            {
                str2 = s.substr(j, str1.size());
                if(str2 == str1)
                    j += str1.size();
                else
                    break;
            }
            if(j >= s.size())
                return true;
        }
        return false;
    }
};
