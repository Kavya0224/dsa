class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> preSum(n + 1, 0);
        string t = "";
        vector<int> pos(n + 1, 0);

        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + (s[i] - '0');
            pos[i] = t.size();
            if (s[i] != '0')
                t.push_back(s[i]);
        }
        pos[n] = t.size();

        int m = t.size();
        vector<long long> pref(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++) pow10[i] = (pow10[i - 1] * 10) % MOD;
        for (int i = 0; i < m; i++) pref[i + 1] = (pref[i] * 10 + (t[i] - '0')) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = preSum[r + 1] - preSum[l];

            int L = pos[l];
            int R = pos[r + 1] - 1;

            long long num = 0;

            if (L <= R) {
                int len = R - L + 1;
                num = (pref[R + 1] -
                       pref[L] * pow10[len] % MOD +
                       MOD) % MOD;
            }

            ans.push_back(sum * num % MOD);
        }

        return ans;
    }
};