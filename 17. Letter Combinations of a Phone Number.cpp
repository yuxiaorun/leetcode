//
// Created by yxr on 2018/7/30.
//
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return result;
        helper(0,digits.size(),digits,"");
        return result;
    }
private:
    vector<string> keyboard { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> result;
    void helper(int i,int n, string digits, string cur){
        if(i==n){
            result.push_back(cur);

        }
        string c=keyboard[digits[i]-'0'];
        for(int k=0;k<c.size();k++){
            helper(i+1,n,digits,cur+c[k]);
        }

    }
};
