class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        const int NEG = -1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, NEG)));

        // starting cell
        for (int k = 0; k < 3; k++) dp[0][0][k] = NEG;
        
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // neutralize starting negative
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; k++) {
                    int bestPrev = NEG;

                    if (i > 0) bestPrev = max(bestPrev, dp[i - 1][j][k]);
                    if (j > 0) bestPrev = max(bestPrev, dp[i][j - 1][k]);

                    if (bestPrev != NEG) {
                        dp[i][j][k] = max(dp[i][j][k], bestPrev + coins[i][j]);
                    }

                    // If current cell is negative, we may neutralize it
                    if (coins[i][j] < 0 && k > 0) {
                        int bestPrevNeutral = NEG;
                        if (i > 0) bestPrevNeutral = max(bestPrevNeutral, dp[i - 1][j][k - 1]);
                        if (j > 0) bestPrevNeutral = max(bestPrevNeutral, dp[i][j - 1][k - 1]);

                        if (bestPrevNeutral != NEG) {
                            dp[i][j][k] = max(dp[i][j][k], bestPrevNeutral);
                        }
                    }
                }
            }
        }

        return max({dp[n - 1][m - 1][0], dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]});
    }
};