//
// Created by yxr on 2018/7/10.
//
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    if(i-1>=0 && board[i-1][j]=='X')continue;
                    if(j-1>=0 && board[i][j-1]=='X')continue;
                    sum++;
                }
            }
        }

        return sum;
    }
};
