class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        vector<int> text(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] > nums[i]) {
                text[i] = 1;
            } else if (nums[i + 1] == nums[i]) {
                text[i] = 0;
            } else {
                text[i] = -1;
            }
        }

        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int count = 0;
        for (int i = 0, j = 0; i < n - 1;) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    count++;
                    j = lps[j - 1];
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return count;
    }
};