//
// Created by yxr on 2018/7/15.
//
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum=0;
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j]==1)sum+=perimeter(i,j,grid);
        return sum;
    }
private:
    int m;
    int n;
    int perimeter(int x, int y, vector<vector<int>>& grid){
        int s=4;
        if(x+1<m && grid[x+1][y]==1)s--;
        if(x-1>=0 && grid[x-1][y]==1)s--;
        if(y-1>=0 && grid[x][y-1]==1)s--;
        if(y+1<n && grid[x][y+1]==1)s--;
        return s;
    }
};
