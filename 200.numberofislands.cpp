//
// Created by yxr on 2018/7/6.
//

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cur_num=1;
        if(grid.size()==0)return 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i>=13)
                    if(grid[i][j]-'0' == 0)continue;
                if(grid[i][j]-'0' == 1 ){
                    grid[i][j]='0';
                    cur_num++;
                    mark_around(i,j,grid);
                }
            }
        }
        return cur_num-1;
    }
private: void mark_around(int x, int y, vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(x-1>=0 && grid[x-1][y]-'0'== 1){
            grid[x-1][y]=0;
            mark_around(x-1, y, grid);
        }
        if(x+1<m && grid[x+1][y]-'0'== 1){
            grid[x+1][y]=0;

            mark_around(x+1, y, grid);

        }
        if(y-1>=0 && grid[x][y-1]-'0'== 1){
            grid[x][y-1]=0;
            mark_around(x, y-1, grid);
        }
        if(y+1<n && grid[x][y+1]-'0'== 1){
            grid[x][y+1]=0;
            mark_around(x, y+1, grid);
        }

    }

};