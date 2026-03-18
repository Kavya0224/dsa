class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0 ) continue;
                if(i==0) grid[i][j]+=grid[i][j-1];
                else if (j==0) grid[i][j]+=grid[i-1][j];
                else grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
        int ct=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<=k) ct++;
            }
        }
        return ct;
    }
};