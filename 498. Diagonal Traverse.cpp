//
// Created by yxr on 2018/8/9.
//
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0)return result;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i<m+n-1;i++){
            int x=0;
            int y=0;
            vector<int> one_turn;
            if(i<n){
                y=i;
            }else{
                x=i-n+1;
                y=n-1;
            }
            while(x>=0 && x<m && y>=0 && y<n){
                one_turn.push_back(matrix[x][y]);
                x+=1;
                y-=1;
            }
            if(i%2 == 0)reverse(one_turn.begin(), one_turn.end());
            for(int j=0; j < one_turn.size(); j++)result.push_back(one_turn[j]);
        }
        return result;
    }
};
