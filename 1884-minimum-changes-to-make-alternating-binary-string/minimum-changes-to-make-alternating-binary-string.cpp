class Solution {
public:
    int minOperations(string s) {
        int n = (int)s.size();
        int mism01 = 0; // mismatches vs pattern 0101...
        int mism10 = 0; // mismatches vs pattern 1010...

        for (int i = 0; i < n; i++) {
            char expect01 = (i % 2 == 0) ? '0' : '1';
            char expect10 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expect01) mism01++;
            if (s[i] != expect10) mism10++;
        }
        return min(mism01, mism10);
    }
};