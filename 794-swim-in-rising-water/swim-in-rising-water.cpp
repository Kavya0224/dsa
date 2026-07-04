#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int t, int n, vector<vector<int>>& grid) {
        if (grid[0][0] > t) return false;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < n &&
                    !vis[nx][ny] &&
                    grid[nx][ny] <= t) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int st = max(grid[0][0], grid[n - 1][n - 1]);
        int end = n * n - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (helper(mid, n, grid))
                end = mid;
            else
                st = mid + 1;
        }

        return st;
    }
};