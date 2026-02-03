class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

       

        vis[i][j] = true;
        int closed = 1;

        if (i+1<n && grid[i+1][j] == 1 && !vis[i+1][j])
            closed += dfs(i+1, j, grid, vis);

        if (i-1>=0&&grid[i-1][j] == 1 && !vis[i-1][j])
            closed += dfs(i-1, j, grid, vis);

        if (j+1<m && grid[i][j+1] == 1 && !vis[i][j+1])
            closed += dfs(i, j+1, grid, vis);

        if (j-1>=0 && grid[i][j-1] == 1 && !vis[i][j-1])
            closed += dfs(i, j-1, grid, vis);

        return closed;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {   // FIXED
                if (grid[i][j] == 1 && !vis[i][j]) {
                    mx=max(mx,dfs(i, j, grid, vis));
                }
            }
        }
        return mx;
    }
};