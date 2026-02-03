class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        // If touches boundary → not closed
        if (i == 0 || j == 0 || i == n-1 || j == m-1)
            return false;

        vis[i][j] = true;
        bool closed = true;

        if (grid[i+1][j] == 0 && !vis[i+1][j])
            closed &= dfs(i+1, j, grid, vis);

        if (grid[i-1][j] == 0 && !vis[i-1][j])
            closed &= dfs(i-1, j, grid, vis);

        if (grid[i][j+1] == 0 && !vis[i][j+1])
            closed &= dfs(i, j+1, grid, vis);

        if (grid[i][j-1] == 0 && !vis[i][j-1])
            closed &= dfs(i, j-1, grid, vis);

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ct = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {   // FIXED
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (dfs(i, j, grid, vis))
                        ct++;
                }
            }
        }
        return ct;
    }
};
