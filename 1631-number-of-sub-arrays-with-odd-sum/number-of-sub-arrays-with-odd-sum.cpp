class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    // Returns count of subarrays ending at index 'i' with given 'parity' (0 = even, 1 = odd)
    int solve(int i, int parity, vector<int>& arr) {
        if (i < 0) return 0;
        
        if (dp[i][parity] != -1) {
            return dp[i][parity];
        }

        int isOdd = arr[i] % 2;
        long long count = 0;

        if (parity == 1) { // Want ODD sum ending at i
            if (isOdd) {
                // Single element [arr[i]] + extending previous EVEN subarrays
                count = 1 + solve(i - 1, 0, arr);
            } else {
                // Extending previous ODD subarrays
                count = solve(i - 1, 1, arr);
            }
        } else { // Want EVEN sum ending at i
            if (isOdd) {
                // Extending previous ODD subarrays
                count = solve(i - 1, 1, arr);
            } else {
                // Single element [arr[i]] + extending previous EVEN subarrays
                count = 1 + solve(i - 1, 0, arr);
            }
        }

        return dp[i][parity] = count % MOD;
    }

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(2, -1));
        long long totalOddSubarrays = 0;
        for (int i = 0; i < n; i++) {
            totalOddSubarrays = (totalOddSubarrays + solve(i, 1, arr)) % MOD;
        }
        
        return totalOddSubarrays;
    }
};