class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt[3] = {0, 0, 0};
        int l = 0;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += (n - r);          // all endings from r..n-1 work
                cnt[s[l] - 'a']--;
                l++;
            }
        }
        return (int)ans;
    }
};
