class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;

        int n = grid.size();
        unordered_map<int, pair<int, int>> pos;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                pos[grid[r][c]] = {r, c};
            }
        }

        int totalCells = n * n;
        for (int i = 0; i < totalCells - 1; ++i) {
            auto [r1, c1] = pos[i];
            auto [r2, c2] = pos[i + 1];

            int dr = abs(r1 - r2);
            int dc = abs(c1 - c2);

            if (dr * dc != 2) {
                return false;
            }
        }

        return true;
    }
};