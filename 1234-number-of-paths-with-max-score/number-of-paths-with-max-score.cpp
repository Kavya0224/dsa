class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        dp[0][0] = {0, 1};
        for (int j = 1; j < n; j++) {
            if (board[0][j] == 'X' || dp[0][j - 1].second == 0) break;
            dp[0][j].first = dp[0][j - 1].first + (board[0][j] == 'S' ? 0 : board[0][j] - '0');
            dp[0][j].second = 1;
        }
        for (int i = 1; i < n; i++) {
            if (board[i][0] == 'X' || dp[i - 1][0].second == 0) break;
            dp[i][0].first = dp[i - 1][0].first + (board[i][0] == 'S' ? 0 : board[i][0] - '0');
            dp[i][0].second = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (board[i][j] == 'X') continue;
                
                int max_score = -1;
                long long paths = 0;
                vector<pair<int, int>> directions = { {i-1, j-1}, {i-1, j}, {i, j-1} };
                
                for (auto& dir : directions) {
                    int prev_i = dir.first;
                    int prev_j = dir.second;
                    
                    if (dp[prev_i][prev_j].second > 0) {
                        if (dp[prev_i][prev_j].first > max_score) {
                            max_score = dp[prev_i][prev_j].first;
                            paths = dp[prev_i][prev_j].second;
                        } else if (dp[prev_i][prev_j].first == max_score) {
                            paths = (paths + dp[prev_i][prev_j].second) % MOD;
                        }
                    }
                }
                if (max_score != -1) {
                    int current_val = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');
                    dp[i][j].first = max_score + current_val;
                    dp[i][j].second = paths;
                }
            }
        }
                if (dp[n - 1][n - 1].second == 0) {
            return {0, 0};
        }
        
        return {dp[n - 1][n - 1].first, dp[n - 1][n - 1].second};
    }
};