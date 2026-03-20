class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> arr;

                // collect elements of current k x k subgrid
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        arr.push_back(grid[i + x][j + y]);
                    }
                }

                sort(arr.begin(), arr.end());

                // remove duplicates
                arr.erase(unique(arr.begin(), arr.end()), arr.end());

                // if fewer than 2 distinct elements, answer is 0
                if (arr.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }

                int mn = INT_MAX;
                for (int p = 0; p + 1 < arr.size(); p++) {
                    mn = min(mn, arr[p + 1] - arr[p]);
                }

                ans[i][j] = mn;
            }
        }

        return ans;
    }
};