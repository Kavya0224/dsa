class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, 10001));
        for (int i = 0; i < n; ++i) cost[i][i] = 0;
        for (auto& edge : edges) {
            cost[edge[0]][edge[1]] = edge[2];
            cost[edge[1]][edge[0]] = edge[2];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
                }
            }
        }

        int city = -1, minReachable = n + 1;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (cost[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt <= minReachable) {
                minReachable = cnt;
                city = i;
            }
        }
        return city;
    }
};