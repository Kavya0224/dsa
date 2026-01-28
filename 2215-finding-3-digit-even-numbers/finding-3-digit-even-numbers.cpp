class Solution {
public:
    unordered_set<int> s;

    void helper(vector<int>& nums, vector<bool>& used, int count, int temp) {
        // when exactly 3 digits formed
        if (count == 3) {
            if (temp % 2 == 0)        // must be even
                s.insert(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) continue;

            // leading zero not allowed
            if (count == 0 && nums[i] == 0) continue;

            used[i] = true;
            helper(nums, used, count + 1, temp * 10 + nums[i]);
            used[i] = false;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);
        helper(digits, used, 0, 0);

        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
