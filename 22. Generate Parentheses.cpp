//
// Created by yxr on 2018/7/4.
//
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string path="";
        dfs(path, n, n);
        return result;
    }
private:
    vector<string> result;
    void dfs(string path, int left,int right){
        if(right<left)return;
        if(left<0)return;
        if(right==0 && left==0){
            result.push_back(path);
            return;
        }

        dfs(path+'(', left-1, right);
        dfs(path+')', left, right-1);
    }
};