class Solution {
    vector<int> memo;

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    int solve(int i, const string &s, int k) {
        if (i >= s.size()) return 0;
        if (memo[i] != -1) return memo[i];
        int ans = solve(i + 1, s, k);
        if (i + k <= s.size() && isPalindrome(s, i, i + k - 1)) {
            ans = max(ans, 1 + solve(i + k, s, k));
        }
        if (i + k + 1 <= s.size() && isPalindrome(s, i, i + k)) {
            ans = max(ans, 1 + solve(i + k + 1, s, k));
        }

        return memo[i] = ans;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        memo.assign(n, -1);
        return solve(0, s, k);
    }
};