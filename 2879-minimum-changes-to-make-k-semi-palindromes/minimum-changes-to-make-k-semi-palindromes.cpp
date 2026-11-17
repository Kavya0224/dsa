class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // divisors[len] will store all proper divisors of len
        vector<vector<int>> divisors(n + 1);
        for (int len = 1; len <= n; ++len) {
            for (int d = 1; d * d <= len; ++d) {
                if (len % d == 0) {
                    if (d < len) divisors[len].push_back(d);
                    int d2 = len / d;
                    if (d2 != d && d2 < len) divisors[len].push_back(d2);
                }
            }
        }

        // cost[i][j] = min changes to make s[i...j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = 1e9;

                for (int d : divisors[len]) {
                    int current_changes = 0;
                    // Check each group of step d directly in-place
                    for (int start = 0; start < d; ++start) {
                        int l = i + start;
                        // Find the last element in this group
                        int r = i + start + (len - d) - ((start + len - d) % d); // simpler: jump backwards from j
                        // Alternatively, find exact indices:
                        // Leftmost and rightmost pointers for this group:
                        int left_idx = i + start;
                        int right_idx = j - ((j - (i + start)) % d);
                        
                        while (left_idx < right_idx) {
                            if (s[left_idx] != s[right_idx]) {
                                current_changes++;
                            }
                            left_idx += d;
                            right_idx -= d;
                        }
                    }
                    min_changes = min(min_changes, current_changes);
                }
                cost[i][j] = min_changes;
            }
        }

        // dp[i][p] = min changes to partition prefix s[0...i] into p parts
        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));
        
        for (int i = 0; i < n; ++i) {
            dp[i][1] = cost[0][i];
        }

        for (int p = 2; p <= k; ++p) {
            for (int i = 0; i < n; ++i) {
                for (int j = p - 2; j < i; ++j) {
                    if (dp[j][p - 1] != 1e9 && cost[j + 1][i] != 1e9) {
                        dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j + 1][i]);
                    }
                }
            }
        }

        return dp[n - 1][k];
    }
};