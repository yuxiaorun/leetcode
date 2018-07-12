//
// Created by yxr on 2018/7/12.
//
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, false));
        vector<pair<int, int>> path;
        dfs(n*n, n, 0, 0, path, board);
        return result;
    }
private:
    vector<vector<string>>result;
    void dfs(int step, int left, int x, int y, vector<pair<int, int>> path, vector<vector<char>>& board){
        int n=board.size();
        if(step==0 && left!=0)
            return;
        if(left==0){
            vector<string> r;
            for(int i=0;i<n;i++){
                string s(n, '.');
                for(int j=0; j<n; j++){
                    if(board[i][j]=='Q')
                        s[j]='Q';
                }
                r.push_back(s);
            }
            result.push_back(r);
            return;
        }

        if(is_valid(x, y, path)){
            board[x][y]='Q';
            int remain=(y+1)/n;
            path.push_back(make_pair(x,y));
            dfs(step-1, left-1, x+remain, (y+1)%n, path, board);
            path.pop_back();
        }
        board[x][y]='.';
        int remain=(y+1)/n;
        dfs(step-1, left, x+remain, (y+1)%n, path, board);
    }
    bool is_valid(int x,int y, vector<pair<int, int>> path){
        for(int i=0; i<path.size(); i++){
            if(x==path[i].first)return false;
            if(y==path[i].second)return false;
            if(abs(x-path[i].first)==abs(y-path[i].second))return false;
        }
        return true;

    }
};
