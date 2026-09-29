#include <vector>

class Solution {
    int m, n;
    bool visited[100][100][105];

    bool dfs(const std::vector<std::vector<char>>& grid, int i, int j, int bal) {
        if (grid[i][j] == '(') bal++;
        else bal--;

        if (bal < 0) return false;
        if (bal > (m - i) + (n - j) - 1) return false;

        if (i == m - 1 && j == n - 1) return bal == 0;

        if (visited[i][j][bal]) return false;
        visited[i][j][bal] = true;

        if (j + 1 < n && dfs(grid, i, j + 1, bal)) return true;
        if (i + 1 < m && dfs(grid, i + 1, j, bal)) return true;

        return false;
    }

public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;

        return dfs(grid, 0, 0, 0);
    }
};