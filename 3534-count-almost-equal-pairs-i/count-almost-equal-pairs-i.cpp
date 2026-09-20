class Solution {
private:
    bool isAlmostEqual(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);

        while (s1.length() < s2.length()) s1 = "0" + s1;
        while (s2.length() < s1.length()) s2 = "0" + s2;

        vector<int> diff;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        if (diff.empty()) return true;

        if (diff.size() == 2) {
            return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
        }

        return false;
    }

public:
    int countPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAlmostEqual(nums[i], nums[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};