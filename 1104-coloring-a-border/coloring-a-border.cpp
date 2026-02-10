class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int original = grid[row][col];

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int,int>> borders;

        q.push({row, col});
        vis[row][col] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            bool isBorder = false;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    isBorder = true;
                }
                else if (grid[nx][ny] != original) {
                    isBorder = true;
                }
                else if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            if (isBorder) {
                borders.push_back({x, y});
            }
        }

        // Color only the border cells
        for (auto &p : borders) {
            grid[p.first][p.second] = color;
        }

        return grid;
    }
};
