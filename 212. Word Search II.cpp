//
// Created by yxr on 2018/7/10.
//
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        vector<vector<bool>> used(m,vector<bool>(n,false));
        map<string, bool> has;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<words.size();k++){
                    if(board[i][j]==words[k][0] && has[words[k]]==false)
                        helper(i,j,0,words[k],board, used,has);
                }
            }

        }
        return result;
    }
private:
    int m;
    int n;
    vector<string> result;
    void helper(int x, int y, int i, string s, vector<vector<char>>& board,vector<vector<bool>>& used, map<string, bool>& has){
        if(board[x][y]!=s[i])return;
        used[x][y]=true;
        if(i+1==s.size() && has[s]==false){
            result.push_back(s);
            has[s]=true;
            used[x][y]=false;
            return;
        }

        if(x-1>=0 && used[x-1][y]==false)helper(x-1,y,i+1,s,board,used, has);
        if(x+1<m && used[x+1][y]==false)helper(x+1,y,i+1,s,board,used,has);
        if(y-1>=0 && used[x][y-1]==false)helper(x,y-1,i+1,s,board,used,has);
        if(y+1<n && used[x][y+1]==false)helper(x,y+1,i+1,s,board,used,has);
        used[x][y]=false;
    }
};
