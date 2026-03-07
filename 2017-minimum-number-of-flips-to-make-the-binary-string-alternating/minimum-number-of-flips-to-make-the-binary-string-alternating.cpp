class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int alt1 = 0, alt2 = 0;
        int ans = INT_MAX;

        for (int i = 0; i < 2 * n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1'; // 0101...
            char expected2 = (i % 2 == 0) ? '1' : '0'; // 1010...

            if (t[i] != expected1) alt1++;
            if (t[i] != expected2) alt2++;

            if (i >= n) {
                char leftExpected1 = ((i - n) % 2 == 0) ? '0' : '1';
                char leftExpected2 = ((i - n) % 2 == 0) ? '1' : '0';

                if (t[i - n] != leftExpected1) alt1--;
                if (t[i - n] != leftExpected2) alt2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(alt1, alt2));
            }
        }

        return ans;
    }
};